#include "project.h"
#include <iostream>
#include<cstring>
#include<windows.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
int verifier(int a,char b,char c,char l[11][11],bateau bt)//fonction qui verifier la possibiliter de placer les bateau lors de remplissage
{
    int r;
    r=1;
    if ((c=='H')||(c=='h'))
    {
        if ((75-b)>= bt.getnb())
        {
            for(int i=0;i<bt.getnb();i++)
            {
                if (l[a][b-64+i]!='~')
                {
                    r=0;
                }
            }

        }
        else {r=2;}
    }
    else
        {
            if ((11-a)>= bt.getnb())
        {
            for(int i=0;i<bt.getnb();i++)
            {
                if (l[a+i][b-64]!='~')
                {
                    r=0;
                }
            }

        }
        else {r=2;}
        }
    return r ;
}
int verifier1(int a,int b,char c,char l[11][11],bateau bt)// meme fonction mais pour la  methode remplir robot
{
    int r;
    r=1;
    if ((c=='H')||(c=='h'))
    {
        if ((11-b)>= bt.getnb())
        {
            for(int i=0;i<bt.getnb();i++)
            {
                if (l[a][b+i]!='~')
                {
                    r=0;
                }
            }

        }
        else {r=2;}
    }
    else
        {
            if ((11-a)>= bt.getnb())
        {
            for(int i=0;i<bt.getnb();i++)
            {
                if (l[a+i][b]!='~')
                {
                    r=0;
                }
            }

        }
        else {r=2;}
        }
    return r ;
}
using namespace std;
bateau:: bateau(int a , string n)//constructeur
{nb=a;
nom=n;}
bateau::bateau(){}//constructeur
int bateau:: getnb()// accees a l'attribut nb
{
    return nb;
}
string bateau:: getnom()// accees a l'attribut nom
{
        return nom;
}
joueur :: joueur(string ch)//constructeur
{
        nick_name=ch;
        nbc_rest=0;
        plateau_bataille[1][0]='1';// les coordoonees
        plateau_bataille[2][0]='2';
        plateau_bataille[3][0]='3';
        plateau_bataille[4][0]='4';
        plateau_bataille[5][0]='5';
        plateau_bataille[6][0]='6';
        plateau_bataille[7][0]='7';
        plateau_bataille[8][0]='8';
        plateau_bataille[9][0]='9';
        plateau_bataille[10][0]='10';
        plateau_bataille[0][1]='A';
        plateau_bataille[0][2]='B';
        plateau_bataille[0][3]='C';
        plateau_bataille[0][4]='D';
        plateau_bataille[0][5]='E';
        plateau_bataille[0][6]='F';
        plateau_bataille[0][7]='G';
        plateau_bataille[0][8]='H';
        plateau_bataille[0][9]='I';
        plateau_bataille[0][10]='J';
        plateau_bataille[0][0]='X';
        plateau_info[1][0]='1';
        plateau_info[2][0]='2';
        plateau_info[3][0]='3';
        plateau_info[4][0]='4';
        plateau_info[5][0]='5';
        plateau_info[6][0]='6';
        plateau_info[7][0]='7';
        plateau_info[8][0]='8';
        plateau_info[9][0]='9';
        plateau_info[10][0]='10';
        plateau_info[0][1]='A';
        plateau_info[0][2]='B';
        plateau_info[0][3]='C';
        plateau_info[0][4]='D';
        plateau_info[0][5]='E';
        plateau_info[0][6]='F';
        plateau_info[0][7]='G';
        plateau_info[0][8]='H';
        plateau_info[0][9]='I';
        plateau_info[0][10]='J';
        plateau_info[0][0]='X';
        for(int i=1;i<11;i++)// initialiser les plateau par l'eau
        {for(int j=1;j<11;j++)
            {
             plateau_bataille[i][j]='~';
             plateau_info[i][j]='~';
            }
        }
    }
int joueur::get_nbc_rest()// accees a l'attribut nbc_rest
{return nbc_rest;}
string joueur:: get_nick_name()// accees a l'attribut nick_name
{return nick_name;}
void joueur:: affiche1()// l'implimentation for affiche 1 qui affiche plateau bataille
    {
      cout <<endl;
      for(int i=0;i<11;i++)
      {
          cout <<endl;
          for(int j=0;j<11;j++)
            cout<<plateau_bataille[i][j]<<"     ";
          cout<<endl;
      }
    }
void joueur:: affiche2() // l'implimentation for affiche 1 qui affiche plateau info
    {
      cout <<endl;
      for(int i=0;i<11;i++)
      {
          cout <<endl;
          for(int j=0;j<11;j++)
           cout<<plateau_info[i][j]<<"     ";
          cout<<endl;
      }
    }
void joueur:: remplir(bateau l1[5],bateau l2[10],int k) //remplissage de plateau bataille
    {
        int a,r;//a variable de coordonne r est varibale qui indique si on a un error ou nn
        r=5;
        char b,c;//variables de coordonnees et diresction;
        cout<< nick_name << " commencer a remplir  ton plateau"<<endl;
        affiche1();
        if (k==1)// si k=1 donc disposition si nn disposition 2
        {
            for(int i=0;i<5;i++)
            {

              do
              {
              cout<<endl;
              cout<<"donner la premier case et la direction du bateau "<<endl<< l1[i].getnom()<< " de "<<l1[i].getnb()<<" case(s)"<<endl;
              do
              {
                 cout<<" les lignes sont entre 1 et 10"<<endl;
                 cout<<"ligne:";
                 cin>>a;
              }
              while((a<1)&&(10<a));
              cout<<endl;
              do
              {
                 cout<<" les colonnes sont entre A et J"<<endl;
                 cout<< "colonne:";
                 cin>>b;
              }
              while((b<'A')&&('G'<b));
              cout<< "direction:"<<endl<<". V pour verticale de haut vers le bas"<<endl<<". H pour horizontale du gauche vers la droite"<<endl<<"Tapez:";
              do
              {
                 cout<<" TAPEZ H OR V:"<<endl;
                 cin>>c;
              }
              while((c!='h')&&(c!='H')&&(c!='v')&&(c!='V'));
              r=verifier(a,b,c,plateau_bataille,l1[i]);
              if ((r==2)&&((c=='h')||(c=='H')))
                 cout <<"il n'y a pas assez de sapce sur la ligne"<<endl;
              else if ((r==2)&&((c=='v')||(c=='V')))
                 cout <<"il n'y a pas assez de sapce sur la colonne"<<endl;
              else if(r==0)
                 cout<<"il y a un autre bateau sur le chemin"<<endl;
              else if((r==1)&&((c=='v')||(c=='V')))
                {
                    for(int j=0;j<l1[i].getnb();j++)
                       plateau_bataille[a+j][b-64]='#';
                    nbc_rest+=l1[i].getnb();
                    affiche1();
                }
              else if((r==1)&&((c=='h')||(c=='H')))
                {
                    for(int j=0;j<l1[i].getnb();j++)
                       plateau_bataille[a][b-64+j]='#';
                    nbc_rest+=l1[i].getnb();
                    affiche1();
                }
              }
              while(r!=1);
            }
        }
        else if (k==2)// deuxieme disposition
        {
          for(int i=0;i<10;i++)
            {
              do
              {
              cout<<"donner la premier case et la direction du bateau "<<endl<< l2[i].getnom()<< "de"<<l2[i].getnb()<<" case(s)"<<endl;
              do
              {
                 cout<<" les lignes sont entre 1 et 10"<<endl;
                 cout<<"ligne:";
                 cin>>a;
              }
              while((a<1)&&(10<a));
              cout<<endl;
              do
              {
                 cout<<" les colonnes sont entre A et J"<<endl;
                 cout<< "colonne:";
                 cin>>b;
              }
              while((b<'A')&&('G'<b));
              cout<< "direction:"<<endl<<". V pour verticale de haut vers le bas"<<endl<<". H pour horizontale du gauche vers la droite"<<endl<<"Tapez:";
              do
              {
                 cout<<" TAPEZ H OR V:"<<endl;
                 cin>>c;
              }
              while((c!='h')&&(c!='H')&&(c!='v')&&(c!='V'));
              r=verifier(a,b,c,plateau_bataille,l2[i]);
              if ((r==2)&&((c=='h')||(c=='H')))
                 cout <<"il n'y a pas assez de sapce sur la ligne"<<endl;
              else if ((r==2)&&((c=='v')||(c=='V')))
                 cout <<"il n'y a pas assez de sapce sur la colonne"<<endl;
              else if(r==0)
                 cout<<"il y a un autre bateau sur le chemin"<<endl;
              else if((r==1)&&((c=='v')||(c=='V')))
                {
                    for(int j=0;j<l2[i].getnb();j++)
                       plateau_bataille[a+j][b-64]='#';

                    nbc_rest+=l2[i].getnb();
                    affiche1();
                }
              else if((r==1)&&((c=='h')||(c=='H')))
                {
                    for(int j=0;j<l2[i].getnb();j++)
                       plateau_bataille[a][b-64+j]='#';

                    nbc_rest+=l2[i].getnb();
                    affiche1();
                }
            }
            while(r!=1);
        }
        }

    }
 void joueur:: attack(joueur& j)// fonction d'attack
 {
     int a;//variable de coordonnee
     char b;//variable de coordonnee
     system("cls");//clear console
     do
     {
     cout<<"tu as "<< nbc_rest<<" case(s) restante(s)"<<endl;
     affiche1();
     cout <<endl;
     cout <<endl;
     cout <<"VOTRE PLATEAU BATAILLE EST AU DESUS"<<endl;
     cout <<endl;
     affiche2();
     cout<< nick_name <<" choisir une case de plateau pour l'attacker"<<endl;
     do
     {
        cout<<" les lignes sont entre 1 et 10"<<endl;
        cout<<"ligne:";
        cin>>a;
     }
     while((a<1)&&(10<a));
     cout<<endl;
     do
     {
        cout<<" les colonnes sont entre A et J"<<endl;
        cout<< "colonne:";
        cin>>b;
     }
     while((b<'A')&&('G'<b));
     if((j.plateau_bataille[a][b-64]=='X')||(j.plateau_bataille[a][b-64]=='O'))
     {
        system("cls");
        cout<<"tu as deja attackee cette case"<<endl;
        sleep(1);
     }
     }
     while((j.plateau_bataille[a][b-64]=='X')||(j.plateau_bataille[a][b-64]=='O'));

     if(j.plateau_bataille[a][b-64]=='#')
     {
         system("cls");
         cout<<"bon attack"<<endl;
         j.plateau_bataille[a][b-64]='X';
         plateau_info[a][b-64]='X';
         j.nbc_rest=j.nbc_rest-1;
         sleep(1);
     }
     else if(j.plateau_bataille[a][b-64]=='~')
     {
        system("cls");
        cout<<" tu as rate"<<endl;
        j.plateau_bataille[a][b-64]='O';
        plateau_info[a][b-64]='O';
        sleep(1);
     }


 }
 void joueur:: robot_remplir(bateau l1[5],bateau l2[10],int k)// le robot remplir le plateau aleatoirement et correctement
 {
     int a,b,r,c;
     char c1;
        if (k==1)
        {
            for(int i=0;i<5;i++)
            {
              r=0;
              srand(time(0));
              while(r!=1)
               {
                  a=(rand()%10)+1;
                  b=(rand()%10)+1;
                  c=rand()%2;
                  if(c==0)
                  {
                      c1='h';
                      r=verifier1(a,b,c1,plateau_bataille,l1[i]);
                      if(r!=1)
                      {
                          c1='v';
                          r=verifier1(a,b,c1,plateau_bataille,l1[i]);
                      }

                  }
                  else if(c==1)
                  {
                      c1='v';
                      r=verifier1(a,b,c1,plateau_bataille,l1[i]);
                      if(r!=1)
                      {
                          c1='h';
                          r=verifier1(a,b,c1,plateau_bataille,l1[i]);
                      }
                  }
               }
              if(c1=='v')
                {
                    for(int j=0;j<l1[i].getnb();j++)
                    {
                       plateau_bataille[a+j][b]='#';
                    }
                    nbc_rest+=l1[i].getnb();
                }
              else if(c1=='h')
                {
                    for(int j=0;j<l1[i].getnb();j++)
                    {
                       plateau_bataille[a][b+j]='#';
                    }
                    nbc_rest+=l1[i].getnb();
                }
            }
        }
        else if (k==2)
        {
          for(int i=0;i<10;i++)
            {
              r=0;
              srand(time(0));
              while(r!=1)
               {
                  a=(rand()%10)+1;
                  b=(rand()%10)+1;
                  c=rand()%2;
                  if(c==0)
                  {
                      c1='h';
                      r=verifier1(a,b,c1,plateau_bataille,l2[i]);
                      if(r!=1)
                      {
                          c1='v';
                          r=verifier1(a,b,c1,plateau_bataille,l2[i]);
                      }

                  }
                  else if(c==1)
                  {
                      c1='v';
                      r=verifier1(a,b,c1,plateau_bataille,l2[i]);
                      if(r!=1)
                      {
                          c1='h';
                          r=verifier1(a,b,c1,plateau_bataille,l2[i]);
                      }
                  }
               }
              if(c1=='v')
                {
                    for(int j=0;j<l2[i].getnb();j++)
                    {
                       plateau_bataille[a+j][b]='#';
                    }
                    nbc_rest+=l2[i].getnb();
                }
              else if(c1=='h')
                {
                    for(int j=0;j<l2[i].getnb();j++)
                    {
                        plateau_bataille[a][b+j]='#';
                    }
                    nbc_rest+=l2[i].getnb();
                }

            }
            }
        }
void joueur:: robot_attack(joueur& j,int&a,int&b,int&a1,int&b1,int&x,int&k)// fonction de l'attack intelegent du robot
{                                                                          // j l'autre joueur
    int r1;
      if(x==0)                                                             //  a ,b sont les coordonnee du premier case d'une bateau detruite
      {                                                                    //  a1 , b1 les coordonee du  l'volution du robot autour du case detruit cherchant les autre case
      r1=0;                                                               //  k indique la direction de l'evolution du robot
      srand(time(0));
      while (r1!=1)
      {
      a=(rand()%10)+1;
      b=(rand()%10)+1;
      if ((j.plateau_bataille[a][b]=='#')||(j.plateau_bataille[a][b]=='~'))
            r1=1;
      }
      if(j.plateau_bataille[a][b]=='#')
      {
          a1=a;
          b1=b;
          x=1;
      }
      else if ((j.plateau_bataille[a][b]=='O')||(j.plateau_bataille[a][b]=='X'))
      {
          x=0;
          k=1;
          robot_attack(j,a,b,a1,b1,x,k);
      }
      else if (j.plateau_bataille[a][b]=='~')
      {
          plateau_info[a][b]='O';
          j.plateau_bataille[a][b]='O';
          system("cls");
          cout<<"le Robot a raté"<<endl;
          sleep(1);
          x=0;
      }
      }
      else if (x==1)
      {
      if (j.plateau_bataille[a1][b1]=='#')
      {
          plateau_info[a1][b1]='X';
          j.plateau_bataille[a1][b1]='X';
          system("cls");
          cout<<"le robot a detruit une piece d'un bateau"<<endl;
          sleep(1);
          j.nbc_rest-=1;
          if((k==1)&&(b1!=10))
          {
              b1=b1+1;
          }
          else if((k==2)&&(b1!=1))
          {
              b1=b1-1;
          }
          else if((k==3)&&(a1!=1))
          {
              a1=a1-1;
          }
          else if((k==4)&&(a1!=10))
          {
              a1=a1+1;
          }
          else if((k==1)&&(b1==10))
          {
            k=2;
            a1=a;
            b1=b-1;
          }
          else if((k==3)&&(a1==1))
          {
            k=4;
            a1=a+1;
            b1=b;
          }
          else
          {
              k=1;
              x=0;
          }


      }
      else if (j.plateau_bataille[a1][b1]=='~')
      {
          plateau_info[a1][b1]='O';
          j.plateau_bataille[a1][b1]='O';
          system("cls");
          cout<<"le Robot a raté"<<endl;
          sleep(1);
          if((k==1)&&(b!=1))
          {
              k=2;
              a1=a;
              b1=b-1;
          }
          else if((k==2)&&(a!=1))
          {
              k=3;
              a1=a-1;
              b1=b;
          }
          else if((k==3)&&(a!=10))
          {
              a1=a+1;
              b1=b;
              k=4;
          }
          else if(k==4)
          {
              x=0;
              k=1;
          }
          if((k==1)&&(b==1)&&(a!=1))
          {
              k=3;
              a1=a-1;
              b1=b;
          }
          else if((k==2)&&(a==1))
          {
              a1=a+1;
              b1=b;
              k=4;
          }
          else if((k==3)&&(a==10))
          {
              x=0;
              k=1;
          }
          if((k==1)&&(b==1)&&(a==1))
          {
              k=4;
              a1=a+1;
              b1=b;
          }
      }
      else if ((j.plateau_bataille[a1][b1]=='O')||(j.plateau_bataille[a1][b1]=='X'))
      {
         if((k==1)&&(b!=1))
            {
                a1=a;
                b1=b-1;
                k=2;
                robot_attack(j,a,b,a1,b1,x,k);
            }
         else if ((k==2)&&(a!=1))
         {
                a1=a-1;
                b1=b;
                k=3;
                robot_attack(j,a,b,a1,b1,x,k);
         }
         else if ((k==3)&&(a!=10))
         {
                a1=a+1;
                b1=b;
                k=4;
                robot_attack(j,a,b,a1,b1,x,k);
         }
         else if (k==4)
         {
                x=0;
                k=1;
                robot_attack(j,a,b,a1,b1,x,k);
         }
         if((k==1)&&(b==1)&&(a!=1))
            {
                a1=a-1;
                b1=b;
                k=3;
                robot_attack(j,a,b,a1,b1,x,k);
            }
         else if((k==2)&&(a==1)&&(a!=10))
            {
                a1=a+1;
                b1=b;
                k=4;
                robot_attack(j,a,b,a1,b1,x,k);
            }
         else if((k==3)&&(a==10))
            {
                k=1;
                x=0;
                robot_attack(j,a,b,a1,b1,x,k);
            }
         if((k==1)&&(b==1)&&(a==1))
            {
                a1=a+1;
                b1=b;
                k=4;
                robot_attack(j,a,b,a1,b1,x,k);
            }
      }
      }
}
