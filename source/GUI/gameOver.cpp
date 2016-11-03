///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gameOver.h"

///////////////////////////////////////////////////////////////////////////

gameOver::gameOver( wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	GameOverMessage = new wxStaticText( this, gameOver, wxT("Game Over!"), wxPoint( -1,-1 ), wxSize( -1,-1 ), wxALIGN_CENTRE );
	GameOverMessage->Wrap( -1 );
	GameOverMessage->SetFont( wxFont( 18, 74, 90, 92, false, wxT("Arial") ) );
	
	bSizer1->Add( GameOverMessage, 0, wxALL, 5 );
	
	Win_Lose = new wxStaticText( this, win_lose, wxT("You Win or Lose!"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	Win_Lose->Wrap( -1 );
	Win_Lose->SetFont( wxFont( 14, 74, 90, 92, false, wxT("Arial") ) );
	
	bSizer1->Add( Win_Lose, 0, wxALL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	P1_Score = new wxStaticText( this, p1_score, wxT("Player 1 Score: "), wxDefaultPosition, wxDefaultSize, 0 );
	P1_Score->Wrap( -1 );
	gSizer1->Add( P1_Score, 0, wxALL, 5 );
	
	P2_Score = new wxStaticText( this, p2_score, wxT("Player 2 Score:"), wxDefaultPosition, wxDefaultSize, 0 );
	P2_Score->Wrap( -1 );
	gSizer1->Add( P2_Score, 0, wxALL, 5 );
	
	P3_Score = new wxStaticText( this, p3_score, wxT("Player 3 Score: "), wxDefaultPosition, wxDefaultSize, 0 );
	P3_Score->Wrap( -1 );
	gSizer1->Add( P3_Score, 0, wxALL, 5 );
	
	P4_Score = new wxStaticText( this, p4_score, wxT("Player 4 Score: "), wxDefaultPosition, wxDefaultSize, 0 );
	P4_Score->Wrap( -1 );
	gSizer1->Add( P4_Score, 0, wxALL, 5 );
	
	
	bSizer1->Add( gSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	PlayAgain = new wxButton( this, play_again, wxT("Play Again"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( PlayAgain, 0, wxALL, 5 );
	
	MainMenu = new wxButton( this, main_menu, wxT("Main Menu"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( MainMenu, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

gameOver::~gameOver()
{
}
