#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

char wybor;
int menu;
int szerokosc, wysokosc, szybkosc;
int *stol;

void menu1();
void menu2();
void latwy();
void sredni();
void trudny();

void pole(int **&tab,int szer,int wys);


int main()
{
    

    while(true)
    {
        menu=1;

        menu1();

        switch(menu)
            {
                case 1:
                {
                    menu2();
                    break;
                }
                case 2:
                {
                    exit(0);
                }
            } 

        switch(menu)
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

void menu1()
{
     do
        {
            system("cls");
           cout << "\t\tSNAKE\n\n";
           cout << (menu == 1 ? "->" : "  ") << "Graj" << endl;
           cout << (menu == 2 ? "->" : "  ") << "wyjdz" << endl;
            wybor=getch();
            if(wybor==72 && menu>1)
            {
                menu--;
            }   
            if(wybor==80 && menu<2)
            {
                menu++;
            }     
        
        } while (wybor!=13);
}

void menu2()
{
    do
    {
     system("cls");
           cout << "\t\tSNAKE\n\n";
           cout << (menu == 1 ? "->" : "  ") << "Latwy" << endl;
           cout << (menu == 2 ? "->" : "  ") << "Sredni" << endl;
           cout << (menu == 3 ? "->" : "  ") << "Trudny" << endl;
           cout << (menu == 4 ? "->" : "  ") << "Powrot" << endl;
            wybor=getch();
            if(wybor==72 && menu>1)
            {
                menu--;
            }   
            if(wybor==80 && menu<4)
            {
                menu++;
            }     
    } while (wybor!=13);
}

void latwy()
{
    szerokosc = 15;
    wysokosc = 15;
    szybkosc= 10;
    
    while(true)
    {
        pole(stol,szerokosc,wysokosc);

    }
    
}
void sredni()
{
     cout << "sredni  ";
    system("pause");
}
void trudny()
{
     cout << "trudny  ";
    system("pause");
}

void pole(int **tab,int szer,int wys)
{
    tab=new *int[szer];
    for (int i=0; i<szer; i++)
    {
        tab[szer]=new int[wys];
    }
}