#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    
    string przerwa = "                  ";
    int szerokosc = 10;
    int wysokosc = 10;
    int szybkosc = 9;
    int tab[szerokosc][wysokosc];

                for(int i=0; i<szerokosc; i++)
                {       tab[i][wysokosc]=i;
                    
                        for(int j=0; j<wysokosc; j++)
                        {
                            //tab[szerokosc][j] = j;
                        }
                }



                for(int i=0; i<szerokosc; i++)
                {
                  
                    for(int j=0; j<wysokosc; j++)
                    {
                       cout << tab[i][j] ;
                    }
                    cout << endl;
                }


    system("pause");
    return 0;
}