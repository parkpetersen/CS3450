#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <wx/wx.h>


class GameOver : public wxPanel
{
public:
	GameOver(wxFrame* parent);
	wxButton *playAgain;
	wxButton *mainMenu;
	void display();
	void hide();

};

enum
{
	BUTTON_mainMenu = wxID_HIGHEST + 7,
	BUTTON_playAgain = wxID_HIGHEST + 9
};
#endif
