#include <wx/wx.h>
#include <wx/sizer.h>
#include "GameOver.hpp"

GameOver::GameOver(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	wxFlexGridSizer *verticalBox = new wxFlexGridSizer(3, 0, 10, 10);
	wxBoxSizer *horizontalBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *horizontalBoxTwo = new wxBoxSizer(wxHORIZONTAL);
	wxGridSizer *gridBox = new wxGridSizer(2, 2, 3, 3);


	mainMenu = new wxButton(this, BUTTON_mainMenu, _T("Main Menu"), wxDefaultPosition, wxSize(140, 30));
	playAgain = new wxButton(this, BUTTON_playAgain, _T("Play Again"), wxDefaultPosition, wxSize(140, 30));

	horizontalBox->Add(mainMenu, wxCENTER, 0);
	horizontalBox->Add(playAgain, wxCENTER, 0);

	horizontalBoxTwo->Add(new wxStaticText(this, 0, "Game Over! You Win/Lose!!", wxDefaultPosition,
		wxSize(240, 30)), 1, wxCENTER, 0);

	gridBox->Add(new wxStaticText(this, 0, "Player 1 Score", wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Add(new wxStaticText(this, 0, "Player 2 Score", wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Add(new wxStaticText(this, 0, "Player 3 Score", wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);
	gridBox->Add(new wxStaticText(this, 0, "Player 4 Score", wxDefaultPosition,
		wxSize(140, 30)), 1, wxCENTER, 0);

	verticalBox->Add(horizontalBoxTwo, wxCENTER, 0);
	verticalBox->Add(gridBox, wxCENTER, 0);
	verticalBox->Add(horizontalBox, wxCENTER, 0);



	SetSizerAndFit(verticalBox);
	CenterOnParent();
	Show(0);
}

void GameOver::display()
{
	Show(1);

}

void GameOver::hide()
{
	Show(0);
}
