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
//field
void makeField(char **&tab, int w, int h);
void printField(char **&field, int width, int height, int pkt, int dmg);
void deleteField(char **&tab, int w);
void refreshField(char **&tab, int w, int h);
void explosion(char **&field,int width, int height, int pkt, int dmg);
//*********
void left(Object &s);
void right(Object &s);
void shot(Object *&m, Object &x);
//*******
void createMissleObject(Object *&o, int w);


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
    int height = 23;
    int width = 26;
    int pkt=0;
    int counter = 0;
    int dmg = 0;
    Object ship;
    Object *missle=nullptr;
    Object *target=nullptr;
    ship.x=width/2;
    ship.y=height-2;
    makeField(field, width, height);
    
    //CREATE TARGET OBJECT
    createMissleObject(target, width);
    
    
            do
            {   
                
                
               system("cls");
            //game frame counter
                    counter++;
   
            //MOVEMENT DETECT              
                if(kbhit())
                {
                    choice=getch();
                    if(choice==75 && ship.x>0)
                    {
                        left(ship);
                    }
                    else if(choice==77 && ship.x<width-2)
                    {
                        right(ship);
                    }
                    else if(choice==32 && missle==nullptr)
                    {
                        missle=new Object;
                        shot(missle,ship);
                    }
                }

                //COLISION DETECT
                    //for hit target
                    if (missle != nullptr && target->x == missle->x && target != nullptr && target->y==missle->y)
                    {
                        explosion(field,target->x,target->y,pkt,dmg);

                        delete target;
                        target = nullptr;
                        
                        delete missle;
                        missle = nullptr;
                        
                        counter=3;
                        createMissleObject(target,width);
                        pkt++;
                    }
                    //for target hit ground
                    else if(target != nullptr && counter==8)
                    {
                        target->y++;
                        if(target->y>height-1)
                        {
                            delete target;
                            target = nullptr;
                            
                            dmg++;
                            createMissleObject(target,width);
                        }
                        counter=0;
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
                 
                 printField(field, width, height, pkt, dmg);   
                                        
                //ADITIONAL INFORMATIONS
                    cout << endl << "X: "<< ship.x<< "   Y: " << ship.y << endl << "tX :" << target->x << "    tY: " << target->y << endl;
                    if(missle!=nullptr)
                    {
                        cout << "\tmX: "<< missle->x<< "   mY: " << missle->y << endl;
                    }
                    
                Sleep(1);

                
            }while(choice!='q' && dmg<3);
        cout << " \t KONIEC GRY\n";
        system("pause");
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

void printField(char **&field, int width, int height, int pkt, int dmg)
{
    for(int i=0; i<width+1; i++)
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
                                    if(field[l][j]=='0')
                                    {
                                        cout << "O";
                                    }
                                    if(field[l][j]=='#')
                                    {
                                        cout << "#";
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
                                        cout << "|   pkt : " << pkt << endl ;
                                    }
                                if(j==3)
                                    {
                                        cout << "|                dmg : " << dmg << endl ;
                                    }                                      
                                else
                                {
                                    cout << "|" <<endl;
                                }
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
}
void explosion(char **&field,int x, int y, int pkt, int dmg)
{
    char explosionFrame[3] = { '#', '*', '0' };
    
    for(int i=0; i<3; ++i)
    {
        //swap symbol around target place on field
        field[x][y]= explosionFrame[i];
        if (x > 0) field[x - 1][y] = explosionFrame[i];     // nad
        if (x < 23) field[x + 1][y] = explosionFrame[i];    // pod
        if (y > 0) field[x][y - 1] = explosionFrame[i];     // lewo
        if (y < 26) field[x][y + 1] = explosionFrame[i];    // prawo

        //print field witch explosion effect
        printField( field, 26, 23, pkt, dmg);
        //delay
        Sleep(5);

        //refresh field before next frame
        system("cls");
        
    }

}

void createMissleObject(Object *&o, int w)
{
    o = new Object;
    o->x=rand()%(w-1);
    o->y=3;

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