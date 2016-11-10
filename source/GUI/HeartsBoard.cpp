#include <wx/wx.h>
#include <wx/sizer.h>
#include "HeartsBoard.hpp"

HeartsBoard::HeartsBoard(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	//Sizers
	wxFlexGridSizer *verticalBox = new wxFlexGridSizer(3, 0, 10, 10);
	wxBoxSizer *horizontalBox = new wxBoxSizer(wxHORIZONTAL);
	//wxBoxSizer *horizontalBox2 = new wxBoxSizer(wxHORIZONTAL);

	//Image used to scale the Bitmap
	wxImage p1c;
	
	//Initializes card images and buttons
	::wxInitAllImageHandlers();
	std::string cardNum;
	for (int i = 0; i < 13; i++)
	{
		cardNum = "../../../../CS3450/Resources/cards/" + std::to_string(i + 1) + "c.png";
		p1Cards[i].LoadFile(cardNum, wxBITMAP_TYPE_PNG);
		p1c = p1Cards[i].ConvertToImage();
		p1Cards[i] = wxBitmap(p1c.Scale(63, 91));

		p1Hand[i] = new wxBitmapButton(this, BUTTON_Card + i, p1Cards[i], wxDefaultPosition, wxSize(63, 91), 0);
		horizontalBox->Add(p1Hand[i], wxCENTER, 0);
	}


	verticalBox->Add(horizontalBox, wxBOTTOM, 0);
	//verticalBox->Add(horizontalBox2, wxCENTER, 0);

	SetSizerAndFit(verticalBox);

	CenterOnParent();
	Show(0);

}

void HeartsBoard::display()
{
	Show(1);

}

void HeartsBoard::hide()
{
	Show(0);
}