#include "game.h"
#include <conio.h>
#include <iostream>

using namespace std;


Menu::Menu(unsigned int selectOp,bool flag)
{
    selectedOption = selectOp;
    flag = flag;
}

void Menu::displayMenu()
{

    do{
    system("cls");
    cout << "\t\t SNAKE \t\t\n\n\n";
    cout <<(this->selectedOption==1 ? "\t -> " : "\t    ") << "Start" << endl;
    cout <<(this->selectedOption==2 ? "\t -> " : "\t    ") << "Ranking" << endl;
    cout <<(this->selectedOption==3 ? "\t -> " : "\t    ") << "Credits" << endl;
    cout <<(this->selectedOption==4 ? "\t -> " : "\t    ") << "Exit" << endl;

     int choice=getch();

                if ( choice==72 )
                    {
                        if(this->selectedOption>1)
                        {
                            this->selectedOption--;
                        }

                    }
                else if (choice == 80)
                    {
                        if(this->selectedOption<4)
                        {
                            this->selectedOption++;
                        }

                    }
                else if ( choice == 13)
                {
                    switch(this->selectedOption)
                    {
                        case 1: {this->SelectDifficulty(); flag=false ; break;}
                        case 2: {cout << "View Ranking..."; flag=false ; break;}
                        case 3: {this->credits(); flag=false ; break;}
                        case 4: {exit (0);}
                    }
                }

    }while(flag=!false);
}
void Menu::SelectDifficulty()
{


    do{

    system("cls");
    cout << "\t\t SNAKE \t\t\n\n\n";
    cout <<(this->selectedOption==1 ? "\t -> " : "\t    ") << "Easy (20x40 , speed 10)" << endl;
    cout <<(this->selectedOption==2 ? "\t -> " : "\t    ") << "Medium (15x30 , speed 15)" << endl;
    cout <<(this->selectedOption==3 ? "\t -> " : "\t    ") << "Hard (10x15 , speed 20)" << endl << endl;
    cout <<(this->selectedOption==4 ? "\t -> " : "\t    ") << "Back" << endl;

    int choice=getch();



     if ( choice==72 )
                    {
                        if(this->selectedOption>1)
                        {
                            this->selectedOption--;
                        }

                    }
                else if (choice == 80)
                    {
                        if(this->selectedOption<4)
                        {
                            this->selectedOption++;
                        }

                    }
                else if ( choice == 13)
                {
                    switch(this->selectedOption)
                    {
                        case 1: {Field f1; f1.setEasy(); f1.printField(); flag=false; break;}
                        case 2: {Field f2; f2.setMedium(); f2.printField(); flag=false; break;}
                        case 3: {Field f3; f3.setHard(); f3.printField(); flag=false; break;}
                        case 4: {displayMenu(); break;}
                    }
                }
            }while(flag=!false);
}

void Menu::credits()
{
    string credits[8] = {"creative director     --  Rafal Waliczek",
    "production director   --  Rafal Waliczek","art director          --  Rafal Waliczek",
    "technical director    --  Rafal Waliczek","technical director    --  Rafal Waliczek",
    "technical director    --  Rafal Waliczek","animation director    --  Rafal Waliczek",
    "level design director --  Rafal Waliczek"};
    system("cls");
    for(int i=0; i<sizeof(credits)/sizeof(string);i++)
    {
        cout<<"\n\t\t"<<credits[i]<<"\n\n";
    }
    system("pause");
    this->displayMenu();


}

