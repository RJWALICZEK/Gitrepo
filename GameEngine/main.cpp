#include <iostream>
#include "gameManager.h"
#include "mob.h"

 
using namespace std;

int main()
{
    Mob mob;
    Player player;

    mob.metoda();
    player.metoda();

    Mob *ptr = new Player;

    ptr->metoda();

    
    cout << endl;
    system ("pause");
    return 0;
    
}
