#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    int data;
    unique_ptr<Node> link;
    Node(int d) : data(d), link(nullptr) {}
};

class LinkedList
{
public:
    
    LinkedList() : head(nullptr), tail(nullptr) {}
    void createList(int d)
    {
        auto node = make_unique<Node>(d);
        if (head.get() == nullptr)
        {
            head  = move(node);
            tail = head.get();
        }
        else{
            tail->link = move(node);
            tail = tail->link.get();
        }
    }

    void printList()
    {
        Node* tmp = head.get();
        while (tmp != nullptr)
        {
            cout << tmp->data << "->";
            tmp =tmp->link.get();
        }
        cout << "->Null" << endl;
    }

private:
    unique_ptr<Node> head;
    Node* tail;
};

int main()
{
    cout << "List is here" << endl;
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.createList(i);
    list.printList();
    return 0;
}