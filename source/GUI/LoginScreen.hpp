#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <wx/wx.h>
#include <string>
#include <fstream>

class login : public wxPanel
{
public:
	wxButton *exit;
	wxButton *create;
	wxButton *loginBtn;
	login(wxFrame* parent);
	void display();
	void hide();
	bool getInput();
	bool checkLogin(std::string un, std::string pw);
	wxFlexGridSizer *verticalBox;
	wxBoxSizer *horizontalBox;
	wxBoxSizer *horizontalBoxTwo;

	wxTextCtrl *userNameTxt;
	wxTextCtrl *passwordTxt;
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