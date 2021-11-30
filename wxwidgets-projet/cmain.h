#pragma once
#include "wx/wx.h"
class cmain : public wxFrame
{
public:
	cmain();
	~cmain();
public:
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;
	wxButton** btn2;
	int* nField;
	int* nField2;
	bool bFirstClick = true;
	bool bFirstClick2 = true;
	bool lastplayer = false;
	bool player1 = true;
	wxButton* startgame;
	int player1score = 17;
	int player2score = 17;
	
	wxString player1_name;
	wxString player2_name;

	wxStaticText* player1_label;
	wxStaticText* player2_label;
	int time= 15;
	wxTimer* datetime;
	wxStaticText* time_label;

	void OnButtonClicked1(wxCommandEvent& evt);
	void OnButtonClicked2(wxCommandEvent& evt);
	void affiche();
	void onstartgame(wxCommandEvent& evt);
	void switchsides();
	void endgame();
	void onquit(wxCommandEvent& evt);
	void onreplay(wxCommandEvent& evt);
	void addsecond(wxTimerEvent& evt);
	wxString timetostring(int);
	void timefunction(wxTimerEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

