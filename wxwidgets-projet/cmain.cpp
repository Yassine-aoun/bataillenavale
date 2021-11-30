#include "cmain.h"
#include "bateau.h"
#include "cFill.h"
#include <iostream>
#include <fstream>
#include "wxBackgroundBitmap.h"
using namespace std;
wxBEGIN_EVENT_TABLE(cmain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked1)
EVT_BUTTON(10002, OnButtonClicked2)
EVT_TIMER(1111, timefunction)
wxEND_EVENT_TABLE()

void cmain::timefunction(wxTimerEvent& evt) {
	wxString s;
	s = timetostring(time);
	time--;
	time_label->SetLabel(s);
	if (time == 0) {
		switchsides();
		time = 15;
	}
	evt.Skip();
}
cmain::cmain() : wxFrame(nullptr, wxID_ANY, "Match Window", wxPoint(30, 30), wxSize(1400, 800))
{
	time_label = new wxStaticText(this, wxID_ANY, timetostring(0), wxPoint(700, 30));
	time_label->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("lol.jpg"), wxBITMAP_TYPE_JPEG);
	wxBackgroundBitmap* NotebookBackground = new wxBackgroundBitmap(TempBitmap);
	this->PushEventHandler(NotebookBackground);

	cFill* fill1 = new cFill(this);
	fill1->Show();
	
	btn = new wxButton * [nFieldWidth * nFieldHeight];
	nField = new int[nFieldWidth * nFieldHeight];
	btn2 = new wxButton * [nFieldWidth * nFieldHeight];
	nField2 = new int[nFieldWidth * nFieldHeight];
	wxPanel* wesst = new wxPanel(this, wxID_ANY, wxPoint(575, 100), wxSize(350, 500));
	wxPanel* tahtjoueur1 = new wxPanel(this, wxID_ANY, wxPoint(10, 620), wxSize(500, 150));
	wxPanel* tahtjoueur2 = new wxPanel(this, wxID_ANY, wxPoint(995, 620), wxSize(500, 150));
	wxPanel* panel1 = new wxPanel(this, wxID_ANY, wxPoint(10, 100), wxSize(500, 500));
	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxPoint(995, 100), wxSize(500, 500));



	wxGridSizer* grid1 = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	wxGridSizer* grid2 = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldHeight + x] = new wxButton(panel1, 10000 + (y * nFieldWidth + x));
			btn[y * nFieldHeight + x]->Enable(false);

			grid1->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);
			btn2[y * nFieldHeight + x] = new wxButton(panel2, 20000 + (y * nFieldWidth + x));
			btn2[y * nFieldHeight + x]->Enable(false);

			grid2->Add(btn2[y * nFieldWidth + x], 2, wxEXPAND | wxALL);
			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::OnButtonClicked1, this);
			btn2[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::OnButtonClicked1, this);
			nField[y * nFieldWidth + x] = 0;
			nField2[y * nFieldWidth + x] = 0;
		}
	}
	panel1->SetSizer(grid1);
	panel2->SetSizer(grid2);
	panel1->Layout();
	panel2->Layout();

	startgame = new wxButton(this, wxID_ANY,"Start game", wxPoint(750, 700));
	startgame->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::onstartgame, this);

	player1_label = new wxStaticText(tahtjoueur1, wxID_ANY, player1_name, wxPoint(0, 0));
	player2_label = new wxStaticText(tahtjoueur2, wxID_ANY, player2_name, wxPoint(0, 0));
	datetime = new wxTimer(this, 1111);
	
}


cmain::~cmain()
{
	Destroy();
	this->PopEventHandler(true);
	datetime->Stop();
}

void cmain::OnButtonClicked1(wxCommandEvent& evt)
{
	if (evt.GetId() / 10000 == 1) {
		int x = (evt.GetId() - 10000) % nFieldWidth;
		int y = (evt.GetId() - 10000) / nFieldWidth;
		if (nField[evt.GetId() - 10000] == 1) {
			btn[evt.GetId() - 10000]->SetLabel("X");
			btn[evt.GetId() - 10000]->Enable(false);
			player2score--;
		}
		else {
			btn[evt.GetId() - 10000]->SetLabel("O");
			btn[evt.GetId() - 10000]->Enable(false);
			btn[evt.GetId() - 10000]->SetBackgroundColour(wxColor(0, 0, 0));
		}
		if (player2score == 0) {
			endgame();
			wxMessageBox("Player 1 won!!!!");
		}
		else {
			time = 15;
			switchsides();
		}
	}
	else {
		int x2 = (evt.GetId() - 20000) % nFieldWidth;
		int y2 = (evt.GetId() - 20000) / nFieldWidth;

		if (nField2[evt.GetId() - 20000] == 1) {
			btn2[evt.GetId() - 20000]->SetLabel("X");
			btn2[evt.GetId() - 20000]->Enable(false);
			player1score--;
		}
		else {
			btn2[evt.GetId() - 20000]->SetLabel("O");
			btn2[evt.GetId() - 20000]->Enable(false);
			btn2[evt.GetId() - 20000]->SetBackgroundColour(wxColor(0, 0, 0));
		}
		if (player1score == 0) {
			endgame();
			wxMessageBox("Player 2 won!!!!");
		}
		else {
			time = 15;
			switchsides();
		}
	}
	evt.Skip();
}
void cmain::OnButtonClicked2(wxCommandEvent& evt)
{
	int x2 = (evt.GetId() - 10000) % nFieldWidth;
	int y2 = (evt.GetId() - 10000) / nFieldWidth;

	if (nField2[evt.GetId() - 10000] == 1) {
		btn2[evt.GetId() - 10000]->SetLabel("X");
		btn2[evt.GetId() - 10000]->Enable(false);
		player1score--;
	}
	else {
		btn2[evt.GetId() - 10000]->SetLabel("O");
		btn2[evt.GetId() - 10000]->Enable(false);
		btn2[evt.GetId() - 10000]->SetBackgroundColour(wxColor(0, 0, 0));
	}
	if (player1score == 0) {
		endgame();
		wxMessageBox("Player 2 won!!!!");
	}
	else {
		time = 15;
		switchsides();
	}
	evt.Skip();
}

void cmain::affiche() {
	if (lastplayer) {
		/*
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				if (nField[y * nFieldWidth + x] != 0) btn[y * nFieldHeight + x]->SetLabel("#");
			}
		}		
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				if (nField2[y * nFieldWidth + x] != 0) btn2[y * nFieldHeight + x]->SetLabel("#");
			}
		}
		*/
	}
	else {
		nField = nField2;
		cFill* f2 = new cFill(this);
		f2->Show();
	}
	lastplayer = true;
}

void cmain::onstartgame(wxCommandEvent& evt) {
	if (player1) {
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				btn[y * nFieldHeight + x]->Enable(true);
				btn2[y * nFieldHeight + x]->Enable(false);
			}
		}
	}
	else {
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				btn2[y * nFieldHeight + x]->Enable(true);
				btn[y * nFieldHeight + x]->Enable(false);
			}
		}
	}
	player1 = !player1;
	startgame->Show(false);

	datetime->Start(1000);
	evt.Skip();
}

void cmain::switchsides() {
	if (player1) {
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				if (btn[y * nFieldHeight + x]->GetLabel() == "") btn[y * nFieldHeight + x]->Enable(true);
				if (btn2[y * nFieldHeight + x]->GetLabel() == "") btn2[y * nFieldHeight + x]->Enable(false);
			}
		}
	}
	else {
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				if (btn2[y * nFieldHeight + x]->GetLabel() == "") btn2[y * nFieldHeight + x]->Enable(true);
				if (btn[y * nFieldHeight + x]->GetLabel() == "") btn[y * nFieldHeight + x]->Enable(false);
			}
		}
	}
	player1 = !player1;
}

void cmain::endgame() {

	wxFrame* end_frame = new wxFrame(this, wxID_ANY, "End game", wxPoint(200, 100), wxSize(800, 600), wxCAPTION | wxFRAME_FLOAT_ON_PARENT);
	wxButton* quit_btn = new wxButton(end_frame, wxID_ANY, "Quit", wxPoint(50,500));
	quit_btn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::onquit, this);
	wxButton* replay = new wxButton(end_frame, wxID_ANY, "Replay", wxPoint(120, 500));
	replay->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::onreplay, this);
	wxStaticText* winner = new wxStaticText(end_frame, wxID_ANY, "qsdqsdqsd");
	ofstream output("matchs.txt", ios::app);
	
	if (player1score <= player2score) {
		winner->SetLabel(player2_label->GetLabel());
		output << player1_label->GetLabel() + " 0 " + player2_label->GetLabel() + " " + "1" << endl;

	}
	else {
		winner->SetLabel(player1_label->GetLabel());
		output << player1_label->GetLabel() + " 1 " + player2_label->GetLabel() + " " + "0" << endl;

	}
	winner->SetFont(wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	output.close();
	end_frame->Show();
}

void cmain::onquit(wxCommandEvent& evt) {
	this->Close();
	evt.Skip();
}

void cmain::onreplay(wxCommandEvent& evt) {
	this->Close();
	cmain* frame = new cmain();

	evt.Skip();
}

wxString cmain::timetostring(int x) {
	wxString h, m, s;
	int hh, mm, ss;
	ss = x % 60;
	x = x / 60;
	mm = x % 60;
	x = x / 60;
	hh = x % 60;
	h << hh;
	m << mm;
	s << ss;
	wxString res;
	if (ss < 10 && mm < 10) res =  "0" + s;
	else if (ss < 10 && mm >= 10) res =  "0" + s;
	else if (ss >= 10 && mm < 10) res =   s;
	else res =  ":" + s;
	return res;
}