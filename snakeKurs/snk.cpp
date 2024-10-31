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

//pozycja weza
struct Pozycja
{
    int x;
    int y;

};

//DEKLARACJA FUNKCJI
int menu1(int m);
int menu2(int m);
void rekordy();
void latwy();
void sredni();
void trudny();
void zwolnijPamiec(char **&tab, int szer);
void pole(char **&tab,int szer,int wys, int szyb);

void gora(Pozycja &p);
void dol(Pozycja &p);
void prawo(Pozycja &p);
void lewo(Pozycja &p);


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

    szerokosc = 18;
    wysokosc = 18;
    szybkosc= 3;

        pole(stol, szerokosc, wysokosc, szybkosc);

    zwolnijPamiec(stol,szerokosc);

}
//POZIOM SREDNI
void sredni()
{
    char **stol = nullptr;

    szerokosc = 15;
    wysokosc = 15;
    szybkosc= 6;
    
        pole(stol,szerokosc, wysokosc, szybkosc);


    zwolnijPamiec(stol,szerokosc);
    
}
//POZIOM TRUDNY
void trudny()
{
    char **stol = nullptr;
    
    szerokosc = 10;
    wysokosc = 10;
    szybkosc = 9;

        pole(stol, szerokosc, wysokosc, szybkosc);



    zwolnijPamiec(stol, szerokosc);
     
}
//FUNKCJA TWORZACA POLE DO GRY
void pole(char **&tab,int szer,int wys,int szyb)
{
    system("cls");

    //LICZNIK PUNKTOW
    int punkty=0;

    //DEKLARACJA TABLICY
    tab=new char*[szer];
     
     for (int i=0; i<szer; i++)
    {
        tab[i]=new char[wys];
    }
    
     //DEKLARACJA I LOSOWANIE WSP WEZA
    Pozycja waz;
    waz.x = rand()%(szerokosc-1);
    waz.y = rand()%(wysokosc-1);

   
    
    //DEKLARACJA I LOSOWANIE WSP PUNKT
    Pozycja punkt;
    do
    {
        punkt.x = rand()%(szerokosc-1);
        punkt.y = rand()%(wysokosc-1);
                    
    } while (tab[punkt.x][punkt.y]!=tab[waz.x][waz.y]);
    
    

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
                         tab[waz.x][waz.y]='w';

                        //USTALANIE POZYCJI PUNKTU

                        tab[punkt.x][punkt.y]='x';    
                        

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
                                    
                                    if(j==2)
                                    {
                                        cout << "|      punkty : " << punkty << endl;
                                    }
                                    else
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
                        cout << "   q : wyjscie     p : pauza" <<endl;
                        wybor=getch();
                        if(wybor==72)
                        {
                            gora(waz);
                        }
                        else if(wybor==80)
                        {
                            dol(waz);
                        }
                        else if(wybor==77)
                        {
                            prawo(waz);
                        }
                        else if(wybor==75)
                        {
                            lewo(waz);
                        }
                        if(wybor=='p')
                        {
                            system("pause");
                        }
                        if(waz.x==punkt.x && waz.y==punkt.y)
                        {
                            punkty++;
                            tab[punkt.x][punkt.y]='p';
                            
                                //LOSOWANIE WSP PUNKTU
                                do
                                {
                                    punkt.x = (rand()%(szer-1));
                                    punkt.y = (rand()%(wys-1));
                            
                                } while (tab[punkt.x][punkt.y]!='p');

                                //USTALANIE POZYCJI PUNKTU

                                tab[punkt.x][punkt.y]='x';    
                        }
                        if(waz.x==szerokosc)
                        {
                            waz.x=0;
                        }
                        if(waz.x==-1)
                        {
                            waz.x=szerokosc-1;
                        }
                        if(waz.y==wysokosc)
                        {
                            waz.y=0;
                        }
                        if(waz.y==-1)
                        {
                            waz.y=wysokosc-1;
                        }

        }while(wybor!='q');
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

void gora(Pozycja &p)
{
    p.y--;

}
void dol(Pozycja &p)
{
   p.y++;
}
void prawo(Pozycja &p)
{
    p.x++;
}
void lewo(Pozycja &p)
{
    p.x--;
}