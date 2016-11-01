//#include <wx/wx.h>
//#include <wx/sizer.h>
//#include "CreateAccount.h"
//
//CreateAccount::CreateAccount(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
//	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
//{
//	wxFlexGridSizer *verticalBox = new wxFlexGridSizer(3, 0, 10, 10);
//	wxBoxSizer *horizontalBox = new wxBoxSizer(wxHORIZONTAL);
//	wxBoxSizer *horizontalBoxTwo = new wxBoxSizer(wxHORIZONTAL);
//
//
//	wxButton *login = new wxButton(this, wxID_ANY, _T("Login"), wxDefaultPosition, wxSize(140, 30));
//	wxButton *create = new wxButton(this, wxID_ANY, _T("Create Account"), wxDefaultPosition, wxSize(140, 30));
//
//	horizontalBox->Add(login, wxCENTER, 0);
//	horizontalBox->Add(create, wxCENTER, 0);
//
//	horizontalBoxTwo->Add(new wxTextCtrl(this, 0, "Login", wxDefaultPosition,
//		wxSize(140, 30)), 1, wxCENTER, 0);
//	horizontalBoxTwo->Add(new wxTextCtrl(this, 0, "Password", wxDefaultPosition,
//		wxSize(140, 30)), 1, wxCENTER, 0);
//
//	verticalBox->Add(horizontalBoxTwo, wxCENTER, 0);
//	verticalBox->Add(horizontalBox, wxCENTER, 0);
//
//
//
//	SetSizerAndFit(verticalBox);
//	CenterOnParent();
//	Show(0);
//}
//
//void login::display()
//{
//	Show(1);
//
//}
