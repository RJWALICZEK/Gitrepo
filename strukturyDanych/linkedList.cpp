#include <iostream>

using namespace std;

//Node struct
struct Node{

    int data;
    Node* next;
};
//main classes
class List
{
    private:
    Node* head;
    Node* temp;
    void addNode(Node* ptr);
    bool isEmpty();
    public:
    List();
    void newNode(int value);    
    void rmNode(Node* ptr);
    void printList();
    ~List()
    {
       Node* current=head;
       while(current!=nullptr)
       {
            temp = current;
            current=temp->next;
            delete temp;
       }
       delete temp;
       delete head;
    }
    
};

class Menu: private List
{
    public:
        Menu() = default;
        void printMenu();
        void push();
        ~Menu() = default;
    

};
//////////////////////////////////////////////////////////

int main()
{

    List myList;
    Menu menu1;
    for(;;)
    {
        menu1.printMenu();

        system("cls");


    }

    system("pause");

    return 0;
}

///////////////class function define///////////////////////

/// for List
List::List()
{
    head=nullptr;
    temp=nullptr;
}
void List::newNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next=nullptr;
    addNode(newNode);
}
void List::addNode(Node* ptr)
{
    if(head==nullptr)
    {
        head=ptr;
        temp=head;
    }
    else
    {
        temp->next=ptr;
        temp=ptr;
            
    }
}
void List::printList()
{
    if(!isEmpty())
    {
        Node* current = head;
        do
        {
            cout << current->data << " ";
            current=current->next;
        } while (current!=nullptr);
    }
    else
    cout << "\t***List is empty***";
   
}
bool List::isEmpty()
{
    if(head==nullptr)
    {
        return true;
    }
    else
    return false;
}


/////// for Menu

void Menu::printMenu()
{
    int choice;
    int value;
        cout << "\t LINKED LIST";
        cout << "\n--------------------------\n";
        List::printList();
        cout << "\n--------------------------\n";
        cout << "1.Push\n2.Pop\n3.print\n\n4Exit\n>";
        cin >> choice;

        switch(choice)
        {
            case 1: push(); break;
            case 2: break;
            case 3: List::printList(); break;
            case 4: exit(0);
        }
}

void Menu::push()
{
    int value;
    system("cls");
    cout << "\t LINKED LIST\n\n\n\n";
    cout << "Enter value > ";
    cin >> value;
    List::newNode(value);    


}