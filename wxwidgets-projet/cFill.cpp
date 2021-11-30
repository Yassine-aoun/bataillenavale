#include "cFill.h"
#include <wx/rawbmp.h>
#include "wxBackgroundBitmap.h"

using namespace std;
BEGIN_EVENT_TABLE(cFill, wxFrame)
//EVT_PAINT(cFill::OnPaint)
END_EVENT_TABLE()

void cFill::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);
	PrepareDC(dc);
	dc.DrawBitmap(*bit_img, 500, 0, true);
}

cFill::cFill(cmain* parent) : wxFrame(nullptr, wxID_ANY, "Remplissage", wxPoint(30, 30), wxSize(1400, 800), wxCAPTION) {
	cmain_frame = parent;

	title = new wxStaticText(this, wxID_ANY, "Remplissage", wxPoint(10, 10));
	title->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true));
	int x = 80;
	panel1 = new wxPanel(this, wxID_ANY, wxPoint(10 + x, 130), wxSize(500, 500));
	panel1->SetBackgroundColour(wxColor(111, 111, 111));
	wxButton* nums[10];
	wxButton* alph[10];
	wxInitAllImageHandlers();
	//wxImage* img = new wxImage("porteavion.png", wxBITMAP_TYPE_PNG);
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("lol.jpg"), wxBITMAP_TYPE_JPEG);
	wxBackgroundBitmap* NotebookBackground = new wxBackgroundBitmap(TempBitmap);
	this->PushEventHandler(NotebookBackground);


	wxBitmap* vide;
	vide = new wxBitmap();


	for (int i = 0; i < 10; i++) {
		wxString s;
		s << (i + 1);
		nums[i] = new wxButton(this, wxID_ANY, s, wxPoint(x + 10 + 50 * i, 80), wxSize(49, 49), wxBORDER_NONE | wxBU_EXACTFIT);
		nums[i]->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		nums[i]->SetBackgroundColour(wxColor(111, 111, 111));

		alph[i] = new wxButton(this, wxID_ANY, (char)(65 + i), wxPoint(x - 40, 130 + 50 * i), wxSize(49, 49), wxBU_EXACTFIT | wxBORDER_NONE);
		alph[i]->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
		alph[i]->SetBackgroundColour(wxColor(111, 111, 111));
	}
	btn = new wxButton * [nFieldWidth * nFieldHeight];
	bitmap_btn = new wxBitmapButton * [nFieldWidth * nFieldHeight];

	nField = new int[nFieldWidth * nFieldHeight];
	wxGridSizer* grid1 = new wxGridSizer(nFieldWidth, nFieldHeight, 1, 1);
	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			/*
			btn[y * nFieldHeight + x] = new wxButton(panel1, 10000 + (y * nFieldWidth + x), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
			btn[y * nFieldHeight + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onspot, this);
			//btn[y * nFieldHeight + x]->SetLabel(to_string((y * nFieldHeight + x)));
			btn[y * nFieldHeight + x]->SetBackgroundColour(wxColor(141, 179, 184));

			grid1->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);
			*/

			bitmap_btn[y * nFieldHeight + x] = new wxBitmapButton(panel1, 10000 + (y * nFieldWidth + x), *vide, wxDefaultPosition, wxSize(49, 49), wxBORDER_NONE);
			bitmap_btn[y * nFieldHeight + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onspot, this);
			//btn[y * nFieldHeight + x]->SetLabel(to_string((y * nFieldHeight + x)));
			bitmap_btn[y * nFieldHeight + x]->SetBackgroundColour(wxColor(141, 179, 184));

			grid1->Add(bitmap_btn[y * nFieldWidth + x], 0, wxEXPAND | wxALL);
			nField[y * nFieldWidth + x] = 0;
		}
	}
	panel1->SetSizer(grid1);
	panel1->Layout();
	wxPanel* panel3 = new wxPanel(this, wxID_ANY, wxPoint(700, 80), wxSize(400, 550));

	wxButton* porteavion[5];
	porteavion_text = new wxButton(panel3, 10, "1 Porte avion", wxPoint(60, 20));
	porteavion_text->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onadd, this);
	for (int i = 0; i < 5; i++) {
		porteavion[i] = new wxButton(panel3, wxID_ANY, "", wxPoint(50 + i * 30, 50), wxSize(30, 30), wxBORDER_NONE);

	}

	wxButton* croiseur[4];
	croiseur_text = new wxButton(panel3, 11, "1 Croiseur", wxPoint(60, 90));
	croiseur_text->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onadd, this);
	for (int i = 0; i < 4; i++) {
		croiseur[i] = new wxButton(panel3, wxID_ANY, "", wxPoint(50 + i * 30, 120), wxSize(30, 30), wxBORDER_NONE);
	}

	wxButton* sousmarin[6];
	sousmarin_text = new wxButton(panel3, 12, "2 Sous-marins", wxPoint(60, 180));
	sousmarin_text->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onadd, this);
	for (int i = 0; i < 3; i++) {
		sousmarin[i] = new wxButton(panel3, wxID_ANY, "", wxPoint(50 + i * 30, 220), wxSize(30, 30), wxBORDER_NONE);
	}
	for (int i = 3; i < 6; i++) {
		sousmarin[i] = new wxButton(panel3, wxID_ANY, "", wxPoint(70 + i * 30, 220), wxSize(30, 30), wxBORDER_NONE);
	}
	wxButton* tropilleur[2];
	tropilleur_text = new wxButton(panel3, 13, "1 Tropilleur", wxPoint(60, 270));
	tropilleur_text->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onadd, this);
	for (int i = 0; i < 2; i++) {
		tropilleur[i] = new wxButton(panel3, wxID_ANY, "", wxPoint(50 + i * 30, 300), wxSize(30, 30), wxBORDER_NONE);
	}

	wxStaticText* aleau = new wxStaticText(panel3, wxID_ANY, "~ A l'eau", wxPoint(60, 350));
	aleau->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	wxStaticText* touche = new wxStaticText(panel3, wxID_ANY, "# Beteau", wxPoint(60, 390));
	touche->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	wxButton* next = new wxButton(this, wxID_ANY, "Next", wxPoint(1200, 700));
	next->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onnext, this);

	data_frame = new wxFrame(this, wxID_ANY, "Name", wxPoint(500, 400), wxSize(300, 100), wxCAPTION | wxFRAME_FLOAT_ON_PARENT);
	name_ctrl = new wxTextCtrl(data_frame, wxID_ANY, "", wxPoint(10, 20));
	wxButton* ok_button = new wxButton(data_frame, wxID_ANY, "Ok", wxPoint(150, 20));
	ok_button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onok, this);
	this->Enable(false);
	data_frame->Show();

	/*
	for (int i = 0; i < 5; i++) {
		fortest[i] = new wxBitmapButton(this, wxID_ANY, *vide, wxPoint(900 + i * 50, 0), wxSize(49,49), wxNO_BORDER);
		fortest[i]->SetBackgroundColour(wxColor(141, 179, 184));
	}
	*/

}

cFill::~cFill() {
	Destroy();
	this->PopEventHandler(true);

}

void cFill::onadd(wxCommandEvent& evt) {
	bateau_type = evt.GetId();
	if (bateau_type == 10) {
		porteavion_text->Enable(false);
	}
	if (bateau_type == 11) {
		croiseur_text->Enable(false);
	}
	if (bateau_type == 12) {
		if (sousmarin == true) sousmarin_text->Enable(false);
		sousmarin = true;
	}
	if (bateau_type == 13) {
		tropilleur_text->Enable(false);
	}
	f1 = new wxFrame(this, wxID_ANY, "Choose", wxPoint(500, 200), wxDefaultSize, wxICONIZE);
	f1->Show();
	wxButton* horizontal = new wxButton(f1, 1, "Horizontal", wxPoint(150, 50));
	wxButton* vertical = new wxButton(f1, 2, "Vertical", wxPoint(150, 150));
	horizontal->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onchoose, this);
	vertical->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cFill::onchoose, this);
	this->Enable(false);
	evt.Skip();
}

void cFill::onchoose(wxCommandEvent& evt) {
	int id = evt.GetId();
	if (id == 1) {
		direction = false;
	}
	else {
		direction = true;
	}
	f1->Close();
	this->Enable(true);
	this->SetFocus();
	wxMessageBox("You may now click the start point.");
	evt.Skip();
}

void cFill::onspot(wxCommandEvent& evt) {
	int id = evt.GetId();
	int y = (id - 10000) / nFieldWidth;
	int x = (id - 10000) % nFieldWidth;

	int needed_spots = 0;

	bool caninsert = true;
	//bateau_type used for verifying if a boat is selected and which one is it.
	if (bateau_type == 0) {
		wxMessageBox("Please select a boat.");
	}
	else {
		if (bateau_type == 10) {
			needed_spots = 5;
		}
		if (bateau_type == 11) {
			needed_spots = 4;
		}
		if (bateau_type == 12) {
			needed_spots = 3;
		}
		if (bateau_type == 13) {
			needed_spots = 2;
		}
		verify(direction, needed_spots, x, y);
	}
	evt.Skip();
}

void cFill::verify(bool direction, int needed_spots, int x, int y) {
	bool caninsert = true;
	if (direction) {
		for (int i = 0; i < needed_spots; i++) {
			if (x + i < 10) {
				//edge case
				if (nField[y * nFieldWidth + x + i] == 1) { //spot not available
					caninsert = false;
				}
			}
			else {
				caninsert = false;
			}

		}
	}
	else {//for the other direction
		for (int i = 0; i < needed_spots; i++) {
			if (y + i < 10) {
				//edge case
				if (nField[(y + i) * nFieldWidth + x] == 1) { //spot not available
					caninsert = false;
				}
			}
			else {
				caninsert = false;
			}

		}
	}
	if (caninsert) {
		if (direction) {
			for (int i = 0; i < needed_spots; i++) {
				nField[y * nFieldWidth + x + i] = 1;
				//btn[y * nFieldWidth + x + i]->SetLabel("#");

			}
			if (needed_spots == 5) {
				wxImage* img1[5];
				wxBitmapButton* bitbtn[5];
				for (int i = 0; i < 5; i++) {
					img1[i] = new wxImage("./porteavion/porteavion_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					*img1[i] = img1[i]->Rotate90();
					//bitbtn[i] = new wxBitmapButton(this, wxID_ANY, *img1[i], wxPoint(700 + i * 50, 0));
					bitmap_btn[y * nFieldWidth + x + i]->SetBitmap(*img1[i]);
				}
			}
			else if (needed_spots == 4) {
				wxImage* img1[4];
				wxBitmapButton* bitbtn[4];
				for (int i = 0; i < 4; i++) {
					img1[i] = new wxImage("./croiseur/croiseur_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					*img1[i] = img1[i]->Rotate90();
					bitmap_btn[y * nFieldWidth + x + i]->SetBitmap(*img1[i]);
				}
			}
			else if (needed_spots == 3) {
				wxImage* img1[3];
				wxBitmapButton* bitbtn[3];
				for (int i = 0; i < 3; i++) {
					img1[i] = new wxImage("./sousmarin/sousmarin_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					*img1[i] = img1[i]->Rotate90();
					bitmap_btn[y * nFieldWidth + x + i]->SetBitmap(*img1[i]);
				}
			}
			else if (needed_spots == 2) {
				wxImage* img1[2];
				wxBitmapButton* bitbtn[2];
				for (int i = 0; i < 2; i++) {
					img1[i] = new wxImage("./torpilleur/torpilleur_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					*img1[i] = img1[i]->Rotate90();
					bitmap_btn[y * nFieldWidth + x + i]->SetBitmap(*img1[i]);
				}
			}
		}
		else {
			for (int i = 0; i < needed_spots; i++) {
				nField[(y + i) * nFieldWidth + x] = 1;
				//btn[(y + i) * nFieldWidth + x]->SetLabel("#");
			}
			if (needed_spots == 5) {
				wxImage* img1[5];
				//wxBitmapButton* bitbtn[5];
				for (int i = 0; i < 5; i++) {
					img1[i] = new wxImage("./porteavion/porteavion_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					//bitbtn[i] = new wxBitmapButton(this, wxID_ANY, *img1[i], wxPoint(700 + i * 50, 0));
					bitmap_btn[(y + i) * nFieldWidth + x]->SetBitmap(*img1[i]);
				}
			}
			else if (needed_spots == 4) {
				wxImage* img1[4];
				wxBitmapButton* bitbtn[4];
				for (int i = 0; i < 4; i++) {
					img1[i] = new wxImage("./croiseur/croiseur_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					bitmap_btn[(y + i) * nFieldWidth + x]->SetBitmap(*img1[i]);
				}
			}
			else if (needed_spots == 3) {
				wxImage* img1[3];
				wxBitmapButton* bitbtn[3];
				for (int i = 0; i < 3; i++) {
					img1[i] = new wxImage("./sousmarin/sousmarin_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					bitmap_btn[(y + i) * nFieldWidth + x]->SetBitmap(*img1[i]);
				}
			}
			else if (needed_spots == 2) {
				wxImage* img1[2];
				wxBitmapButton* bitbtn[2];
				for (int i = 0; i < 2; i++) {
					img1[i] = new wxImage("./torpilleur/torpilleur_" + to_string(i + 1) + ".png", wxBITMAP_TYPE_PNG);
					bitmap_btn[(y + i) * nFieldWidth + x]->SetBitmap(*img1[i]);
				}
			}
		}
		bateau_type = 0;

	}
	else {
		wxMessageBox("Cannot");
	}
}

void cFill::onnext(wxCommandEvent& evt) {
	if (porteavion_text->IsEnabled() == false && tropilleur_text->IsEnabled() == false && sousmarin_text->IsEnabled() == false && croiseur_text->IsEnabled() == false) {
		if (cmain_frame->lastplayer) cmain_frame->Show();
		cmain_frame->nField2 = nField;
		cmain_frame->affiche();
		this->Close();
	}
	else {
		wxMessageBox("Please use all.");
	}
	/*
	if (cmain_frame->lastplayer) {
		cmain_frame->Show();
		//cmain_frame->endgame();
	}
	cmain_frame->nField2 = nField;
	cmain_frame->affiche();
	this->Close();
	*/

	evt.Skip();
}

void cFill::onok(wxCommandEvent& evt) {
	if (cmain_frame->lastplayer) {
		cmain_frame->player2_label->SetLabel(name_ctrl->GetValue());
	}
	else {
		cmain_frame->player1_label->SetLabel(name_ctrl->GetValue());
	}
	data_frame->Close();
	this->Enable(true);
	evt.Skip();
}