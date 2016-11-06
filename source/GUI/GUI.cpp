// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include "PlayModeScreen.h"
<<<<<<< HEAD
#include "LoginScreen.h"
#include "CreateAccount.h"
#include "GameOver.h"

=======

#include "LoginScreen.h"
#include "CreateAccount.h"
>>>>>>> refs/remotes/michaelkamerath/master
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
<<<<<<< HEAD
  GameOver *gameOver;

=======
>>>>>>> refs/remotes/michaelkamerath/master

private:
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnCreateAccount(wxCommandEvent& event);
  void OnCreateCancel(wxCommandEvent& event);
  void OnLogin(wxCommandEvent& event);
<<<<<<< HEAD
  void OnModeHearts(wxCommandEvent& event);
  void OnModeCancel(wxCommandEvent& event);
  void OnMainMenu(wxCommandEvent& event);
  void OnPlayAgain(wxCommandEvent& event);
=======
  void OnModeCancel(wxCommandEvent& event);
>>>>>>> refs/remotes/michaelkamerath/master
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
<<<<<<< HEAD
EVT_BUTTON(BUTTON_Hearts, MyFrame::OnModeHearts)
EVT_BUTTON(BUTTON_modeCancel, MyFrame::OnModeCancel)
EVT_BUTTON(BUTTON_login, MyFrame::OnLogin)
EVT_BUTTON(BUTTON_mainMenu, MyFrame::OnMainMenu)
EVT_BUTTON(BUTTON_playAgain, MyFrame::OnPlayAgain)
=======
EVT_BUTTON(BUTTON_modeCancel, MyFrame::OnModeCancel)
EVT_BUTTON(BUTTON_login, MyFrame::OnLogin)
>>>>>>> refs/remotes/michaelkamerath/master
wxEND_EVENT_TABLE()
IMPLEMENT_APP_NO_MAIN(MyApp)
bool MyApp::OnInit()
{
<<<<<<< HEAD
  MyFrame *frame = new MyFrame("Card Games", wxPoint(50, 50), wxSize(450, 340));
=======
  MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
>>>>>>> refs/remotes/michaelkamerath/master
  
  frame->Show(true);
  return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");
  SetMenuBar(menuBar);
  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");
  loginScreen = new login(this);
  createAccountScreen = new CreateAccount(this);
  modeScreen = new PlayModeScreen(this);
<<<<<<< HEAD
  gameOver = new GameOver(this);
=======
>>>>>>> refs/remotes/michaelkamerath/master
  loginScreen->display();


}
void MyFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
  wxMessageBox("This is a wxWidgets' Hello world sample",
    "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
  wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnCreateAccount(wxCommandEvent& event)
{
	loginScreen->hide();
	createAccountScreen->display();

<<<<<<< HEAD
=======

>>>>>>> refs/remotes/michaelkamerath/master
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

<<<<<<< HEAD
void MyFrame::OnModeHearts(wxCommandEvent& event)
{
	modeScreen->hide();
	//Replace with hearts game display when available
	//This one should be connected to the game board
	gameOver->display();

}

=======
>>>>>>> refs/remotes/michaelkamerath/master
void MyFrame::OnModeCancel(wxCommandEvent& event)
{
	modeScreen->hide();
	loginScreen->display();
}

<<<<<<< HEAD
void MyFrame::OnMainMenu(wxCommandEvent& event)
{
	gameOver->hide();
	modeScreen->display();

}

void MyFrame::OnPlayAgain(wxCommandEvent& event)
{
	gameOver->hide();
	modeScreen->display();


}

=======
>>>>>>> refs/remotes/michaelkamerath/master


int main(int argc, char* argv[])
{
  wxApp* pApp = new MyApp();
  wxApp::SetInstance(pApp);
  wxEntry(argc, argv);
}