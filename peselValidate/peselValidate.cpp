#include <iostream>
#include <string>

using namespace std;

bool isOk(string pesel);
bool validate(string pesel);

int main(){

    string pesel;
    
    do{
        
        cout << "Insert PESEL number : ";
        getline(cin,pesel);
    }while(!isOk(pesel));

    if(validate(pesel))
    {
        cout << "PESEL OK";
    }
    else
    {
        cout << "Verification failure";
    }

    cout << endl;
    system("pause");
    return 0;
}

bool isOk(string pesel)
{
    int test=0;
    if(pesel.length()==11)
    {
        for(int i=0; i<pesel.length(); i++)
        {
            if(isdigit(pesel[i]))
            {
                test++;
            }
        }
        if(test==pesel.length())
        {
            return true;
        }
    }
        return false;
    
}

bool validate(string pesel)
{
    int key [10] = {1,3,7,9,1,3,7,9,1,3};
    int controlNum;
    int sum=0;

    for (int i = 0; i < 10; i++)
    {
        sum += ((pesel[i]-'0')*key[i]);
    }
    controlNum=10-(sum%10);
    if(controlNum==(pesel.back()-'0'))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}