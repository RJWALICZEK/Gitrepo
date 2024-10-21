#include <iostream>

using namespace std;

struct partsBase{

    string name;
    int quantity;
    int price;
    partsBase *next;

};

int main()
{
    partsBase *head=nullptr;
    partsBase *temp=nullptr;
    partsBase *newPart=nullptr;

    string nam;
    unsigned int q, p;
    char op;

    do{
        newPart=new partsBase;
        cout << "Enter part name : ";
        cin >> nam;
        cout << "Enter quantity : ";
        cin >> q;
        cout << "Set price : ";
        cin >> p;
        if(head==nullptr)
        {
            head=newPart;
            head->name=nam;
            head->quantity=q;
            head->price=p;
            head->next=nullptr;
            temp=head;
        }
        else
        {
            newPart->name=nam;
            newPart->price=p;
            newPart->quantity=q;
            newPart->next=nullptr;
            temp->next=newPart;
            temp=newPart;

        }


            cout << "Want to add new item? (y/n) >> ";
            cin >> op;


    }while(op!='n');


    temp = head;
    unsigned int iter=1;
    while (temp != nullptr)
    {
        cout << iter << ". { part name : " << temp->name << ", quantity : " << temp->quantity << ", price : " << temp->price << "$ }" << endl;
        iter++;
        temp = temp->next;
    }

    temp = head;
    partsBase *toDelete;
    while(temp != nullptr)
    {
        toDelete = temp;
        temp=temp->next;
        delete toDelete;
    }

    return 0;
}
