/****************************************
 *********RAFAL*WALICZEK*****************
 ************SNAKE V2********************
 ****************************************/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <windows.h>

using namespace std;

//ZMIENNE GLOBALNE
//dla menu
char wybor;
//dla pola do gry
int szerokosc, wysokosc, szybkosc;
//dla sterowania

//DEKLARACJA FUNKCJI
int menu1(int m);
int menu2(int m);
void rekordy();
void latwy();
void sredni();
void trudny();
void zwolnijPamiec(char **&tab, int szer);
void pole(char **&tab,int szer,int wys, int szyb, string prz);

void gora(vector <int> &gora);
void dol(vector <int> &dol);
void prawo(vector <int> &prawo);
void lewo(vector <int> &lewo);


int main()
{
    const int menu = 1;
    srand(time(NULL));

    while(true)
    {

        switch(menu1(menu))
            {
                case 1:
                {
                    switch(menu2(menu))
                        {
                            case 1:
                            {
                                latwy();
                                break;
                            }
                            case 2:
                            {
                                sredni();
                                break;
                            }
                            case 3:
                            {
                                trudny();
                                break;
                            }
                            case 4:
                            {
                            break;
                            }
                        } 
                                break;
                }
                case 2:
                {
                    rekordy();
                    continue;
                }
                case 3:
                {
                    exit(0);
                }
            } 

        
       
      

    }   



    return 0;
}
//GLOWNE MENU GRY
int menu1(int m)
{
     do
        {
            system("cls");
           cout << "************SNAKE************\n\n";
           cout << (m == 1 ? "  \t->GRAJ" : "\t    Graj") << endl;
           cout << (m == 2 ? "  \t->REKORDY" : "\t    Rekordy") << endl << endl;
           cout << (m == 3 ? "  \t->WYJSCIE" : "\t    Wyjscie") << endl;
            wybor=getch();
            if(wybor==72 && m>1)
            {
                m--;
            }   
            if(wybor==80 && m<3)
            {
                m++;
            }     
        
        } while (wybor!=13);
        return m;
}
//MENU WYBORU POZIOMU TRUDNOSCI
int menu2(int m)
{
    do
    {
     system("cls");
           cout << "************SNAKE************\n\n";
           cout << (m == 1 ? "  \t->LATWY" : "\t    Latwy") << endl;
           cout << (m == 2 ? "  \t->SREDNI" : "\t    Sredni") << endl;
           cout << (m == 3 ? "  \t->TRUDNY" : "\t    Trudny") << endl << endl;
           cout << (m == 4 ? "  \t->POWROT" : "\t    Powrot") << endl;
            wybor=getch();
            if(wybor==72 && m>1)
            {
                m--;
            }   
            if(wybor==80 && m<4)
            {
                m++;
            }     
    } while (wybor!=13);
    return m;
}
//LISTA REKORDOW WCZYTYWANA Z PLIKU
void rekordy()
{   
    //MENU TESTOWE
    system("cls");
    cout << "************REKORDY************\n" << endl; 
    cout << "\t 1 - " << " AAA " << " -" <<endl;
    cout << "\t 2 - " << " BBB " << " -" <<endl;
    cout << "\t 3 - " << " CCC " << " -" <<endl;
    cout << "\t 4 - " << " DDD " << " -" <<endl;
    cout << "\t 5 - " << " EEE " << " -" <<endl;
    cout << "\t 6 - " << " FFF " << " -" <<endl;
    cout << "\t 7 - " << " GGG " << " -" <<endl;
    cout << "\t 8 - " << " HHH " << " -" <<endl;
    cout << "\t 9 - " << " III " << " -" <<endl;
    cout << "\t10 - " << " JJJ " << " -" <<endl;
    cout << "\t11 - " << " KKK " << " -" <<endl;
    cout << "\t12 - " << " LLL " << " -" <<endl;
    cout << endl;
    system("pause");
}
//POZIOM LATWY
void latwy()
{
    char **stol = nullptr;
    string przerwa = "                                  ";
    szerokosc = 18;
    wysokosc = 18;
    szybkosc= 3;

    
    do
    {

        pole(stol, szerokosc, wysokosc, szybkosc, przerwa);


    }while(wybor=='q');

    zwolnijPamiec(stol,szerokosc);

}
//POZIOM SREDNI
void sredni()
{
    char **stol = nullptr;
    string przerwa = "                            ";
    szerokosc = 15;
    wysokosc = 15;
    szybkosc= 6;
    do
    {
        pole(stol,szerokosc, szybkosc, wysokosc,przerwa);

    } while (wybor=='q');

    zwolnijPamiec(stol,szerokosc);
    
}
//POZIOM TRUDNY
void trudny()
{
    char **stol = nullptr;
    string przerwa = "                  ";
    szerokosc = 10;
    wysokosc = 10;
    szybkosc = 9;
    do
    {
        pole(stol, szerokosc, wysokosc, szybkosc, przerwa);

    } while (wybor=='q');

    zwolnijPamiec(stol, szerokosc);
     
}
//FUNKCJA TWORZACA POLE DO GRY
void pole(char **&tab,int szer,int wys,int szyb, string prz)
{
    system("cls");
     //DEKLARACJA WSP WEZA
    vector<int> xyWaz;
    //DEKLARACJA WSP PUNKT
    vector<int>xyPunkt;

    //DEKLARACJA TABLICY
    tab=new char*[szer];
     
     for (int i=0; i<szer; i++)
    {
        tab[i]=new char[wys];
    }
     //LOSOWANIE WSP WAZA
     xyWaz.push_back(rand()%(szer-1));
     xyWaz.push_back(rand()%(wys-1));
//////////////////////////////////////////////////////////////////////////
/////////--------------------------POLE----------------------------------
          do

            {
                system("cls");

                //ZAPELNIANIE TABLICY "p" = PUSTE POLE
                for(int i=0; i<szer; i++)
                {
                    for(int j=0; j<wys; j++)
                    {
                        tab[i][j] = 'p';
                    }
                }
                

                //USTALANIE POZYCJI WEZA
                tab[xyWaz[0]][xyWaz[1]]='w';

                //LOSOWANIE WSP PUNKTU
                do
                {
                    xyPunkt.push_back(rand()%(szer-1));
                    xyPunkt.push_back(rand()%(wys-1));
            
                } while (tab[xyPunkt[0]][xyPunkt[1]]!='p');

                //USTALANIE POZYCJI PUNKTU

                tab[xyPunkt[0]][xyPunkt[1]]='x';    
                

                //RYSOWANIE RAMKI POLA GRY
                for(int i=0; i<szerokosc; i++)
                {
                    cout << "--";
                    if(i==szerokosc-1)
                    {
                        cout << endl;
                        for(int j=0; j<wysokosc; j++)
                        {
                            cout << "|" ;

                            for (int l=0; l<szer-1; l++)
                            {
                                if(tab[l][j]=='p')
                                {
                                    cout << "  ";
                                }
                                if(tab[l][j]=='w')
                                {
                                    cout<<"w"<< " ";
                                }
                                if(tab[l][j]=='x')
                                {
                                    cout << "x" << " ";
                                }
                            }
                            
                            cout << "|" <<endl;
                            if(j==wysokosc-1)
                            {
                                for (int k=0; k<szerokosc; k++)
                                {
                                    cout << "--";
                                }
                            }
                        }
                    }
                }
                cout << endl;
                wybor=getch();
                if(wybor==72 && xyWaz[1] < wys+1)
                {
                    gora(xyWaz);
                }
                 if(wybor==80 && xyWaz[1] > wys-1)
                {
                    dol(xyWaz);
                }
                 if(wybor==77)
                {
                    prawo(xyWaz);
                }
                 if(wybor==75)
                {
                    lewo(xyWaz);
                }
                if(xyWaz[0]==xyPunkt[0] && xyWaz[1]==xyPunkt[1])
                {
                    tab[xyPunkt[0]][xyPunkt[1]]='p';
                        //LOSOWANIE WSP PUNKTU
                        do
                        {
                            xyPunkt.push_back(rand()%(szer-1));
                            xyPunkt.push_back(rand()%(wys-1));
                    
                        } while (tab[xyPunkt[0]][xyPunkt[1]]!='p');

                        //USTALANIE POZYCJI PUNKTU

                        tab[xyPunkt[0]][xyPunkt[1]]='x';    
                }

                
        Sleep(szyb);
   }while(wybor!=13);
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl;
    system("pause");
}
 //ZWALNIANIE PAMIECI ZAREZERWOWANEJ DLA TABLICY
void zwolnijPamiec(char **&tab, int szer)
{  
    for(int i=0; i<szer; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
}

void gora(vector<int> &gora)
{
    gora[1]--;
}
void dol(vector<int> &dol)
{
    dol[1]++;
}
void prawo(vector<int> &prawo)
{
    prawo[0]++;
}
void lewo(vector<int> &lewo)
{
    lewo[0]--;
}