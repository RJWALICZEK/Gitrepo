#include <iostream>
#include <string>
#include "mob.h"
#include <windows.h>
#include <cstdlib>

Mob::Mob(std::string name, int hp, int dmg)
: name(name), hp(hp), dmg(dmg)
{
    status = true;
}

void Mob::viewInfo()
{   
    
    std::cout << "Name : " << name << "\nHp : " << hp
    << "\nDmg : " << dmg << "\nStatus : " << status << std::endl;
}

void Mob::attack(Mob& mob)
{
    srand(time(NULL));
    if(!mob.isDead() && !this->isDead())
    {
        std::cout << this->name << " attack " << mob.name << "\n";
        mob.hp -= rand()%this->dmg+1;
        Sleep(1000);
        if(mob.hp > 0)
        {
            std::cout << mob.name << " is dead\n";
            mob.status=false;
        }
    }
    else
    {
        std::cout << "Target seems to be dead\n";
    }
}
bool Mob::isDead()
{
    if(this->hp < 1)
    {
        return true;
    }
    else
    return false;
}
void Mob::up()
{
    this->posY++;
}
void Mob::down()
{
    this->posY--;
}
void Mob::left()
{
    this->posX--;
}
void Mob::right()
{
    this->posX++;
}
int Mob::getX()
{
    return posX;
}
int Mob::getY()
{
    return posY;
}