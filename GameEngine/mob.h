#include <iostream>

class Mob
{
    private:
    
    public:
    virtual void metoda()
    {
        std::cout << "Mob::metoda\n";
    }

};
class Player : public Mob
{
    private:

    public:
    virtual void metoda()
    {
        std::cout << "Player::metoda\n";
    }

};
class Npc:private Mob
{
    private:

    public:

};