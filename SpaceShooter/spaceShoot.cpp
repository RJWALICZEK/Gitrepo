#include <iostream>
#include <conio.h>


using namespace std;

//globar variables
    char choice;
    int op=1;
//objects
struct object
{
    int x;
    int y;
};
//functions
void field();
int menu();
void makeField(char **&tab, int w, int h);

int main()
{

    while(true)
    {

        menu();

        switch(op)
        {
            case 1:
            {
                field();
                break;
            }
            case 2:
            {
                exit(0);
            }
        }

    }

    
    return 0;
}

int menu()
{
    
    do
    {
        system("cls");
        cout << "\t\t MENU\n\n" << endl;
        cout << (op == 1 ? "\tPLAY" : "\t play") << endl;
        cout << (op == 2 ? "\tEXIT" : "\t exit") << endl;

        choice=getch();

        if(choice==72 && op>1)
        {
            op--;
        }
        if(choice == 80 && op<2)
        {
            op++;
        }
    
    }while(choice!=13);
    
    return op;

}

void field()
{
    char **field;
    int height = 20;
    int width = 60;
    string space = "                                                            ";
    makeField(field, width, height);

    for(int i=0; i<width; i++)
                        {
                            cout << "-";
                            if(i==width-1)
                            {
                                cout << endl;
                                for(int j=0; j<height; j++)
                                {
                                    cout << "|" ;

                                for (int l=0; l<width-1; l++)
                                {
                                    if(field[l][j]=='o')
                                    {
                                        cout << ".";
                                    }
                                }
                                
                                if(j==2)
                                {
                                        cout << "|      pkt : " << endl;
                                    }                                    else
                                cout << "|" <<endl;
                                
                                if(j==height-1)
                                {
                                    for (int k=0; k<width; k++)
                                    {
                                        cout << "-";
                                    }
                                }
                            }
                        }
                    }


    system("pause");

}

void makeField(char **&tab, int w, int h)
{
    tab = new char*[w];
    for(int i=0; i<w; i++)
    {
        tab[i]=new char[h];
    }
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            tab[i][j] = 'o';
        }
    }

}