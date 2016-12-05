#include <wx/wx.h>
#include <wx/sizer.h>
#include "SpadesBoard.hpp"
#include <random>
#include <time.h>


SpadesBoard::SpadesBoard(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	//Sizers
	verticalBoxMain = new wxFlexGridSizer(3, 0, 20, 20);
	horizontalBoxBtm = new wxBoxSizer(wxHORIZONTAL);
	horizontalBoxMid = new wxBoxSizer(wxHORIZONTAL);
	horizontalBoxTop = new wxBoxSizer(wxHORIZONTAL);
	verticalBoxLeft = new wxBoxSizer(wxVERTICAL);
	verticalBoxCenter = new wxBoxSizer(wxVERTICAL);
	verticalBoxRight = new wxBoxSizer(wxVERTICAL);

	horizontalBoxCenter = new wxFlexGridSizer(2, 2, 10, 10);

	//Images used to scale the Bitmap
	wxImage pc;
	wxImage pct;
	wxImage pcs;
	wxImage dc;
	wxBitmap defaultColor;
	wxBitmap playerHandTop;
	wxBitmap playerHandSide;

	defaultColor.LoadFile("../../../../CS3450/Resources/cards/blank.jpg", wxBITMAP_TYPE_JPEG);
	dc = defaultColor.ConvertToImage();
	defaultColor = wxBitmap(dc.Scale(63, 91));

	playerHandTop.LoadFile("../../../../CS3450/Resources/cards/card_back.jpg", wxBITMAP_TYPE_JPEG);
	pct = playerHandTop.ConvertToImage();

	playerHandSide.LoadFile("../../../../CS3450/Resources/cards/card_back_side.jpg", wxBITMAP_TYPE_JPEG);
	pcs = playerHandSide.ConvertToImage();

	//Initializes card images and buttons
	::wxInitAllImageHandlers();
	std::string cardNum;

	for (int i = 0; i < 13; i++)
	{
		p2Cards[i] = wxBitmap(pcs.Scale(72, 50));
		p2Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER_SPADES, p2Cards[i], wxDefaultPosition, wxSize(72, 25), 0);

		p3Cards[i] = wxBitmap(pct.Scale(50, 72));
		p3Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER2_SPADES, p3Cards[i], wxDefaultPosition, wxSize(50, 72), 0);

		p4Cards[i] = wxBitmap(pcs.Scale(72, 50));
		p4Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER_SPADES, p4Cards[i], wxDefaultPosition, wxSize(72, 25), 0);


		//Add bitmap buttons to the sizers
		verticalBoxLeft->Add(p2Hand[i], wxCENTER, 0);
		verticalBoxRight->Add(p4Hand[i], wxCENTER, 0);
		horizontalBoxTop->Add(p3Hand[i], wxCENTER, 0);


	}




	gridBox = new wxGridSizer(7, 2, 3, 3);

	horizontalBoxMid->Add(verticalBoxLeft, wxALIGN_LEFT, 50);
	horizontalBoxMid->Add(horizontalBoxCenter, wxALIGN_CENTER, 50);
	horizontalBoxMid->Add(verticalBoxRight, wxALIGN_RIGHT, 50);
	horizontalBoxMid->Add(gridBox, wxALIGN_CENTER, 50);
	verticalBoxMain->Add(horizontalBoxTop, wxCENTER, 0);
	verticalBoxMain->Add(horizontalBoxMid, wxCENTER, 0);


	SetSizerAndFit(verticalBoxMain);

	CenterOnParent();
	Show(0);
	srand(time(NULL));

}

void SpadesBoard::display() //called when the Spades button is pressed on the game select screen. initializes the game
{
	Show(1);
	Player player1, player2, player3, player4;
	players.push_back(player1);
	players.push_back(player2);
	players.push_back(player3);
	players.push_back(player4);
	spadesPlay();

}

void SpadesBoard::hide()
{
	Show(0);
}

void SpadesBoard::cardClick(int i)
{
	std::cout << players[0].playerHand[i].getValue() << " " << players[0].playerHand[i].getSuit() << std::endl;
		if (!bidMode && turn == 0 && validateMove(0, players[0].playerHand[i], trickNum, turnOrder) && horizontalBoxCenter->GetItemCount() < 4)
		{
			wxBitmapButton *tmpButton = p1Hand[i];
			p1Hand[i]->Hide();
			horizontalBoxBtm->Detach(p1Hand[i]);
			horizontalBoxCenter->Add(tmpButton, wxCENTER, 50);
			horizontalBoxCenter->Layout();
			horizontalBoxBtm->Layout();

			tmpButton->Show();
			centerCards[0] = tmpButton;
			Card tmp = players[0].playerHand[i];
			centerPile.push_back(tmp);
			players[0].playerHand[i].setSuit(UNDEFINED);
			turn = (turn + 1) % 4;
			turnOrder++;
			takeTurn();
		}
}

void SpadesBoard::spadesPlay() //starts the game
{
	if (players[0].getScore() < 100 && players[1].getScore() < 100 && players[2].getScore() < 100 && players[3].getScore() < 100)
	{
		for (int i = 0; i < 4; i++)
		{
			players[i].playerHand.reserve(13);
		}
		std::vector<Card> deck = initializeDeck();
		dealCards(deck);
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Player " << i << " hand: " << std::endl;
			for (int j = 0; j < 13; j++)
			{
				std::cout << players[i].playerHand[j].getValue() << " " << players[i].playerHand[j].getSuit() << std::endl;
			}
		}
		players[0].setBid(0);
		turn = 1;
		displayHand(players[0].playerHand);
		bidMode= true;
		makeBids();

		updateScoreBoard();
		wxMessageBox("Enter bid then click bid button.", "Bid", wxOK | wxICON_INFORMATION);

	}

}

std::vector<Card> SpadesBoard::initializeDeck() //initializes the deck
{
	std::vector<Card> deck;
	deck.reserve(52);
	std::vector<Suit> suits = { HEARTS, SPADES, CLUBS, DIAMONDS };
	for (auto&& suit : suits)
	{
		for (int i = 2; i <= 14; i++)
		{
			deck.push_back(Card(suit, (Value)i));
		}
	}
	return deck;
}

// shuffle and deals the cards to the players
// takes in a deck of cards
void SpadesBoard::dealCards(std::vector<Card>& Deck)
{

	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(Deck.begin(), Deck.end(), generator);
	for (size_t i = 0; i < players.size(); i++)
	{
		for (auto j = 0; j < 13; j++)
		{
			players[i].insertCardToHand(Deck[(j)+(13 * i)]);
		}
	}
	players[0].organizeHand(players[0].playerHand);
}

void SpadesBoard::displayHand(std::vector<Card> playerHand) //displays the human player's hand
{
	std::string cardNum;
	wxImage pc;
	horizontalBoxBtm->Clear();
	horizontalBoxBtm->Layout();
	for (int i = 0; i < players[0].playerHand.size(); i++)
	{
		cardNum = playerHand[i].getImagePath();
		p1Cards[i].LoadFile(cardNum, wxBITMAP_TYPE_PNG);
		pc = p1Cards[i].ConvertToImage();
		p1Cards[i] = wxBitmap(pc.Scale(63, 91));
		p1Hand[i] = new wxBitmapButton(this, BUTTON_CARD1_SPADES + i, p1Cards[i], wxDefaultPosition, wxSize(63, 91), 0);
		horizontalBoxBtm->Add(p1Hand[i], wxCENTER, 0);
	}

	verticalBoxMain->Add(horizontalBoxBtm, wxCENTER, 0);
	SetSizerAndFit(verticalBoxMain);

	CenterOnParent();
	horizontalBoxBtm->Layout();
}

// checks to see if a move is valid
// takes index of player in vector, the proposed card,
// the trick number, and the turn number
// returns a bool of whether the card is a valid move
bool SpadesBoard::validateMove(int index, Card move, int numTrick, int turn)
{
	Suit lead;
	if (centerPile.size() > 0) lead = centerPile[0].getSuit();
	if (turn == 0)
	{
		if (centerPile.size() == 0)
		{
			if (move.getSuit() == UNDEFINED)
				return false;
			else if (move.getSuit() == SPADES && !brokenSpades)
				return false;
			else
				return true;
		}
		else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].playerHand))
			{
				if (move.getSuit() == SPADES && brokenSpades)
					return true;
				else if (move.getSuit() == SPADES && allSpades(players[index].playerHand))
				{
					brokenSpades = true;
					return true;
				}
				else if (move.getSuit() == SPADES)
					return false;
				else
					return true;
			}
			else if (move.getSuit() != lead)
				return false;
			else
				return true;
		}
	}
	else
	{
		if (centerPile.size() == 0)
		{
			if (move.getSuit() == UNDEFINED)
				return false;
			else if (move.getSuit() == SPADES && allSpades(players[index].playerHand))
			{
				brokenSpades = true;
				return true;
			}
			else if (move.getSuit() == SPADES && brokenSpades)
				return true;
			else if (move.getSuit() == SPADES)
				return false;
			return true;
		}
		else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].playerHand))
			{
				if (move.getSuit() == SPADES && brokenSpades)
					return true;
				else if (move.getSuit() == SPADES && allSpades(players[index].playerHand))
				{
					brokenSpades = true;
					return true;
				}
				else if (move.getSuit() == SPADES)
					return false;
				else
					return true;
			}
			else if (move.getSuit() != lead)
				return false;
			else
				return true;
		}
	}
	return false;
}

// checks to see if a players hand is all hearts.
// takes a vector of cards, ie the player's hand
// returns a bool of whether all the cards are hearts
bool SpadesBoard::allSpades(std::vector<Card> h)
{

	for (size_t i = 0; i < h.size(); ++i)
	{
		if (h[i].getSuit() != SPADES && h[i].getSuit() != UNDEFINED)
		{
			return false;
		}
	}
	return true;
}

// compares hand against the lead suit
// Takes in a suit and the player's hand
// returns a bool whether there is a card with suit s
// in the hand
bool SpadesBoard::noLeadSuit(Suit s, std::vector<Card> h)
{
	for (size_t i = 0; i < h.size(); ++i)
	{
		if (h[i].getSuit() == s)
		{
			return false;
		}
	}
	return true;
}

void SpadesBoard::updateScoreBoard()
{
	
	if (bidText)
		bidText->Destroy();
	wxString p1Score, p2Score, p3Score, p4Score, p1Bid, p2Bid, p3Bid, p4Bid, p1Bag, p2Bag, p3Bag, p4Bag;
	p1Score << players[0].getScore();
	p2Score << players[1].getScore();
	p3Score << players[2].getScore();
	p4Score << players[3].getScore();
	p1Bid << players[0].getBid();
	p2Bid << players[1].getBid();
	p3Bid << players[2].getBid();
	p4Bid << players[3].getBid();
	p1Bag << players[0].getBags();
	p2Bag << players[1].getBags();
	p3Bag << players[2].getBags();
	p4Bag << players[3].getBags();


	player1Score = "Your Score: " + p1Score;
	player2Score = "Player 2 Score: " + p2Score;
	player3Score = "Player 3 Score: " + p3Score;
	player4Score = "Player 4 Score: " + p4Score;
	player1Bid = "Your bid: " + p1Bid;
	player2Bid = "Player 2 bid: " + p2Bid;
	player3Bid = "Player 3 bid: " + p3Bid;
	player4Bid = "Player 4 bid: " + p4Bid;
	player1Bags = "Your bags: " + p1Bag;
	player2Bags = "Player 2 bags: " + p2Bag;
	player3Bags = "Player 3 bags: " + p3Bag;
	player4Bags = "Player 4 bags: " + p4Bag;


	gridBox->Clear();

	bidButton = new wxButton(this, BUTTON_BID+turnOrder, _T("Bid"), wxDefaultPosition, wxSize(140, 30));

	bidText = new wxTextCtrl(this, 0, "Enter Bid Here", wxDefaultPosition,
		wxSize(140, 30));

	player1ScoreStaticText = new wxStaticText(this, 0, player1Score, wxDefaultPosition,
		wxSize(140, 30));
	player1BidStaticText = new wxStaticText(this, 0, player1Bid, wxDefaultPosition,
		wxSize(140, 30));
	player1BagStaticText = new wxStaticText(this, 0, player1Bags, wxDefaultPosition,
		wxSize(140, 30));
	player2ScoreStaticText = new wxStaticText(this, 0, player2Score, wxDefaultPosition,
		wxSize(140, 30));
	player2BidStaticText = new wxStaticText(this, 0, player2Bid, wxDefaultPosition,
		wxSize(140, 30));
	player2BagStaticText = new wxStaticText(this, 0, player2Bags, wxDefaultPosition,
		wxSize(140, 30));
	player3ScoreStaticText = new wxStaticText(this, 0, player3Score, wxDefaultPosition,
		wxSize(140, 30));
	player3BidStaticText = new wxStaticText(this, 0, player3Bid, wxDefaultPosition,
		wxSize(140, 30));
	player3BagStaticText = new wxStaticText(this, 0, player3Bags, wxDefaultPosition,
		wxSize(140, 30));
	player4ScoreStaticText = new wxStaticText(this, 0, player4Score, wxDefaultPosition,
		wxSize(140, 30));
	player4BidStaticText = new wxStaticText(this, 0, player4Bid, wxDefaultPosition,
		wxSize(140, 30));
	player4BagStaticText = new wxStaticText(this, 0, player4Bags, wxDefaultPosition,
		wxSize(140, 30));

	gridBox->Add(player1ScoreStaticText);
	gridBox->Add(player1BidStaticText);
	gridBox->Add(player2ScoreStaticText);
	gridBox->Add(player2BidStaticText);
	gridBox->Add(player3ScoreStaticText);
	gridBox->Add(player3BidStaticText);
	gridBox->Add(player4ScoreStaticText);
	gridBox->Add(player4BidStaticText);
	gridBox->Add(bidButton);
	gridBox->Add(bidText);
	gridBox->Add(player1BagStaticText);
	gridBox->Add(player2BagStaticText);
	gridBox->Add(player3BagStaticText);
	gridBox->Add(player4BagStaticText);

	gridBox->Layout();
	horizontalBoxMid->Layout();
}

void SpadesBoard::onBidButton()
{
	if (bidMode)
	{
		std::string userBid = bidText->GetLineText(0); //need to add input verification for when user enters a non number
		int userBidInt = wxAtoi(userBid);
		players[0].setBid(userBidInt);
		bidMode = false;
		updateScoreBoard();
		for (int i = 0; i < 4; i++)
		{
			std::cout << i << " " << players[i].getBid() << std::endl;
		}
		takeTurn();
		
	}
}

//this function is the main gameplay function and takes care of the computer's turns.
void SpadesBoard::takeTurn()
{

	if (turn != 0 && centerPile.size() < 4)  //continues to take computer turns
	{
		int moveIndex = computerTurn(turn);

		std::string cardName = players[turn].playerHand[moveIndex].getImagePath();
		wxImage cpuCard;
		wxBitmap cpuCardBitmap;
		wxBitmapButton *cpuCardBitmapButton;
		cpuCardBitmap.LoadFile(cardName, wxBITMAP_TYPE_PNG);
		cpuCard = cpuCardBitmap.ConvertToImage();
		cpuCardBitmap = wxBitmap(cpuCard.Scale(63, 91));
		centerCards[turn] = new wxBitmapButton(this, BUTTON_CARD_OTHER2_SPADES + turnOrder + trickNum + 1, cpuCardBitmap, wxDefaultPosition, wxSize(63, 91), 0);
		if (turn == 1)
		{
			p2Hand[trickNum]->Hide();
		}
		else if (turn == 2)
		{
			p3Hand[trickNum]->Hide();
		}
		else if (turn == 3)
		{
			p4Hand[trickNum]->Hide();
		}

		wxSleep(.75);

		horizontalBoxCenter->Add(centerCards[turn], wxCENTER, 50);
		horizontalBoxCenter->Layout();

		Card tmp = players[turn].playerHand[moveIndex];
		centerPile.push_back(tmp);
		//players[turn].playerHand.erase(players[turn].playerHand.begin() + moveIndex);
		players[turn].playerHand[moveIndex].setSuit(UNDEFINED);
		turn = (turn + 1) % 4;
		turnOrder++;
		horizontalBoxCenter->Layout();
		if (centerPile.size() < 4)
		{
			wxSleep(.90);
			takeTurn();
		}
	}
	if (centerPile.size() == 4) //when the center is full it will determine who won the trick, update the score and reset the center
	{
		if (players[0].getScore() < 200 && players[1].getScore() < 200 && players[2].getScore() < 200 && players[3].getScore() < 200)
		{
			int trickWinner = endTurn(turn);
			if (trickWinner == 0)
			{
				wxMessageBox("You win the trick.", "Trick over", wxOK | wxICON_INFORMATION);
			}
			else
			{
				std::string message = "Player " + std::to_string(trickWinner + 1) + " wins the trick.";
				wxMessageBox(message, "Trick over", wxOK | wxICON_INFORMATION);
				for (int i = 0; i < players.size(); i++)
				{
					std::cout << "Player " << i << " score: " << players[i].getScore() << std::endl;
				}
			}
			for (int i = 0; i < 4; i++)
			{
				horizontalBoxCenter->Detach(centerCards[i]);
				centerCards[i]->Destroy();
			}
			horizontalBoxCenter->Layout();
			turn = trickWinner;
			trickNum++;
			if (trickNum < 13)
			{
				takeTurn();
			}
			else if (trickNum == 13) //if all cards have been played it will update scores, remake the deck, shuffle and redeal
			{
				score();
				makeBids();
				player1ScoreStaticText->Destroy();
				player1BidStaticText->Destroy();
				player2ScoreStaticText->Destroy();
				player2BidStaticText->Destroy();
				player3ScoreStaticText->Destroy();
				player3BidStaticText->Destroy();
				player4ScoreStaticText->Destroy();
				player4BidStaticText->Destroy();
				player1BagStaticText->Destroy();
				player2BagStaticText->Destroy();
				player3BagStaticText->Destroy();
				player4BagStaticText->Destroy();
				//updateScoreBoard();
				centerPile.clear();
				trickNum = 0;
				turnOrder = 0;
				brokenSpades = false;
				gridBox->Clear();
				horizontalBoxBtm->Clear();
				verticalBoxMain->Detach(horizontalBoxBtm);
				for (int i = 0; i < players.size(); i++)
				{
					players[i].playerHand.clear();
				}
				if (players[0].getScore() >= 200 || players[1].getScore() >= 200 || players[2].getScore() >= 200 || players[3].getScore() >= 200) //checks if anyone has won.

				{
					updateScoreBoard();
					int highest = players[0].getScore();
					int highestIndex = 0;
					for (int i = 1; i < players.size(); i++)
					{
						if (players[i].getScore() > highest)
						{
							highest = players[i].getScore();
							highestIndex = i;
						}
					}
					std::string message = "Player " + std::to_string(highestIndex + 1) + " is the winner!";
					wxMessageBox(message, "Game Over", wxOK | wxICON_INFORMATION);
					returnButton = new wxButton(this, BUTTON_RETURN_BUTTON_SPADES, _T("Exit"), wxDefaultPosition, wxSize(140, 30));
					returnButton->Show();
					return;

					//we need to make it so when the game is over it will take you back to the game select screen.
				}
				for (int j = 0; j < 13; j++)
				{
					p2Hand[j]->Show();
					p3Hand[j]->Show();
					p4Hand[j]->Show();
				}
				std::vector<Card> deck = initializeDeck();
				dealCards(deck);
				displayHand(players[0].playerHand);
				bidMode = true;
				//makeBids();
				//horizontalBoxMid->Add(gridBox);
				updateScoreBoard();
				wxMessageBox("Make a bid.", "Bid", wxOK | wxICON_INFORMATION);

			}
		}
	}
}


int SpadesBoard::computerTurn(int player) //finds a valid move for a computer
{
	for (int i = 0; i < players[player].playerHand.size(); i++)
	{
		if (validateMove(player, players[player].playerHand[i], trickNum, turnOrder))
		{
			return i;
		}
	}
}

// finished the turn
// takes the index of the current player
// returns the player index who won the trick
int SpadesBoard::endTurn(int currentPlayer)
{
	std::cout << "pass" << std::endl;
	Suit leadSuit = centerPile[0].getSuit();
	int maxIndex = 0;
	int maxValue = 0;
	int score = 0;
	for (int i = 0; i < centerPile.size(); i++)
	{
		Card tmp = centerPile[i];
		if (tmp.getSuit() == leadSuit && tmp.getValue() > maxValue)
		{
			maxValue = tmp.getValue();
			maxIndex = i;
		}
	}
	players[(maxIndex + currentPlayer) % players.size()].incrementTricksWon();
	centerPile.clear();
	updateScoreBoard();
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Player " << i << " tricks won: " << players[i].getTricksWon() << std::endl;
	}

	return (maxIndex + currentPlayer) % players.size();
}

void SpadesBoard::score() //adapted from function in https://github.com/michaelkamerath/SharedServer/blob/master/source/GameLogic/SpadesLogic.cpp
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Player " << i << " tricks won: " << players[i].getTricksWon() << std::endl;
	}
	
	for (int i = 0; i < players.size(); i++)
	{
		auto bid = players[i].getBid();
		auto tricks = players[i].getTricksWon();
		auto bag = players[i].getBags();
		if (bid == tricks)
		{
			players[i].incrementScore(bid * 10);
		}
		else if (bid < tricks)
		{
			int sc = bid * 10;
			for (int b = bid; b < tricks; b++)
			{
				sc++;
				bag++;
			}
			players[i].incrementScore(sc);
			players[i].setBags(bag);
		}
		else if (bid > tricks)
		{
			players[i].incrementScore(0);
		}
		if (bag >= 10)
		{
			players[i].incrementScore(-100);
			players[i].setBags(bag % 10);
		}
		if (players[i].getScore() < 0)
		{
			players[i].setScore(0);
		}
	}
}

void SpadesBoard::makeBids()
{
	for (int i = 1; i < players.size(); i++)
	{
		int randBid = rand() % 10;
		players[i].setBid(randBid);
	}

}