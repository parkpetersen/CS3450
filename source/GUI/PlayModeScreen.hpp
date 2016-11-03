#ifndef PLAYMODESCREEN_H
#define PLAYMODESCREEN_H

#include <wx/wx.h>


class PlayModeScreen : public wxPanel
{
public:
	PlayModeScreen(wxFrame* parent);
	wxButton *hearts;
	wxButton *spades;
	wxButton *crazyEights;
	wxButton *modeCancel;
	void display();
	void hide();

};

enum
{
	BUTTON_Hearts = wxID_HIGHEST + 6,
	BUTTON_Spades = wxID_HIGHEST + 7,
	BUTTON_modeCancel = wxID_HIGHEST + 8,
	BUTTON_Eights = wxID_HIGHEST + 9
};
#endif