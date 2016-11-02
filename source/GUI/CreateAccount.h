#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <wx/wx.h>


class CreateAccount : public wxPanel
{
public:
	CreateAccount(wxFrame* parent);
	wxButton *createProfile;
	wxButton *cancel;
	void display();
	void hide();
	void OnOpen(wxCommandEvent& event);

};

enum
{
	BUTTON_cancel = wxID_HIGHEST + 1,
	BUTTON_createProfile = wxID_HIGHEST + 2
};
#endif