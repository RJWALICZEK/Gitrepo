#include <string>

class Item{
    private:
    int power;
    std::string name;
    public:
    Item(std::string nam = "unnamed", int pow = 0);
};