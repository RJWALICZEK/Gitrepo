#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

char wybor;

int szerokosc, wysokosc, szybkosc;


int menu1(int m);
int menu2(int m);
void latwy();
void sredni();
void trudny();
void zwolnijPamiec(int **&tab, int szer);

void pole(int **&tab,int szer,int wys, string prz);


int main()
{
    int menu;

    while(true)
    {
         menu=1;

       

        switch(menu1(menu))
            {
                case 1:
                {
                    menu2(menu);
                    break;
                }
                case 2:
                {
                    exit(0);
                }
            } 

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
       
      

    }   



    return 0;
}

int menu1(int m)
{
     do
        {
            system("cls");
           cout << "\t\tSNAKE\n\n";
           cout << (m == 1 ? "->" : "  ") << "Graj" << endl;
           cout << (m == 2 ? "->" : "  ") << "wyjdz" << endl;
            wybor=getch();
            if(wybor==72 && m>1)
            {
                m--;
            }   
            if(wybor==80 && m<2)
            {
                m++;
            }     
        
        } while (wybor!=13);
        return m;
}

int menu2(int m)
{
    do
    {
     system("cls");
           cout << "\t\tSNAKE\n\n";
           cout << (m == 1 ? "->" : "  ") << "Latwy" << endl;
           cout << (m == 2 ? "->" : "  ") << "Sredni" << endl;
           cout << (m == 3 ? "->" : "  ") << "Trudny" << endl;
           cout << (m == 4 ? "->" : "  ") << "Powrot" << endl;
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

void latwy()
{
    int **stol = nullptr;
    string przerwa = "                                  ";
    szerokosc = 18;
    wysokosc = 18;
    szybkosc= 3;

    
    do
    {

        pole(stol, szerokosc, wysokosc, przerwa);


    }while(wybor=='q');

    zwolnijPamiec(stol,szerokosc);

}
void sredni()
{
    int **stol = nullptr;
    string przerwa = "                            ";
    szerokosc = 15;
    wysokosc = 15;
    szybkosc= 6;
    do
    {
        pole(stol,szerokosc,wysokosc,przerwa);

    } while (wybor=='q');

    zwolnijPamiec(stol,szerokosc);
    
}
void trudny()
{
    int **stol = nullptr;
    string przerwa = "                  ";
    szerokosc = 10;
    wysokosc = 10;
    szybkosc = 9;
    do
    {
        pole(stol, szerokosc, wysokosc, przerwa);

    } while (wybor=='q');

    zwolnijPamiec(stol, szerokosc);
     
}

void pole(int **&tab,int szer,int wys,string prz)
{
    system("cls");
    tab=new int*[szer];
    for (int i=0; i<szer; i++)
    {
        tab[i]=new int[wys];
    }

    for(int i=0; i<szerokosc; i++)
    {
        cout << "--";
        if(i==szerokosc-1)
        {
            cout << endl;
            for(int j=0; j<wysokosc; j++)
            {
                cout << "|" << prz << "|" <<endl;
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
    system("pause");
}

void zwolnijPamiec(int **&tab, int szer)
{
    for(int i=0; i<szer; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
}