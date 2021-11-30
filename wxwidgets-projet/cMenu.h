#pragma once
#include "wx/wx.h"
#include "cmain.h"

class cMenu : public wxFrame
{
public:
	cMenu();
	~cMenu();

	void onstartgame(wxCommandEvent& evt);
	void onquit(wxCommandEvent& evt);
	void onhistory(wxCommandEvent& evt);

};

