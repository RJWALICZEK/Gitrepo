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

//pozycja obiektow
struct PozycjaWaz
{
    //wsp obiektu
    int x;
    int y;
    //historia pozycji obiektu
    int historiaX[1000];
    int historiaY[1000];
    //licznik cykli gry
    int ile = 0 ;
    //dlugosc weza
    int dlugosc = 3;
};
struct PozycjaPunkt
{
    int x;
    int y;
};


//DEKLARACJA FUNKCJI
//menu
int menu1(int m);
int menu2(int m);
void rekordy();
//poziom trudnosci
void latwy();
void sredni();
void trudny();
//******
void zwolnijPamiec(char **&tab, int szer);
void pole(char **&tab,int szer,int wys, int szyb);
//sterowanie
void gora(PozycjaWaz &p);
void dol(PozycjaWaz &p);
void prawo(PozycjaWaz &p);
void lewo(PozycjaWaz &p);


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

    szerokosc = 36;
    wysokosc = 18;
    szybkosc= 3;

        pole(stol, szerokosc, wysokosc, szybkosc);

    zwolnijPamiec(stol,szerokosc);

}
//POZIOM SREDNI
void sredni()
{
    char **stol = nullptr;

    szerokosc = 30;
    wysokosc = 15;
    szybkosc= 2;
    
        pole(stol,szerokosc, wysokosc, szybkosc);


    zwolnijPamiec(stol,szerokosc);
    
}
//POZIOM TRUDNY
void trudny()
{
    char **stol = nullptr;
    
    szerokosc = 20;
    wysokosc = 10;
    szybkosc = 1;

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
    PozycjaWaz waz;
    waz.x = rand()%(szerokosc-1);
    waz.y = rand()%(wysokosc-1);

  /*  waz.x = 10;
    waz.y = 10;
            */   
    
    //DEKLARACJA I LOSOWANIE WSP PUNKT
    PozycjaPunkt punkt;
    do
    {
        punkt.x = rand()%(szerokosc-1);
        punkt.y = rand()%(wysokosc-1);
                    
    } while (tab[punkt.x][punkt.y]!=tab[waz.x][waz.y]);
    
    

                    //ZAPELNIANIE TABLICY "p" = PUSTE POLE
                        for(int i=0; i<szer; i++)
                        {
                            for(int j=0; j<wys; j++)
                            {
                                tab[i][j] = 'p';
                            }
                        }
//////////////////////////////////////////////////////////////////////////
/////////--------------------------GRA PETLA----------------------------------

    for(int i=3; i>0; i--)
    {
        cout << "\n\n\n\n\n\n\t\t" << i ;
        Sleep(1000);
        system("cls");
    }
            wybor=rand()%4;

    switch(wybor)
    {
        case 0: wybor=72;break;
        case 1: wybor=75;break;
        case 2: wybor=77;break;
        case 3: wybor=80;break;
    }

    do
        {
           
            system("cls");
           
        /*    waz.historiaX[waz.ile]=waz.x;
            waz.historiaY[waz.ile]=waz.y;
            cout << waz.x << endl;
            cout << waz.y << endl;
            cout << waz.historiaX[waz.ile]<<endl;
            cout << waz.historiaY[waz.ile]<<endl; 
            cout << waz.ile<<endl;
            waz.ile++;
                        
                    */
                        

                        
                        //sprawdza czy klawisz zostal wcisniety
                    if(kbhit())
                    {
                        wybor=getch();                       
                            
                    }
                    //Instrukcje dla wcisnietego klawisza
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
                            


                    
                        //ustalanie pozycji węża po kolizji ze sciana 
                        if(waz.x<0)
                        {
                            waz.x=szerokosc-2;
                        }
                        else if(waz.x>szerokosc-2)
                        {
                            waz.x=0;
                        }
                        if(waz.y==wysokosc)
                        {
                            waz.y=0;
                        }
                        else if(waz.y==-1)
                        {
                            waz.y=wysokosc-1;
                        }

                         //USTALANIE POZYCJI WEZA

                         tab[waz.x][waz.y]='w';

                        //USTALANIE POZYCJI PUNKTU

                        tab[punkt.x][punkt.y]='x';    
                        

              ////////////////RYSOWANIE RAMKI POLA GRY////////////////
                        for(int i=0; i<szerokosc; i++)
                        {
                            cout << "-";
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
                                            cout << " ";
                                        }
                                        if(tab[l][j]=='w')
                                        {
                                            cout<<"w";
                                        }
                                        if(tab[l][j]=='x')
                                        {
                                            cout << "o";
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
                                            cout << "-";
                                        }
                                    }
                                }
                            }
                        }
                 ////////////////RYSOWANIE RAMKI POLA GRY ////////////////
                        cout << "   q : wyjscie     p : pauza" <<endl;

                        //Pauze
                          if(wybor=='p')
                            {                               
                                do
                                {    
                                    cout << "\t*Pauza\n\t  wcisnij kierunek*";
                                        wybor=getch();
                                }while(wybor=!75 && wybor!=72 && wybor!=77 && wybor!=80);
                            }
                   
                    

                    //kolizja weza z punktem "punkt"
                        if(waz.x==punkt.x && waz.y==punkt.y)
                        {
                            punkty++;
                            tab[punkt.x][punkt.y]='w';
                            
                                //LOSOWANIE WSP PUNKTU
                                do
                                {
                                    punkt.x = (rand()%(szer-1));
                                    punkt.y = (rand()%(wys-1));
                            
                                } while (tab[punkt.x][punkt.y]!='p');

                                //USTALANIE POZYCJI PUNKTU

                                tab[punkt.x][punkt.y]='x';    
                        }

                      
                        
        Sleep(szyb*50);
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


//Instrukcje dla wcisnietego klawisza
void gora(PozycjaWaz &p)
{
    p.y--;

}
void dol(PozycjaWaz &p)
{
   p.y++;
}
void prawo(PozycjaWaz &p)
{
    p.x++;
}
void lewo(PozycjaWaz &p)
{
    p.x--;
}