#include <iostream>
#include <conio.h>
#include "gameManager.h"
#include "mob.h"

enum key { UP=72, DOWN=80, LEFT=75, RIGHT=77, ENTER=13, SPACE=32, ESC=27};

Game::Game(int w, int h)
: width(w) , height(h) {}

void Game::print()
{
    for(int i=0; i<width; i++)
    {
        if(i==0)
        {
            std::cout << "\xC9";
        }
        else if(i==width-1)
        {
            std::cout << "\xBB"; 
        }
        else
        std::cout << "\xCD";
    }
    std::cout << std::endl;
    for (int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(j==0 || j==width-1)
            {
                std::cout << "\xBA";
            }
            else////////////////////////////////////Game field display
           {
                /* if(player.getX()==i && player.getY()==j)
                {
                    std::cout << "\xDB";
                }
                else */
                std::cout <<" ";

            }
        }
        std::cout << std::endl;
    }
    for(int i=0; i<width; i++)
    {
        if(i==0)
        {
            std::cout << "\xC8";
        }
        else if(i==width-1)
        {
            std::cout << "\xBC"; 
        }
        else
        std::cout << "\xCD";
    }
}
/*void Game::input()
{
    int input=getch();
    switch(input)
    {
        case UP:
        {
            player.up();
            break;
        }
        case DOWN:
        {
            player.down();
            break;
        }
        case LEFT:
        {
            player.left();
            break;
        }
        case RIGHT:
        {
            player.right();
            break;
        } 
        default :
        break;
    }
} */