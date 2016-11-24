#ifndef HEARTSBOARD_HPP
#define HEARTSBOARD_HPP

#include <wx/wx.h>
#include <vector>
#include "source\ClientInfo\Player.hpp"


class HeartsBoard : public wxPanel
{
public:
	HeartsBoard(wxFrame* parent);
	std::vector<Player> players;
	int turn; //this refers to who's turn it is
	int turnOrder=0; //this refers to what turn out of the four in the trick we are on
	int trickNum = 0; 
	bool cardPass = false;
	std::vector<Card> cardsToPass;
	std::vector<int> p1PassCardsIndices;
	std::vector<Card> centerPile;
	bool brokenHearts = false;


	//sizers
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
	void heartsPlay();
	std::vector<Card> initializeDeck();
	void displayHand(std::vector<Card>);
	void passCards();
	int findTwoOfClubs();
	bool allhearts(std::vector<Card> h);
	bool noLeadSuit(Suit s, std::vector<Card> h);
	bool validateMove(int index, Card move, int numTrick, int turn);
	void takeTurn();
	int computerTurn(int);
	int endTurn(int currentPlayer);
	void dealCards(std::vector<Card>& Deck);
};

enum
{
	BUTTON_CARD_CENTER = wxID_HIGHEST + 13,
	BUTTON_CARD1 = wxID_HIGHEST + 17,
	BUTTON_CARD_OTHER = wxID_HIGHEST + 30,
	BUTTON_CARD_OTHER2 = wxID_HIGHEST + 31
};
#endif
