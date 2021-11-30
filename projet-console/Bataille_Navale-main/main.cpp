#include <iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<windows.h>
#include<fstream>
#include "project.h"
using namespace std ;
int main()
{// initialisation des bateau pour remplir les tableaus l1 et l2 de bateau qui nous aide a la methode remplir
bateau Porte_Avions(5,"Porte_Avions");
bateau croiseur(4,"croiseur");
bateau contre_torpilleur1(3,"contre_torpilleur1");
bateau contre_torpilleur2(3,"contre_torpilleur2");
bateau torpilleur(2,"torpilleur");
bateau l1[5];
l1[0]=Porte_Avions;
l1[1]=croiseur;
l1[2]=contre_torpilleur1;
l1[3]=contre_torpilleur2;
l1[4]=torpilleur;
bateau CUIRASSE(4,"CUIRASSE"),CROISEUR1(3,"CROISEUR1"),CROISEUR2(3,"CROISEUR2"),TORPILLEUR1(2,"TORPILLEUR1"),TORPILLEUR2(2,"TORPILLEUR2"),TORPILLEUR3(2,"TORPILLEUR3"),SOUS_MARIN1(1,"SOUS_MARIN1"),SOUS_MARIN2(1,"SOUS_MARIN2"),SOUS_MARIN3(1,"SOUS_MARIN3"),SOUS_MARIN4(1,"SOUS_MARIN4");
bateau l2[10];
l2[0]=CUIRASSE;
l2[1]=CROISEUR1;
l2[2]=CROISEUR2;
l2[3]=TORPILLEUR1;
l2[4]=TORPILLEUR2;
l2[5]=TORPILLEUR3;
l2[6]=SOUS_MARIN1;
l2[7]=SOUS_MARIN2;
l2[8]=SOUS_MARIN3;
l2[9]=SOUS_MARIN4;
int r;
ofstream file;// creation d'object ofstream pour cree un fichier et enregistrer l'historique
r=1;// entier qui nous permer de repeter le jeux si elle est egale 1 et 0 si nn
while(r==1)
{
int p;//entier de choix dans le menux
p=4;
system("cls");//clear console
cout<<"1) 1 VS 1"<<endl<<"2)Contre un Robot"<<endl<<"3) historique"<<endl<<"Tapez 1 ou 2 ou 3:"<<endl ;
while((p!=1)&&(p!=2)&&(p!=3))
{cin>> p;}
if (p==1)// 1 vs 1
{
    string ch1 , ch2;
    cout <<"donner le nom du premier joueur "<<endl;
    cin>> ch1;
    joueur j1(ch1);
    cout <<"donner le nom du deuxieme joueur "<<endl;
    cin>> ch2;
    joueur j2(ch2);
    cout << "choisir la disposition:" <<endl;
    cout<<"1-premier disposition:"<<endl;
    cout<<". 1 PORTE_AVIONS:5 cases"<<endl;
    cout<<". 1 CROISEUR:4 cases"<<endl;
    cout<<". 2 CONTRE_TORPILLEUR:3 cases"<<endl;
    cout<<". 1 TORPILLEUR:2 cases"<<endl;
    cout<<"2-deuxieme disposition en belgique:"<<endl;
    cout<<". 1 CUIRASSE:4 cases"<<endl;
    cout<<". 2 CROISEUR:3 cases"<<endl;
    cout<<". 3 TORPILLEUR:2 cases"<<endl;
    cout<<". 4 SOUS_MARIN:1 case"<<endl;
    cout<<" TAPEZ 1 OU 2 "<<endl;
    int k;
    cin>> k;
    j1.remplir(l1,l2,k);
    system("cls");
    j2.remplir(l1,l2,k);
    system("cls");
    do
    {
        j1.attack(j2);
        j2.attack(j1);
    }
    while ((j1.get_nbc_rest()!=0)&&(j2.get_nbc_rest()!=0));
    if (j1.get_nbc_rest()==0)
    {
        cout<<j2.get_nick_name() <<" est la gagnant"<<endl;
        file.open("history.txt",std::ios::app);
        file<<j2.get_nick_name() << "est gagnant avec "<<j2.get_nbc_rest()<<"case(s) restantes et "<<j1.get_nick_name()<<" a perdu \n" ;
        file.close();
    }
    else if (j2.get_nbc_rest()==0)
    {
        cout<<j1.get_nick_name() <<" est la gagnant"<<endl;
        file.open("history.txt",std::ios::app);
        file<<j1.get_nick_name() << "est gagnant avec "<<j2.get_nbc_rest()<<"case(s) restantes et "<<j2.get_nick_name()<<" a perdu \n" ;
        file.close();
    }
}
else if(p==2)//contre robot
{
    string ch1 ;
    int a1, b1,x,a,b,k;
    x=0;
    k=1;
    cout <<"donner le nom du premier joueur "<<endl;
    cin>> ch1;
    joueur j1(ch1);
    joueur j2("Mr Robot");
    cout << "choisir la disposition:" <<endl;
    cout<<"1-premier disposition:"<<endl;
    cout<<". 1 PORTE_AVIONS:5 cases"<<endl;
    cout<<". 1 CROISEUR:4 cases"<<endl;
    cout<<". 2 CONTRE_TORPILLEUR:3 cases"<<endl;
    cout<<". 1 TORPILLEUR:2 cases"<<endl;
    cout<<"2-deuxieme disposition en belgique:"<<endl;
    cout<<". 1 CUIRASSE:4 cases"<<endl;
    cout<<". 2 CROISEUR:3 cases"<<endl;
    cout<<". 3 TORPILLEUR:2 cases"<<endl;
    cout<<". 4 SOUS_MARIN:1 case"<<endl;
    cout<<" TAPEZ 1 OU 2 "<<endl;
    int k1;
    cin>> k1;
    j2.robot_remplir(l1,l2,k1);
    j2.affiche1();
    j1.remplir(l1,l2,k1);
    system("cls");
    j2.affiche1();
    do
    {
        j1.attack(j2);
        system("cls");
        j2.robot_attack(j1,a,b ,a1,b1,x,k);
    }
    while ((j1.get_nbc_rest()!=0)&&(j2.get_nbc_rest()!=0));
    if (j1.get_nbc_rest()==0)
    {
        cout<<j2.get_nick_name() <<" est la gagnant"<<endl;
        file.open("history.txt",std::ios::app);
        file<<j2.get_nick_name() << "est gagnant avec "<<j2.get_nbc_rest()<<"case(s) restantes et "<<j1.get_nick_name()<<" a perdu \n" ;
        file.close();
    }
    else if (j2.get_nbc_rest()==0)
    {
        cout<<j1.get_nick_name() <<" est la gagnant"<<endl;
        file.open("history.txt",std::ios::app);
        file<<j1.get_nick_name() << "est gagnant avec "<<j2.get_nbc_rest()<<"case(s) restantes et "<<j2.get_nick_name()<<" a perdu \n" ;
        file.close();
    }
}
else // SI P=3 on affiche l'hisstorique
{
  string line;
  ifstream file1("history.txt");
  if(file1.is_open())
  {
      while(getline(file1,line))
      {
          cout<<line<<endl;
      }
  }
}
cout<<" voulez vous repeter ? "<<endl<<"1) yes" <<endl<<"2) no"<<endl<<"Choisir 1 ou 2"<<endl;
cin>> r;
}
    return 0;
}
