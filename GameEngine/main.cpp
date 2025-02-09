#include <iostream>
#include <windows.h>
#include "gameManager.h"
#include "mob.h"
#include "item.h"
#include <conio.h>

int main()
{
    int choice;

    Mob player("Knight", 90, 8);
   Game game;
   do{
    game.print();
    player.viewInfo();
    if(kbhit())
    {
       std::cout << "\a";
    }
    system("cls");
   }while(true);


    std::cout << std::endl;
    system ("pause");
    return 0;
    
}
