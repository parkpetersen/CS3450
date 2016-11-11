// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include "PlayModeScreen.hpp"
#include "GameOver.hpp"
#include "LoginScreen.hpp"
#include "CreateAccount.hpp"
#include "HeartsBoard.hpp"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  login *loginScreen;
  CreateAccount *createAccountScreen;
  PlayModeScreen *modeScreen;
  HeartsBoard *heartsBoard;
  GameOver *gameOver;

private:
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnCreateAccount(wxCommandEvent& event);
  void OnCreateCancel(wxCommandEvent& event);
  void OnLogin(wxCommandEvent& event);
  void OnModeHearts(wxCommandEvent& event);
  void OnModeCancel(wxCommandEvent& event);
  void OnHearts(wxCommandEvent& event);
  void OnSpades(wxCommandEvent& event);
  void OnTest(wxCommandEvent& event);
  void OnPlayAgain(wxCommandEvent& event);
  void OnMainMenu(wxCommandEvent& event);
  wxDECLARE_EVENT_TABLE();
};
enum
{
	ID_Hello = 1,
	BUTTON_Hello = 2
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_BUTTON(BUTTON_Hello, MyFrame::OnExit)            //Event table tells buttons what to do when pressed
EVT_BUTTON(BUTTON_exit, MyFrame::OnExit)
EVT_BUTTON(BUTTON_create, MyFrame::OnCreateAccount)
EVT_BUTTON(BUTTON_cancel, MyFrame::OnCreateCancel)
EVT_BUTTON(BUTTON_createProfile, MyFrame::OnCreateCancel)
EVT_BUTTON(BUTTON_modeCancel, MyFrame::OnModeCancel)
EVT_BUTTON(BUTTON_Hearts, MyFrame::OnHearts)
EVT_BUTTON(BUTTON_Spades, MyFrame::OnSpades)
EVT_BUTTON(BUTTON_test, MyFrame::OnTest)
EVT_BUTTON(BUTTON_login, MyFrame::OnLogin)
EVT_BUTTON(BUTTON_playAgain, MyFrame::OnPlayAgain)
EVT_BUTTON(BUTTON_mainMenu, MyFrame::OnMainMenu)
EVT_BUTTON(BUTTON_CARD1, MyFrame::OnHearts)
EVT_BUTTON(BUTTON_CARD_OTHER, MyFrame::OnHearts)

wxEND_EVENT_TABLE()
IMPLEMENT_APP_NO_MAIN(MyApp)
bool MyApp::OnInit()
{
  MyFrame *frame = new MyFrame("Card Games", wxPoint(50, 50), wxSize(850, 700));
  frame->SetBackgroundColour(wxColour(40,150,40));
  
  frame->Show(true);
  return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    "Welcome to Deal 52!");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");
  SetMenuBar(menuBar);
  CreateStatusBar();
  SetStatusText("Welcome to Deal 52!");
  loginScreen = new login(this);
  createAccountScreen = new CreateAccount(this); 
  modeScreen = new PlayModeScreen(this);
  heartsBoard = new HeartsBoard(this);
  gameOver = new GameOver(this);
  loginScreen->display();


}
void MyFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
  wxMessageBox("Choose between three of the funnest card games!",
    "About Deal 52", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
  wxLogMessage("Welcome to Deal 52!");
}

void MyFrame::OnCreateAccount(wxCommandEvent& event)
{
	loginScreen->hide();
	createAccountScreen->display();

}

void MyFrame::OnCreateCancel(wxCommandEvent& event)
{
	createAccountScreen->hide();
	loginScreen->display();
}

void MyFrame::OnLogin(wxCommandEvent& event)
{
	loginScreen->hide();
	modeScreen->display();
}

void MyFrame::OnModeCancel(wxCommandEvent& event)
{
	modeScreen->hide();
	loginScreen->display();
}

void MyFrame::OnHearts(wxCommandEvent& event)
{
	modeScreen->hide();
	heartsBoard->display();
}

void MyFrame::OnSpades(wxCommandEvent& event)
{
	modeScreen->hide();
	gameOver->display();
}

void MyFrame::OnTest(wxCommandEvent& event)
{
	modeScreen->hide();
	gameOver->display();
}

void MyFrame::OnPlayAgain(wxCommandEvent& event)
{
	gameOver->hide();
	modeScreen->display();
}

void MyFrame::OnMainMenu(wxCommandEvent& event)
{
	gameOver->hide();
	modeScreen->display();
}

int main(int argc, char* argv[])
{
  wxApp* pApp = new MyApp();
  wxApp::SetInstance(pApp);
  wxEntry(argc, argv);
}