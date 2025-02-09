#include <string>

class Mob
{
    private:
    std::string name;
    int hp;
    int dmg;
    int posX,posY;
    bool status;
    public:
    Mob(std::string name = "", int hp = 0, int dmg= 0);
    void viewInfo();
    void attack(Mob& mob);
    bool isDead();
    void up();
    void down();
    void left();
    void right();
    int getX();
    int getY();

};
