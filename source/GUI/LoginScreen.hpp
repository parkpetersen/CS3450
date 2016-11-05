#ifndef LOGIN_H
#define LOGIN_H

#include <wx/wx.h>


class login : public wxPanel
{
public:
	wxButton *exit;
	wxButton *create;
	wxButton *loginBtn;
	login(wxFrame* parent);
	void display();
	void hide();
	//void onCreate(wxCommandEvent& event);
	//~login();

};

enum
{
	BUTTON_login = wxID_HIGHEST + 1,
	BUTTON_exit = wxID_HIGHEST + 2,
	BUTTON_create = wxID_HIGHEST + 3
};
#endif