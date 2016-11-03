///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GAMEOVER_H__
#define __GAMEOVER_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

//#define game_over 1000
//#define gameOver 1001
//#define win_lose 1002
//#define p1_score 1003
//#define p2_score 1004
//#define p3_score 1005
//#define p4_score 1006
//#define play_again 1007
//#define main_menu 1008

///////////////////////////////////////////////////////////////////////////////
/// Class gameOver
///////////////////////////////////////////////////////////////////////////////
class gameOver : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* GameOverMessage;
		wxStaticText* Win_Lose;
		wxStaticText* P1_Score;
		wxStaticText* P2_Score;
		wxStaticText* P3_Score;
		wxStaticText* P4_Score;
		wxButton* PlayAgain;
		wxButton* MainMenu;
	
	public:
		
		gameOver( wxWindow* parent, wxWindowID id = game_over, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~gameOver();
	
};

#endif //__GAMEOVER_H__
