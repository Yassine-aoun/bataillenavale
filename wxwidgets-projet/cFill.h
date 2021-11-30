#pragma once
#include "wx/wx.h"
#include "cmain.h"

class cFill : public wxFrame
{
private:
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;
	wxButton** btn2;

	wxBitmapButton** bitmap_btn;
	int* nField;
	int* nField2;
	bool bFirstClick = true;
	bool bFirstClick2 = true;

	wxStaticText* title;
	wxFrame* f1;

	bool direction = false;
	int bateau_type = 0;
	wxButton* tropilleur_text;
	wxButton* sousmarin_text;
	wxButton* porteavion_text;
	wxButton* croiseur_text;
	bool sousmarin = false;
	cmain* cmain_frame = nullptr;
	wxFrame* data_frame;
	wxTextCtrl* name_ctrl;

public:
	cFill(cmain*);
	~cFill();
	/*
	void onporteavion(wxCommandEvent& evt);
	void oncroiseur(wxCommandEvent& evt);
	void onsousmarin(wxCommandEvent& evt);
	void ontropilleur(wxCommandEvent& evt);
	*/
	void onadd(wxCommandEvent& evt);
	void onchoose(wxCommandEvent& evt);
	void onspot(wxCommandEvent& evt);
	void verify(bool, int, int, int);
	void onnext(wxCommandEvent& evt);
	void onok(wxCommandEvent& evt);
	void OnPaint(wxPaintEvent& WXUNUSED(event));
	wxBitmap* bit_img;
	wxPanel* panel1;
	wxBitmapButton* fortest[5];

	DECLARE_EVENT_TABLE()
};
