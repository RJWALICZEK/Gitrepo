#include <iostream>
#include <stack>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;


class Calc
{
    private:
    stack<int>memo;

    public:
    Calc() = default;
   ~Calc() = default;
   void push(int value);
   void pop();
   void print();
   void math(int op);
};

int main(){

Calc c1;
string s;
int sum;
char value;


do
{
    cout << "\tONP" << endl;
    cout << s << "  >  ";
    c1.print();
    cout << endl;
    value=getch();
    if(value>=48 && value<=57)
    {
        s += to_string(value-48);
    }
    else if(value==13)
    {
        if(s == "")
        {
            c1.push(0);
        }
        else
        {
            sum=stoi(s);
            c1.push(sum);
            sum=0;
            s = "";
        }
    }
    else if(value==8)
    {
        c1.pop();
    }
    else if(value==42||value==43||value==45||value==47)
    {
        c1.math(value);
    }
  
    
    system("cls");
}while(value!=27);
    system("pause");
    return 0;
}

void Calc::push(int value){

    this->memo.push(value);
}
void Calc::print()
{
    stack<int>mem = this->memo;
    int bufor = 0;
    int *iter= nullptr;
    if(!mem.empty())
    {
        iter=new int [(mem.size())];

        while(!mem.empty())
        {
            iter[bufor]=mem.top();
            mem.pop();
            bufor++;
        }
        for(int i=0; i<bufor; i++)
        {
            cout << iter[i] << " ";
        }
    }
    else{
        cout << ":";
    }
    delete [] iter;
}

void Calc::pop()
{
    if(!this->memo.empty())
    {
        this->memo.pop();
    }
}

void Calc::math(int op)
{
    int temp;
    if(this->memo.size()>1)
    {
            switch(op)
            {
                case 43:
                {
                    temp=this->memo.top();
                    this->memo.pop();
                    this->memo.top() += temp;
                    break;
                }
                case 45:
                {
                    temp=this->memo.top();
                    this->memo.pop();
                    this->memo.top() -= temp;
                    break;
                }
                case 42:
                {
                    temp=this->memo.top();
                    this->memo.pop();
                    this->memo.top() *= temp;
                    break;
                }
                case 47:
                {
                    if(this->memo.top()>0)
                    {
                        temp=this->memo.top();
                        this->memo.pop();
                        this->memo.top() /= temp;
                    }
                    else
                    {
                        cout << "\t 0 error" << endl;
                        Sleep(500);
                    }
                    break;
                }
            }
    }
}