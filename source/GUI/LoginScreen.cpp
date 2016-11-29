#include <wx/wx.h>
#include <wx/sizer.h>
#include "LoginScreen.hpp"

login::login(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	verticalBox = new wxFlexGridSizer(3, 0, 10, 10);
	horizontalBox = new wxBoxSizer(wxHORIZONTAL);
	horizontalBoxTwo = new wxBoxSizer(wxHORIZONTAL);


	exit = new wxButton(this, BUTTON_exit, _T("Exit"),wxDefaultPosition, wxSize(140, 30));
	create = new wxButton(this, BUTTON_create, _T("Create Account"),wxDefaultPosition, wxSize(140, 30));
	loginBtn = new wxButton(this, BUTTON_login, _T("Login"), wxDefaultPosition, wxSize(140, 30));

	horizontalBox->Add(exit, wxCENTER, 0);
	horizontalBox->Add(loginBtn, wxCENTER, 0);
	horizontalBox->Add(create, wxCENTER, 0);

	userNameTxt = new wxTextCtrl(this, 0, "UserName", wxDefaultPosition,
		wxSize(140, 30));
	passwordTxt = new wxTextCtrl(this, 0, "Password", wxDefaultPosition,
		wxSize(140, 30));

	horizontalBoxTwo->Add(userNameTxt, wxCENTER, 0);
	horizontalBoxTwo->Add(passwordTxt, wxCENTER, 0);
	//horizontalBoxTwo->Add(new wxTextCtrl(this, 0, "Password", wxDefaultPosition,
		//wxSize(140, 30)), 1, wxCENTER, 0);

	verticalBox->Add(horizontalBoxTwo, wxCENTER, 0);
	verticalBox->Add(horizontalBox, wxCENTER, 0);



	SetSizerAndFit(verticalBox);
	CenterOnParent();
	Show(0);
}



void login::display()
{
	Show(1);

}

void login::hide()
{
	Show(0);
}

bool login::getInput()
{
	std::string username;
	std::string password;
	username = userNameTxt->GetLineText(0);
	password = passwordTxt->GetLineText(0);
	std::cout << username << std::endl;
	std::cout << password << std::endl;
	if (checkLogin(username, password))
	{
		std::cout << "Correct Login!\n";
		return true;
	}
	else
	{
		std::cout << "Bad Login\n";
		wxMessageBox(wxT("Incorrect login information. Please try again"), wxT("Login Error"), wxICON_ERROR);
		return false;
	}

}

bool login::checkLogin(std::string un, std::string pw)
{
	//std::ifstream read("C:\\Users\\dozek\\Desktop\\" + un + ".txt");
	std::ifstream read("../../../../CS3450/Resources/data/" + un + ".txt");
	std::string username;
	std::string password;

	std::getline(read, username);
	std::getline(read, password);

	if (username == un && password == pw)
	{
		return true;
	}
	else
	{
		return false;
	}
}