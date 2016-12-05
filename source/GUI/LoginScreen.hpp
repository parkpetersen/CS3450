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
	void setLogin(std::string &intro);
	wxFlexGridSizer *verticalBox;
	wxBoxSizer *horizontalBox;
	wxBoxSizer *horizontalBoxTwo;

	std::string username;
	std::string password;
	std::string temp;
	std::string heartWin;
	std::string heartLose;
	std::string spadeWin;
	std::string spadeLose;
	std::string allWin;
	std::string allLose;

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