#include <iostream>

using namespace std;

long int factorial(int n);

int main()
{

    cout << factorial(5);

    return 0;
}

long int factorial(int n)
{
    if (n==0) { return 1; }
    else { return n*factorial(n-1); } 
}