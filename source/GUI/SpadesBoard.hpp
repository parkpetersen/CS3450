#ifndef SPADESBOARD_HPP
#define SPADESBOARD_HPP

#include <wx/wx.h>
#include <vector>
#include "source\ClientInfo\Player.hpp"


class SpadesBoard : public wxPanel
{
public:
	SpadesBoard(wxFrame* parent);
	std::vector<Player> players;
	int turn; //this refers to who's turn it is
	int turnOrder = 0; //this refers to what turn out of the four in the trick we are on
	int trickNum = 0;
	bool bidMode = false;
	std::vector<Card> cardsToPass;
	std::vector<int> p1PassCardsIndices;
	std::vector<Card> centerPile;
	bool brokenSpades = false;

	wxTextCtrl *bidText;
	wxButton *bidButton;
	void onBidButton();

	wxString player1Score;
	wxString player2Score;
	wxString player3Score;
	wxString player4Score;

	wxString player1Bid;
	wxString player2Bid;
	wxString player3Bid;
	wxString player4Bid;

	wxString player1Bags;
	wxString player2Bags;
	wxString player3Bags;
	wxString player4Bags;


	wxStaticText *player1ScoreStaticText;
	wxStaticText *player1BidStaticText;
	wxStaticText *player1BagStaticText;
	wxStaticText *player2ScoreStaticText;
	wxStaticText *player2BidStaticText;
	wxStaticText *player2BagStaticText;
	wxStaticText *player3ScoreStaticText;
	wxStaticText *player3BidStaticText;
	wxStaticText *player3BagStaticText;
	wxStaticText *player4ScoreStaticText;
	wxStaticText *player4BidStaticText;
	wxStaticText *player4BagStaticText;

	//sizers
	wxGridSizer *gridBox;
	wxFlexGridSizer *verticalBoxMain;
	wxBoxSizer *horizontalBoxBtm;
	wxBoxSizer *horizontalBoxMid;
	wxBoxSizer *horizontalBoxTop;
	wxBoxSizer *verticalBoxLeft;
	wxBoxSizer *verticalBoxCenter;
	wxBoxSizer *verticalBoxRight;
	wxFlexGridSizer *horizontalBoxCenter;


	//Bitmap images (should be vectors)
	wxBitmap p1Cards[13];
	wxBitmap p2Cards[13];
	wxBitmap p3Cards[13];
	wxBitmap p4Cards[13];
	//wxBitmap centerCards[4];

	//Bitmap buttons (should be vectors)
	wxBitmapButton *p1Hand[13];
	wxBitmapButton *p2Hand[13];
	wxBitmapButton *p3Hand[13];
	wxBitmapButton *p4Hand[13];
	wxBitmapButton *centerCards[4];


	void display();
	void hide();
	void cardClick(int i);
	void spadesPlay();
	std::vector<Card> initializeDeck();
	void dealCards(std::vector<Card>& Deck);
	void displayHand(std::vector<Card>);
	
	bool allSpades(std::vector<Card> h);
	bool noLeadSuit(Suit s, std::vector<Card> h);
	bool validateMove(int index, Card move, int numTrick, int turn);
	void takeTurn();
	int computerTurn(int);
	int endTurn(int currentPlayer);
	void score();
	void makeBids();
	void updateScoreBoard();
	wxButton *returnButton;
	wxButton *hintButton;
	void giveHint();
};

enum
{
	BUTTON_CARD_CENTER_SPADES = wxID_HIGHEST + 32,
	BUTTON_CARD1_SPADES = wxID_HIGHEST + 36,
	BUTTON_CARD_OTHER_SPADES = wxID_HIGHEST + 49,
	BUTTON_CARD_OTHER2_SPADES = wxID_HIGHEST + 50,
	BUTTON_BID = wxID_ANY,
	BUTTON_RETURN_BUTTON_SPADES = wxID_HIGHEST+99,
	BUTTON_HINT_SPADES = wxID_HIGHEST+100
};
#endif
