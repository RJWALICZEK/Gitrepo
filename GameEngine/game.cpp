#include <iostream>
#include "gameManager.h"

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