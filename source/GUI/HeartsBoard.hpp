#ifndef HEARTSBOARD_HPP
#define HEARTSBOARD_HPP

#include <wx/wx.h>
#include <vector>


class HeartsBoard : public wxPanel
{
public:
	HeartsBoard(wxFrame* parent);
	
	//Bitmap images (should be vectors)
	wxBitmap p1Cards[13];
	/*wxBitmap p2Cards[13];
	wxBitmap p3Cards[13];
	wxBitmap p4Cards[13];*/

	//Bitmap buttons (should be vectors)
	wxBitmapButton *p1Hand[13];
	//wxBitmapButton *p2Hand[13];
	//wxBitmapButton *p3Hand[13];
	//wxBitmapButton *p4Hand[13];

	void display();
	void hide();

};

enum
{
	BUTTON_Card = wxID_HIGHEST + 13
};
#endif
