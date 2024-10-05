#include <iostream>

using namespace std;

wstring tetromino[7];

int rotate(int px, int py, int r)
{
    switch(r % 4)
    {
        case 0: return py*4+px; //for 0*
        case 1: return 12+py-(px+4); //for 90*
        case 2: return 15-(px*4)-px; // for 180*
        case 3: return 3-py+(px*4); //for 270* 
    }

}

int main(){

    //create assets
    tetromino[0].append(L"..x.");
    tetromino[0].append(L"..x.");
    tetromino[0].append(L"..x.");
    tetromino[0].append(L"..x.");

    tetromino[1].append(L"..x.");
    tetromino[1].append(L".xx.");
    tetromino[1].append(L".x..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".x..");
    tetromino[2].append(L".xx.");
    tetromino[2].append(L"..x.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L".xx.");
    tetromino[3].append(L".xx.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..x.");
    tetromino[4].append(L".xx.");
    tetromino[4].append(L"..x.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".xx.");
    tetromino[5].append(L"..x.");
    tetromino[5].append(L"..x.");

    tetromino[6].append(L"....");
    tetromino[6].append(L".xx.");
    tetromino[6].append(L".x..");
    tetromino[6].append(L".x..");

    system ("pause");
    return 0;
}