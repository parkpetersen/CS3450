#include <wx/wx.h>
#include <wx/sizer.h>
#include "HeartsBoard.hpp"
#include <random>

#include "source/ClientInfo/Card.hpp"
#include "source/ClientInfo/Player.hpp"


HeartsBoard::HeartsBoard(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	//Sizers
	verticalBoxMain = new wxFlexGridSizer(3, 0, 20, 20);
	horizontalBoxBtm = new wxBoxSizer(wxHORIZONTAL);
	horizontalBoxMid = new wxFlexGridSizer(0, 3, 200, 200);
	horizontalBoxTop = new wxBoxSizer(wxHORIZONTAL);
	verticalBoxLeft = new wxBoxSizer(wxVERTICAL);
	verticalBoxCenter = new wxBoxSizer(wxVERTICAL);
	verticalBoxRight = new wxBoxSizer(wxVERTICAL);

	horizontalBoxCenter = new wxFlexGridSizer(2, 2, 10, 10);
	horizontalBoxMiddle = new wxFlexGridSizer(0, 2, 150, 150);

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
		p2Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER, p2Cards[i], wxDefaultPosition, wxSize(72, 25), 0);

		p3Cards[i] = wxBitmap(pct.Scale(50, 72));
		p3Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER2, p3Cards[i], wxDefaultPosition, wxSize(50, 72), 0);

		p4Cards[i] = wxBitmap(pcs.Scale(72, 50));
		p4Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER, p4Cards[i], wxDefaultPosition, wxSize(72, 25), 0);


		//Add bitmap buttons to the sizers
		verticalBoxLeft->Add(p2Hand[i], wxCENTER, 0);
		verticalBoxRight->Add(p4Hand[i], wxCENTER, 0);
		horizontalBoxTop->Add(p3Hand[i], wxCENTER, 0);


	}
	



	gridBox = new wxGridSizer(2, 2, 3, 3);

	horizontalBoxMid->Add(verticalBoxLeft, wxALIGN_LEFT, 50);
	horizontalBoxMid->Add(horizontalBoxCenter, wxALIGN_CENTER, 50);
	horizontalBoxMid->Add(verticalBoxRight, wxALIGN_RIGHT, 50);
	horizontalBoxMiddle->Add(horizontalBoxMid, wxALIGN_LEFT, 0);
	horizontalBoxMiddle->Add(gridBox, wxALIGN_RIGHT, 0);
	verticalBoxMain->Add(horizontalBoxTop, wxCENTER, 0);
	verticalBoxMain->Add(horizontalBoxMiddle, wxCENTER, 0);

	//p1Hand[2]->Hide();
	//horizontalBoxMid->Remove(2);
	//centerPile[2]->Hide();
	//horizontalBoxCenter->Remove(2);
	//horizontalBoxCenter->Add(p1Hand[2], wxCENTER, 0);

	SetSizerAndFit(verticalBoxMain);

	CenterOnParent();
	Show(0);

}

void HeartsBoard::display() //called when the hearts button is pressed on the game select screen. initializes the game
{
	Show(1);
	Player player1, player2, player3, player4;
	players.push_back(player1);
	players.push_back(player2);
	players.push_back(player3);
	players.push_back(player4);
	heartsPlay();

}

void HeartsBoard::hide()
{
	Show(0);
}

void HeartsBoard::cardClick(int i)
{
	if (cardPass == true)
	{
		p1PassCardsIndices.push_back(i);
		if (p1PassCardsIndices.size() == 3)             //allows player to click 3 cards to pass to other player
		{
			passCards();
		}
		
	}

	else //moves the cards to the center
	{
		if (turn == 0 && validateMove(0, players[0].playerHand[i], trickNum, turnOrder) && horizontalBoxCenter->GetItemCount() < 4)
		{
			wxBitmapButton *tmpButton = p1Hand[i];
			p1Hand[i]->Hide();
			horizontalBoxBtm->Detach(p1Hand[i]);
			//p1Hand[i]->Destroy();
			horizontalBoxCenter->Add(tmpButton, wxCENTER, 50);
			horizontalBoxCenter->Layout();
			horizontalBoxBtm->Layout();

			tmpButton->Show();
			centerCards[0]=tmpButton;
			Card tmp = players[0].playerHand[i];
			centerPile.push_back(tmp);
			players[0].playerHand[i].setSuit(UNDEFINED);
			turn = (turn+1)%4;
			turnOrder++;
			takeTurn();
		}
	}

}

void HeartsBoard::heartsPlay() //starts the game
{
	if (players[0].getScore() < 100 && players[1].getScore() < 100 && players[2].getScore() < 100 && players[3].getScore() < 100)
	{
		for (int i = 0; i < 4; i++)
		{
			players[i].playerHand.reserve(13);
		}
		std::vector<Card> deck = initializeDeck();
		dealCards(deck);
		verticalBoxMain->Detach(horizontalBoxBtm);
		SetSizerAndFit(verticalBoxMain);
		updateScoreBoard();
		displayHand(players[0].playerHand);
		cardPass = true;
		horizontalBoxMiddle->Layout();
		wxMessageBox("Choose 3 cards to pass.", "Pass Cards", wxOK | wxICON_INFORMATION);

	}

}

std::vector<Card> HeartsBoard::initializeDeck() //initializes the deck
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

void HeartsBoard::displayHand(std::vector<Card> playerHand) //displays the human player's hand
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
		p1Hand[i] = new wxBitmapButton(this, BUTTON_CARD1 + i, p1Cards[i], wxDefaultPosition, wxSize(63, 91), 0);
		horizontalBoxBtm->Add(p1Hand[i], wxCENTER, 0);
	}

	verticalBoxMain->Add(horizontalBoxBtm, wxCENTER, 0);
	SetSizerAndFit(verticalBoxMain);

	CenterOnParent();
	horizontalBoxBtm->Layout();
}

void HeartsBoard::passCards() //passes the three cards to another player (incomplete, right now it just trades three cards with a player) alternates which player is traded to
{


	std::iter_swap(players[0].playerHand.begin() + p1PassCardsIndices[0], players[(trickNum + 1) % 4].playerHand.begin());
	std::iter_swap(players[0].playerHand.begin() + p1PassCardsIndices[1], players[(trickNum + 1) % 4].playerHand.begin() + 1);
	std::iter_swap(players[0].playerHand.begin() + p1PassCardsIndices[2], players[(trickNum + 1) % 4].playerHand.begin() + 2);

	horizontalBoxBtm->Detach(p1Hand[p1PassCardsIndices[0]]);
	horizontalBoxBtm->Detach(p1Hand[p1PassCardsIndices[1]]);
	horizontalBoxBtm->Detach(p1Hand[p1PassCardsIndices[2]]);

	for (int i = 0; i < 13; i++)
	{
		p1Hand[i]->Destroy();

	}
	verticalBoxMain->Detach(horizontalBoxBtm);
	SetSizerAndFit(verticalBoxMain);

	cardsToPass.clear();
	p1PassCardsIndices.clear();
	cardPass = false;
	displayHand(players[0].playerHand);
	turn = findTwoOfClubs();
	takeTurn();



}

// looks through each hand to find the 2 of clubs
// returns the index of the player with the 2 of clubs
int HeartsBoard::findTwoOfClubs()
{
	for (size_t i = 0; i < players.size(); ++i)
	{
		std::vector<Card> temp = players[i].playerHand;
		for (auto j = 0; j < 13; ++j)
		{
			if (temp[j].getSuit() == Suit::CLUBS && temp[j].getValue() == 2)
			{
				return i;
			}
		}
	}
	return -1;
}

// checks to see if a players hand is all hearts.
// takes a vector of cards, ie the player's hand
// returns a bool of whether all the cards are hearts
bool HeartsBoard::allhearts(std::vector<Card> h)
{

	for (size_t i = 0; i < h.size(); ++i)
	{
		if (h[i].getSuit() != HEARTS && h[i].getSuit() != UNDEFINED)
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
bool HeartsBoard::noLeadSuit(Suit s, std::vector<Card> h)
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

// checks to see if a move is valid
// takes index of player in vector, the proposed card,
// the trick number, and the turn number
// returns a bool of whether the card is a valid move
bool HeartsBoard::validateMove(int index, Card move, int numTrick, int turn)
{
	Suit lead;
	if (centerPile.size() > 0) lead = centerPile[0].getSuit();
	if (turn == 0)
	{
		if (centerPile.size() == 0)
		{
			if (move.getSuit() != CLUBS || move.getValue() != TWO || move.getSuit() == UNDEFINED)
				return false;
			else
				return true;
		}
		else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].playerHand))
			{
				if (move.getSuit() == HEARTS && brokenHearts)
					return true;
				else if (move.getSuit() == HEARTS &&
					allhearts(players[index].playerHand))
				{
					brokenHearts = true;
					return true;
				}
				else if (move.getSuit() == HEARTS)
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
			else if (move.getSuit() == HEARTS && allhearts(players[index].playerHand))
			{
				brokenHearts = true;
				return true;
			}
			else if (move.getSuit() == HEARTS && brokenHearts)
				return true;
			else if (move.getSuit() == HEARTS)
				return false;
			return true;
		}
		else
		{
			if (move.getSuit() != lead && noLeadSuit(lead, players[index].playerHand))
			{
				if (move.getSuit() == HEARTS && brokenHearts)
					return true;
				else if (move.getSuit() == HEARTS &&
					allhearts(players[index].playerHand))
				{
					brokenHearts = true;
					return true;
				}
				else if (move.getSuit() == HEARTS)
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

//this function is the main gameplay function and takes care of the computer's turns.
void HeartsBoard::takeTurn()
{
	for (int i = 0; i < players.size(); i++)
	{
		std::cout << "Player " << i << " score: " << players[i].getScore() << std::endl;
	}
	
	if (players[0].getScore() >= 100 || players[1].getScore() >= 100 || players[2].getScore() >= 100 || players[3].getScore() >= 100) //checks if anyone has won.

	{
		int lowest = players[0].getScore();
		int lowestIndex = 0;
		for (int i = 1; i < players.size(); i++)
		{
			if (players[i].getScore() < lowest)
			{
				lowest = players[i].getScore();
				lowestIndex = i;
			}
		}
		std::string message = "Player " + std::to_string(lowestIndex+1) + " is the winner!";
		wxMessageBox(message, "Game Over", wxOK | wxICON_INFORMATION);
		Hide();
		//we need to make it so when the game is over it will take you back to the game select screen.
	}

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
		centerCards[turn] = new wxBitmapButton(this, BUTTON_CARD_OTHER2 + turnOrder + trickNum + 1, cpuCardBitmap, wxDefaultPosition, wxSize(63, 91), 0);
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
			takeTurn();
		}
	}
	if (centerPile.size() == 4) //when the center is full it will determine who won the trick, update the score and reset the center
	{
		if (players[0].getScore() < 100 && players[1].getScore() < 100 && players[2].getScore() < 100 && players[3].getScore() < 100)
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
			else if (trickNum == 13) //if all cards have been played it will remake the deck, shuffle and redeal
			{
				centerPile.clear();
				trickNum = 0;
				turnOrder = 0;
				brokenHearts = false;
				horizontalBoxBtm->Clear();
				verticalBoxMain->Detach(horizontalBoxBtm);
				for (int i = 0; i < players.size(); i++)
				{
					players[i].playerHand.clear();
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
				cardPass = true;
				wxMessageBox("Choose 3 cards to pass.", "Pass Cards", wxOK | wxICON_INFORMATION);

			}
		}
	}
}


int HeartsBoard::computerTurn(int player) //finds a valid move for a computer
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
int HeartsBoard::endTurn(int currentPlayer)
{
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
		if (tmp.getSuit() == SPADES && tmp.getValue() == 11) score += 13;
		if (tmp.getSuit() == HEARTS) score++;
	}
	players[(maxIndex + currentPlayer) % players.size()].incrementScore(
		score);
	centerPile.clear();
	updateScoreBoard();
	return (maxIndex + currentPlayer) % players.size();
}

// shuffle and deals the cards to the players
// takes in a deck of cards
void HeartsBoard::dealCards(std::vector<Card>& Deck)
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
}

void HeartsBoard::updateScoreBoard()
{
	wxString p1Score, p2Score, p3Score, p4Score;
	p1Score << players[0].getScore();
	p2Score << players[1].getScore();
	p3Score << players[2].getScore();
	p4Score << players[3].getScore();

	player1Score = "You: " + p1Score;
	player2Score = "Player 2 Score: " + p2Score;
	player3Score = "Player 3 Score: " + p3Score;
	player4Score = "Player 4 Score: " + p4Score;

	gridBox->Clear();
	
	gridBox->Add(new wxStaticText(this, 0, player1Score, wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Add(new wxStaticText(this, 0, player2Score, wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Add(new wxStaticText(this, 0, player3Score, wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Add(new wxStaticText(this, 0, player4Score, wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Layout();
	horizontalBoxMid->Layout();
}