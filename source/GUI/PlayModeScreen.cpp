#include <wx/wx.h>
#include <wx/sizer.h>
#include "PlayModeScreen.h"

PlayModeScreen::PlayModeScreen(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{

	wxFlexGridSizer *verticalBox = new wxFlexGridSizer(3, 0, 10, 10);

	wxBoxSizer *horizontalBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *horizontalBox2 = new wxBoxSizer(wxHORIZONTAL);

	hearts = new wxButton(this, BUTTON_Hearts, _T("Hearts"), wxDefaultPosition, wxSize(140, 30));
	spades = new wxButton(this, BUTTON_Spades, _T("Spades"), wxDefaultPosition, wxSize(140, 30));
	crazyEights = new wxButton(this, BUTTON_Eights, _T("Crazy Eights"), wxDefaultPosition, wxSize(140, 30));
	modeCancel = new wxButton(this, BUTTON_modeCancel, _T("Cancel"), wxDefaultPosition, wxSize(140, 30));
	::wxInitAllImageHandlers();
	test1.LoadFile("C:/Users/dozek/Desktop/cards/2_of_hearts.png", wxBITMAP_TYPE_PNG);
	test2 = new wxBitmapButton(this, BUTTON_test, test1, wxDefaultPosition, wxSize(140, 196), wxBU_EXACTFIT);

	horizontalBox->Add(hearts, wxCENTER, 0);
	horizontalBox->Add(spades, wxCENTER, 0);
	horizontalBox->Add(crazyEights, wxCENTER, 0);
	horizontalBox2->Add(modeCancel, wxCENTER, 0);
	horizontalBox2->Add(test2, wxCENTER, 0);

	verticalBox->Add(horizontalBox, wxCENTER, 0);
	verticalBox->Add(horizontalBox2, wxCENTER, 0);


	SetSizerAndFit(verticalBox);

	CenterOnParent();
	Show(0);
}

void PlayModeScreen::display()
{
	Show(1);

}

void PlayModeScreen::hide()
{
	Show(0);
}
