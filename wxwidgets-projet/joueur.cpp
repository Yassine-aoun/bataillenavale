#include "joueur.h"
#include "wx/wx.h"
joueur::joueur(wxString nom)
{
	nickname = nom;

}
wxString joueur::get_nickname()
{
	return nickname;
}
int joueur::get_nb_r()
{
	return nb_r;
}