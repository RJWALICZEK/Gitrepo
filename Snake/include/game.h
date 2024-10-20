#include <conio.h>
#include <iostream>



class Menu
{
private:
    void credits();
    unsigned int selectedOption;
    bool flag;
protected:
    public:

        Menu(unsigned int selectOp = 1,bool flag = true);
        void displayMenu();
        void SelectDifficulty();
        void getChoice();

        ~Menu()=default;

};


class Field
{
private:
    unsigned int fieldWidth;
    unsigned int fieldHeigth;
    unsigned int gameSpeed;
    unsigned int gamePoints;
    int** field;
public:
   Field(unsigned int width = 10, unsigned int height = 10, unsigned int speed=10, unsigned int points = 0);
    void setEasy();
    void setMedium();
    void setHard();
    void printField();

    ~Field();
};







