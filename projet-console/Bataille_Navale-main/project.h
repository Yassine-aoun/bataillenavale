#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std ;
class bateau
{
private:
    int nb;
    string nom;
public:

    bateau(int a ,string n);//constructeur avec initialisation
    bateau();//constricture
    int getnb();//acces a l'attribut nb
    string getnom();//acces a l'attribut nom
};
class joueur
{
private:
    int nbc_rest;
    char plateau_bataille[11][11];
    char plateau_info[11][11];
    string nick_name;
public:
    joueur(string ch);//constructeur
    int get_nbc_rest();//acces a l'attribut nbc_rest
    string get_nick_name();//acces a l'attribut nick_name
void affiche1();//affichage de plateau_bataille
void affiche2();//affichage de plateau_info
void remplir(bateau l1[5],bateau l2[10],int k);//remplir le plateau_bataille en precisant la disposition
void attack(joueur& j);// this attack le joueur j en prenant compte des variable changant
void robot_remplir(bateau l1[5],bateau l2[10],int k);// le robot remplir son plateau_bataille aleatoirement
void robot_attack(joueur& j,int&a,int&b,int&a1,int&b1,int&x,int&k);//le robot attack le joueur en utilisant l'instiligence artificiel

};
