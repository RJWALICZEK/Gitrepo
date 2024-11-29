#include <iostream>
#include <string>


using namespace std;


int main() {

 string pesel = "12345678";


cout << endl;

 cout << pesel.back();
 cout << "\n" << pesel.front();

cout << endl << endl << (pesel.front()-'0') + (pesel.back()-'0');

cout << endl;

 system("pause");

 return 0;
}