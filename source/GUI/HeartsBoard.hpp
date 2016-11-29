#ifndef HEARTSBOARD_HPP
#define HEARTSBOARD_HPP

#include <wx/wx.h>
#include <vector>
#include <source/ClientInfo/Player.hpp>
#include <source/HeartsLogic/HeartsGame.hpp>


class HeartsBoard : public wxPanel
{
public:
	HeartsBoard(wxFrame* parent);

	int turn;
	int p1Score, p2Score, p3Score, p4Score;
	int p1RoundScore, p2RoundScore, p4RoundScore;

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
	wxBitmap centerCards[4];

	//Bitmap buttons (should be vectors)
	wxBitmapButton *p1Hand[13];
	wxBitmapButton *p2Hand[13];
	wxBitmapButton *p3Hand[13];
	wxBitmapButton *p4Hand[13];
	wxBitmapButton *centerPile[4];

	void display();
	void hide();
	void cardClick(int i);
	void heartsPlay(std::vector<Player>);
	std::vector<Card> initializeDeck();
	void displayHand(std::vector<Card>);
};

enum
{
	BUTTON_CARD_CENTER = wxID_HIGHEST + 13,
	BUTTON_CARD1 = wxID_HIGHEST + 17,
	BUTTON_CARD_OTHER = wxID_HIGHEST + 30,
	BUTTON_CARD_OTHER2 = wxID_HIGHEST + 31
};
#endif
