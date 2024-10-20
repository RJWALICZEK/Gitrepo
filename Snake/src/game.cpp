#include "game.h"
#include <conio.h>
#include <iostream>

using namespace std;

Field::Field (unsigned int width, unsigned int heigth, unsigned int speed, unsigned int points)
{
    fieldHeigth=heigth;
    fieldWidth=width;
    gameSpeed=speed;
    gamePoints=points;
}

void Field::setEasy()
{
    fieldHeigth=20;
    fieldWidth=40;
    gameSpeed=10;
    field = new int*[fieldHeigth];
    for (int i = 0; i < fieldHeigth; i++)
    {
        field[i] = new int[fieldWidth];
    }
}

void Field::setMedium()
{
    fieldHeigth=15;
    fieldWidth=30;
    gameSpeed=15;
    field = new int*[fieldHeigth];
    for (int i = 0; i < fieldHeigth; i++)
    {
        field[i] = new int[fieldWidth];
    }
}

void Field::setHard()
{
    fieldHeigth=10;
    fieldWidth=15;
    gameSpeed=20;
    field = new int*[fieldHeigth];
    for (int i = 0; i < fieldHeigth; i++)
    {
        field[i] = new int[fieldWidth];
    }
}

void Field::printField()
{
    char op;
    do{
            system("cls");
    cout <<"\n\t\t\t points: " << gamePoints;
    cout << endl << endl;
    for (int i=0; i<fieldHeigth; i++)
    {
         cout << endl;
        for (int j=0; j<fieldWidth; j++)
        {
            field[i][j]=0;
            cout<<field[i][j] ;

        }
    }
    cin >> op;
    }while(op!='q');
}

Field::~Field()
{
    for (int i=0; i<fieldHeigth; i++)
    {
        delete [] field[i];
    }
    delete [] field;
}
