#include <wx/wx.h>
#include <wx/sizer.h>
#include "LoginScreen.hpp"
#include <string>

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

void login::getInput()
{
	std::string username;
	std::string password;
	username = userNameTxt->GetLineText(0);
	password = passwordTxt->GetLineText(0);
	std::cout<<username<<std::endl;
	std::cout << password<<std::endl;
	

}