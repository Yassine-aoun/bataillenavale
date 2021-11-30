#include "cMenu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "wxBackgroundBitmap.h"

using namespace std;
cMenu::cMenu() : wxFrame(nullptr, wxID_ANY, "Menu", wxPoint(200,100), wxSize(1000,800)){
	wxButton* stargame = new wxButton(this, wxID_ANY, "Start game", wxPoint(100, 300));
	stargame->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMenu::onstartgame, this);
	wxButton* history = new wxButton(this, wxID_ANY, "History", wxPoint(100, 350));
	history->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMenu::onhistory, this);

	wxButton* quit = new wxButton(this, wxID_ANY, "Quit", wxPoint(100, 400));
	quit->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMenu::onquit, this);
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("bataille-navale-fb.jpg"), wxBITMAP_TYPE_JPEG);
	wxBackgroundBitmap* NotebookBackground = new wxBackgroundBitmap(TempBitmap);
	this->PushEventHandler(NotebookBackground);
}

cMenu::~cMenu() {
	Destroy();
	this->PopEventHandler(true);

}

void cMenu::onstartgame(wxCommandEvent& evt) {
	cmain* frame = new cmain();
	this->Close();
	evt.Skip();
}

void cMenu::onhistory(wxCommandEvent& evt) {
	wxFrame* history_frame = new wxFrame(this, wxID_ANY, "History", wxPoint(100, 100), wxSize(800, 600));
	wxListBox* matchs = new wxListBox(history_frame, wxID_ANY, wxPoint(300, 50), wxSize(300,500));
	wxStaticText* title = new wxStaticText(history_frame, wxID_ANY, "History");
	title->SetFont(wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	ifstream input("matchs.txt");
	vector<string> ans;
	string s;
	while (getline(input, s))
	{
		ans.push_back(s);
	}
	input.close();

	for (auto line : ans) {
		matchs->AppendString(line);
	}
	history_frame->Show();
 	evt.Skip();
}

void cMenu::onquit(wxCommandEvent& evt) {
	this->Close();
	evt.Skip();
}