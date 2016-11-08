#ifndef CREATEACCOUNT_HPP
#define CREATEACCOUNT_HPP

#include <wx/wx.h>


class CreateAccount : public wxPanel
{
public:
	CreateAccount(wxFrame* parent);
	wxButton *createProfile;
	wxButton *cancel;
	void display();
	void hide();

};

enum
{
	BUTTON_cancel = wxID_HIGHEST + 4,
	BUTTON_createProfile = wxID_HIGHEST + 5
};
#endif