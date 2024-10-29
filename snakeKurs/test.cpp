#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int wysokosc = 10;
    int szerokosc = 10;
    vector <int> xy;

    xy.push_back(rand()%wysokosc);
    xy.push_back(rand()%szerokosc);


    cout << "x " << xy[0] << "   y " << xy[1] << endl;
    system("pause");
    return 0;
}