#ifndef PLAYMODESCREEN_HPP
#define PLAYMODESCREEN_HPP

#include <wx/wx.h>


class PlayModeScreen : public wxPanel
{
public:
	PlayModeScreen(wxFrame* parent);
	wxButton *hearts;
	wxButton *spades;
	wxButton *crazyEights;
	wxButton *modeCancel;
	wxBitmap test1;
	wxBitmapButton *test2;
	void display();
	void hide();

};

enum
{
	BUTTON_Hearts = wxID_HIGHEST + 6,
	BUTTON_Spades = wxID_HIGHEST + 7,
	BUTTON_modeCancel = wxID_HIGHEST + 8,
	BUTTON_Eights = wxID_HIGHEST + 9,
	BUTTON_test = wxID_HIGHEST + 12
};
#endif