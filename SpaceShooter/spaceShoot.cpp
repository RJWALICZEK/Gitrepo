#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>



using namespace std;

//globar variables
    char choice;
    int op=1;
//objects
struct Object
{
    int x;
    int y;
};
//functions

void field();
int menu();
void makeField(char **&tab, int w, int h);
void deleteField(char **&tab, int w);
void refreshField(char **&tab, int w, int h);
//controls
void left(Object &s);
void right(Object &s);
void shot(Object *&m, Object &x);
//*******


int main()
{
    srand(time(NULL));
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
    Object ship;
    Object *missle=nullptr;
    Object *target=nullptr;
    ship.x=width/2;
    ship.y=height-2;
    makeField(field, width, height);

    target = new Object;
    target->x=rand()%width;
    target->y=3;
    
            do
            {   
                
                
               system("cls");
            //MOVEMENT DETECT              
                if(kbhit())
                {
                    choice=getch();
                    if(choice==75 && ship.x>0)
                    {
                        left(ship);
                    }
                    else if(choice==77 && ship.x<width-1)
                    {
                        right(ship);
                    }
                    else if(choice==32 && missle==nullptr)
                    {
                        missle=new Object;
                        shot(missle,ship);
                    }
                }
                //CHECKING MISSLE STATUS
                if(missle != nullptr)
                {
                    missle->y--;
                    if(missle->y<0)
                    {
                        delete missle;
                        missle = nullptr;
                    }
                }
                
                // REFRESH FIELD, ADDING OBJECTS
                refreshField(field, width, height);
                field[ship.x][ship.y]='A';
                if(missle!=nullptr)
                {
                    field[missle->x][missle->y]='*';
                }    
                //checking target status
                if (target != nullptr)
                {
                    field[target->x][target->y] = 'V';
                }



                // DRAWING GAME FIELD
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
                                        cout << " ";
                                    }
                                    if(field[l][j]=='A')
                                    {
                                        cout << "A";
                                    }
                                    if(field[l][j]=='*')
                                    {
                                        cout << "*";
                                    }
                                    if(field[l][j]=='V')
                                    {
                                        cout << "V";
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
                    //Colision detect
                    if (missle != nullptr && target->x == missle->x && target != nullptr && target->y==missle->y)
                    {
                        delete target;
                        target = nullptr;
                        delete missle;
                        missle = nullptr;
                        target = new Object;
                        target->x=rand()%width;
                        target->y=3;
                    }
                    
                //ADITIONAL INFORMATIONS
                    cout << endl << "X: "<< ship.x<< "   Y: " << ship.y;
                    if(missle!=nullptr)
                    {
                        cout << "\tmX: "<< missle->x<< "   mY: " << missle->y << endl;
                    }
                    
                Sleep(50);

                
            }while(choice!='q');

        deleteField(field,width);


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
void refreshField(char **&tab, int w, int h)
{
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            tab[i][j] = 'o';
        }
    }
}
void deleteField(char **&tab, int w)
{
    for(int i=0; i<w; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
    tab = nullptr;

}

void left(Object &s)
{
    s.x--;
}
void right(Object &s)
{
    s.x++;
}
void shot(Object *&m, Object &x)
{
    m->x =  x.x;
    m->y =  x.y-1;
}