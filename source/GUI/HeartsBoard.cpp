#include <wx/wx.h>
#include <wx/sizer.h>
#include "HeartsBoard.hpp"

HeartsBoard::HeartsBoard(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition,
	wxSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X)*.5, wxSystemSettings::GetMetric(wxSYS_SCREEN_Y)*.5), wxTAB_TRAVERSAL, wxPanelNameStr)
{
	//Sizers
	wxFlexGridSizer *verticalBoxMain = new wxFlexGridSizer(3, 0, 20, 20);
	wxBoxSizer *horizontalBoxBtm = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *horizontalBoxMid = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *horizontalBoxTop = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *verticalBoxLeft = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *verticalBoxCenter = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *verticalBoxRight = new wxBoxSizer(wxVERTICAL);

	wxFlexGridSizer *horizontalBoxCenter = new wxFlexGridSizer(2, 2, 10, 10);

	//Images used to scale the Bitmap
	wxImage pc;
	wxImage pct;
	wxImage pcs;
	wxImage dc;
	wxBitmap defaultColor;
	wxBitmap playerHandTop;
	wxBitmap playerHandSide;

	defaultColor.LoadFile("../../../../CS3450/Resources/cards/blank.jpg", wxBITMAP_TYPE_JPEG);
	dc = defaultColor.ConvertToImage();
	defaultColor = wxBitmap(dc.Scale(63, 91));

	playerHandTop.LoadFile("../../../../CS3450/Resources/cards/card_back.jpg", wxBITMAP_TYPE_JPEG);
	pct = playerHandTop.ConvertToImage();

	playerHandSide.LoadFile("../../../../CS3450/Resources/cards/card_back_side.jpg", wxBITMAP_TYPE_JPEG);
	pcs = playerHandSide.ConvertToImage();

	//Initializes card images and buttons
	::wxInitAllImageHandlers();
	std::string cardNum;

	for (int i = 0; i < 13; i++)
	{
		/*This uses a hardcoded path for the card images I used.
		* If you can find a way to make this a relative path
		* (or when Michael adds the card images to link it to those,)
		* uncomment this and replace accordingly.
		*/
		cardNum = "../../../../CS3450/Resources/cards/" + std::to_string(i + 1) + "c.png";
		//cardNum = "../cards/2c.png";
		p1Cards[i].LoadFile(cardNum, wxBITMAP_TYPE_PNG);
		pc = p1Cards[i].ConvertToImage();
		p1Cards[i] = wxBitmap(pc.Scale(63, 91));
		p1Hand[i] = new wxBitmapButton(this, BUTTON_CARD1 + i, p1Cards[i], wxDefaultPosition, wxSize(63, 91), 0);

		p2Cards[i] = wxBitmap(pcs.Scale(72, 50));
		p2Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER, p2Cards[i], wxDefaultPosition, wxSize(72, 25), 0);

		p3Cards[i] = wxBitmap(pct.Scale(50, 72));
		p3Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER2, p3Cards[i], wxDefaultPosition, wxSize(50, 72), 0);

		p4Cards[i] = wxBitmap(pcs.Scale(72, 50));
		p4Hand[i] = new wxBitmapButton(this, BUTTON_CARD_OTHER, p4Cards[i], wxDefaultPosition, wxSize(72, 25), 0);


		//Add bitmap buttons to the sizers
		horizontalBoxBtm->Add(p1Hand[i], wxCENTER, 0);
		verticalBoxLeft->Add(p2Hand[i], wxCENTER, 0);
		verticalBoxRight->Add(p4Hand[i], wxCENTER, 0);
		horizontalBoxTop->Add(p3Hand[i], wxCENTER, 0);

	}

	//Generate the center pile (need to fix the size issue)
	for (int i = 0; i < 4; i++) {
		centerPile[i] = new wxBitmapButton(this, BUTTON_CARD_CENTER + i, defaultColor, wxDefaultPosition, wxSize(63, 91), 0);
		horizontalBoxCenter->Add(centerPile[i], wxCENTER, 0);
	}

	horizontalBoxMid->Add(verticalBoxLeft, wxALIGN_LEFT, 0);
	horizontalBoxMid->Add(horizontalBoxCenter, wxALIGN_CENTER, 0);
	horizontalBoxMid->Add(verticalBoxRight, wxALIGN_RIGHT, 0);
	verticalBoxMain->Add(horizontalBoxTop, wxCENTER, 0);
	verticalBoxMain->Add(horizontalBoxMid, wxCENTER, 0);
	verticalBoxMain->Add(horizontalBoxBtm, wxCENTER, 0);

	SetSizerAndFit(verticalBoxMain);

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