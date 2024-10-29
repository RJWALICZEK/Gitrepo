#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    
    int szer = 10;
    int wys = 10;
    int tab[szer][wys];
    for(int i=0; i<szer; i++)
                        {
                            cout << "--";
                            if(i==szer-1)
                            {
                                cout << endl;
                                for(int j=0; j<wys; j++)
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
                                    if(j==wys-1)
                                    {
                                        for (int k=0; k<szer; k++)
                                        {
                                            cout << "--";
                                        }
                                    }
                                }
                            }
                        }

    system("pause");
    return 0;
}