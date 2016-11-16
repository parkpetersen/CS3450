#include <wx/wx.h>
#include <wx/sizer.h>
#include "CreateAccount.hpp"

CreateAccount::CreateAccount(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	wxFlexGridSizer *verticalBox = new wxFlexGridSizer(3, 0, 10, 10);
	wxBoxSizer *horizontalBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *horizontalBoxTwo = new wxBoxSizer(wxHORIZONTAL);


	cancel = new wxButton(this, BUTTON_cancel, _T("Cancel"), wxDefaultPosition, wxSize(140, 30));
	createProfile = new wxButton(this, BUTTON_createProfile, _T("Create Account"), wxDefaultPosition, wxSize(140, 30));

	horizontalBox->Add(cancel, wxCENTER, 0);
	horizontalBox->Add(createProfile, wxCENTER, 0);

	userNameTxt = new wxTextCtrl(this, 0, "Username", wxDefaultPosition,
		wxSize(140, 30));
	passwordTxt = new wxTextCtrl(this, 0, "Password", wxDefaultPosition,
		wxSize(140, 30));

	horizontalBoxTwo->Add(userNameTxt, 1, wxCENTER, 0);
	horizontalBoxTwo->Add(passwordTxt, 1, wxCENTER, 0);

	verticalBox->Add(horizontalBoxTwo, wxCENTER, 0);
	verticalBox->Add(horizontalBox, wxCENTER, 0);



	SetSizerAndFit(verticalBox);
	CenterOnParent();
	Show(0);
}

void CreateAccount::display()
{
	Show(1);

}

void CreateAccount::hide()
{
	Show(0);
}

void CreateAccount::getInput()
{
	std::string username;
	std::string password;
	username = userNameTxt->GetLineText(0);
	password = passwordTxt->GetLineText(0);
	std::cout << username << std::endl;
	std::cout << password << std::endl;

}