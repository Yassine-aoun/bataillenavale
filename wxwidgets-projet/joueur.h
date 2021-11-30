#pragma once
#include "wx/wx.h"
class joueur
{
private:
	wxString nickname;
	int nb_r;
public:
	joueur(wxString nom);
	wxString get_nickname();
	int get_nb_r();
};

