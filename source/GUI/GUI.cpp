// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#include "PlayModeScreen.hpp"
#include "GameOver.hpp"
#include "LoginScreen.hpp"
#include "CreateAccount.hpp"
#include "HeartsBoard.hpp"
#include "SpadesBoard.hpp"


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
  SpadesBoard *spadesBoard;
  std::string introMessage = "Welcome to Deal52, please log in.";

private:
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnCreateAccount(wxCommandEvent& event);
  void OnCreateNewProfile(wxCommandEvent& event);
  void OnCreateCancel(wxCommandEvent& event);
  void OnLogin(wxCommandEvent& event);
  void OnModeCancel(wxCommandEvent& event);
  void OnHearts(wxCommandEvent& event);
  void OnSpades(wxCommandEvent& event);
  void OnTest(wxCommandEvent& event);
  void OnPlayAgain(wxCommandEvent& event);
  void OnMainMenu(wxCommandEvent& event);

  void OnCard0(wxCommandEvent& event);
  void OnCard1(wxCommandEvent& event);
  void OnCard2(wxCommandEvent& event);
  void OnCard3(wxCommandEvent& event);
  void OnCard4(wxCommandEvent& event);
  void OnCard5(wxCommandEvent& event);
  void OnCard6(wxCommandEvent& event);
  void OnCard7(wxCommandEvent& event);
  void OnCard8(wxCommandEvent& event);
  void OnCard9(wxCommandEvent& event);
  void OnCard10(wxCommandEvent& event);
  void OnCard11(wxCommandEvent& event);
  void OnCard12(wxCommandEvent& event);
  void OnCard0_SPADES(wxCommandEvent& event);
  void OnCard1_SPADES(wxCommandEvent& event);
  void OnCard2_SPADES(wxCommandEvent& event);
  void OnCard3_SPADES(wxCommandEvent& event);
  void OnCard4_SPADES(wxCommandEvent& event);
  void OnCard5_SPADES(wxCommandEvent& event);
  void OnCard6_SPADES(wxCommandEvent& event);
  void OnCard7_SPADES(wxCommandEvent& event);
  void OnCard8_SPADES(wxCommandEvent& event);
  void OnCard9_SPADES(wxCommandEvent& event);
  void OnCard10_SPADES(wxCommandEvent& event);
  void OnCard11_SPADES(wxCommandEvent& event);
  void OnCard12_SPADES(wxCommandEvent& event);
  void OnBid(wxCommandEvent& event);
  void OnReturnButtonHearts(wxCommandEvent& event);
  void OnReturnButtonSpades(wxCommandEvent& event);

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
EVT_BUTTON(BUTTON_modeCancel, MyFrame::OnModeCancel)
EVT_BUTTON(BUTTON_createProfile, MyFrame::OnCreateNewProfile)

EVT_BUTTON(BUTTON_Hearts, MyFrame::OnHearts)
EVT_BUTTON(BUTTON_Spades, MyFrame::OnSpades)
EVT_BUTTON(BUTTON_test, MyFrame::OnTest)
EVT_BUTTON(BUTTON_login, MyFrame::OnLogin)
EVT_BUTTON(BUTTON_playAgain, MyFrame::OnPlayAgain)

EVT_BUTTON(BUTTON_mainMenu, MyFrame::OnMainMenu)
EVT_BUTTON(BUTTON_CARD1 + 0, MyFrame::OnCard0)
EVT_BUTTON(BUTTON_CARD1 + 1, MyFrame::OnCard1)
EVT_BUTTON(BUTTON_CARD1 + 2, MyFrame::OnCard2)
EVT_BUTTON(BUTTON_CARD1 + 3, MyFrame::OnCard3)
EVT_BUTTON(BUTTON_CARD1 + 4, MyFrame::OnCard4)
EVT_BUTTON(BUTTON_CARD1 + 5, MyFrame::OnCard5)
EVT_BUTTON(BUTTON_CARD1 + 6, MyFrame::OnCard6)
EVT_BUTTON(BUTTON_CARD1 + 7, MyFrame::OnCard7)
EVT_BUTTON(BUTTON_CARD1 + 8, MyFrame::OnCard8)
EVT_BUTTON(BUTTON_CARD1 + 9, MyFrame::OnCard9)
EVT_BUTTON(BUTTON_CARD1 + 10, MyFrame::OnCard10)
EVT_BUTTON(BUTTON_CARD1 + 11, MyFrame::OnCard11)
EVT_BUTTON(BUTTON_CARD1 + 12, MyFrame::OnCard12)
EVT_BUTTON(wxID_HIGHEST + 51, MyFrame::OnExit)
EVT_BUTTON(BUTTON_CARD1_SPADES + 0, MyFrame::OnCard0_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 1, MyFrame::OnCard1_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 2, MyFrame::OnCard2_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 3, MyFrame::OnCard3_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 4, MyFrame::OnCard4_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 5, MyFrame::OnCard5_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 6, MyFrame::OnCard6_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 7, MyFrame::OnCard7_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 8, MyFrame::OnCard8_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 9, MyFrame::OnCard9_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 10, MyFrame::OnCard10_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 11, MyFrame::OnCard11_SPADES)
EVT_BUTTON(BUTTON_CARD1_SPADES + 12, MyFrame::OnCard12_SPADES)
EVT_BUTTON(BUTTON_RETURN_BUTTON_SPADES, MyFrame::OnExit)
EVT_BUTTON(BUTTON_BID, MyFrame::OnBid)


//EVT_BUTTON(BUTTON_CARD_OTHER, MyFrame::OnHearts)

wxEND_EVENT_TABLE()
IMPLEMENT_APP_NO_MAIN(MyApp)
bool MyApp::OnInit()
{
  MyFrame *frame = new MyFrame("Card Games", wxPoint(50, 50), wxSize(1000, 700));
  frame->SetBackgroundColour(wxColour(40,150,40));
  
  frame->Show(true);
  return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Player Statistics...\tCtrl-H",
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
  SetStatusText("Welcome to wxWidgets!");
  loginScreen = new login(this);
  createAccountScreen = new CreateAccount(this);
  modeScreen = new PlayModeScreen(this);

  heartsBoard = new HeartsBoard(this);
  gameOver = new GameOver(this);
  spadesBoard = new SpadesBoard(this);
  loginScreen->display();


}
void MyFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
  wxMessageBox("Deal52 designed for CS3450 class\n\nCreated by Michael Kamerath, Parker Petersen,\n David Helmick, and Nic Biggs!",
    "About Deal 52", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxMessageBox(introMessage,
		"Welcome to Deal52", wxOK | wxICON_INFORMATION);

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

void MyFrame::OnCreateNewProfile(wxCommandEvent& event)
{
	createAccountScreen->getInput();
	createAccountScreen->hide();
	loginScreen->display();
}

void MyFrame::OnLogin(wxCommandEvent& event)
{
	if (loginScreen->getInput())
	{
		loginScreen->setLogin(introMessage);
		loginScreen->hide();
		modeScreen->display();
	}
}

void MyFrame::OnModeCancel(wxCommandEvent& event)
{
	introMessage = "Welcome to Deal52, please log in.";
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
	spadesBoard->display();
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

void MyFrame::OnCard0(wxCommandEvent & event)
{
	int i = 0;
	heartsBoard->cardClick(i);
}

void MyFrame::OnCard1(wxCommandEvent & event)
{
	int i = 1;
	heartsBoard->cardClick(i);
}

void MyFrame::OnCard2(wxCommandEvent & event)
{
	int i = 2;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard3(wxCommandEvent & event)
{
	int i = 3;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard4(wxCommandEvent & event)
{
	int i = 4;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard5(wxCommandEvent & event)
{
	int i = 5;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard6(wxCommandEvent & event)
{
	int i = 6;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard7(wxCommandEvent & event)
{
	int i = 7;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard8(wxCommandEvent & event)
{
	int i = 8;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard9(wxCommandEvent & event)
{
	int i = 9;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard10(wxCommandEvent & event)
{
	int i = 10;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard11(wxCommandEvent & event)
{
	int i = 11;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard12(wxCommandEvent & event)
{
	int i = 12;
	heartsBoard->cardClick(i);

}

void MyFrame::OnCard0_SPADES(wxCommandEvent & event)
{
	int i = 0;
	spadesBoard->cardClick(i);
}

void MyFrame::OnCard1_SPADES(wxCommandEvent & event)
{
	int i = 1;
	spadesBoard->cardClick(i);
}

void MyFrame::OnCard2_SPADES(wxCommandEvent & event)
{
	int i = 2;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard3_SPADES(wxCommandEvent & event)
{
	int i = 3;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard4_SPADES(wxCommandEvent & event)
{
	int i = 4;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard5_SPADES(wxCommandEvent & event)
{
	int i = 5;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard6_SPADES(wxCommandEvent & event)
{
	int i = 6;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard7_SPADES(wxCommandEvent & event)
{
	int i = 7;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard8_SPADES(wxCommandEvent & event)
{
	int i = 8;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard9_SPADES(wxCommandEvent & event)
{
	int i = 9;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard10_SPADES(wxCommandEvent & event)
{
	int i = 10;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard11_SPADES(wxCommandEvent & event)
{
	int i = 11;
	spadesBoard->cardClick(i);

}

void MyFrame::OnCard12_SPADES(wxCommandEvent & event)
{
	int i = 12;
	spadesBoard->cardClick(i);

}

void MyFrame::OnBid(wxCommandEvent & event)
{
	spadesBoard->onBidButton();
}

void MyFrame::OnReturnButtonHearts(wxCommandEvent & event)
{
	heartsBoard->hide();
	heartsBoard->DestroyChildren();
	heartsBoard->Destroy();
	heartsBoard = new HeartsBoard(this);
	modeScreen->display();
}

void MyFrame::OnReturnButtonSpades(wxCommandEvent & event)
{
	spadesBoard->hide();
	spadesBoard->DestroyChildren();
	spadesBoard->Destroy();
	spadesBoard = new SpadesBoard(this);
	modeScreen->display();
}

int main(int argc, char* argv[])
{
  wxApp* pApp = new MyApp();
  wxApp::SetInstance(pApp);
  wxEntry(argc, argv);
}