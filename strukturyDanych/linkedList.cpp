#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* next;
};

class List
{
    private:
    Node* head;
    Node* temp;
    public:
    List();
    void newNode(int value);
    void addNode(Node* ptr);
    void rmNode(Node* ptr);
    void printList();
    bool isEmpty();
};
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
    cout << "\n\n\t***List is empty***";
   
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

int main()
{

    List myList;
    myList.newNode(1);
    myList.newNode(2);
    myList.newNode(3);
    myList.printList();

    system("pause");

    return 0;
}