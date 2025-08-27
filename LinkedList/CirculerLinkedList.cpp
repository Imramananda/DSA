#include <iostream>
#include <memory>
using namespace std;

class Node
{
public:
    Node(int d)
    {
        data = d;
        link = nullptr;
    }
    int data;
    Node *link;
};

class LinkedList
{
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to prevent memory leaks
    ~LinkedList()
    {
        Node *current = head;
        while (current->link != head)
        {
            Node *next = current->link;
            delete current;
            current = next;
        }
    }

    void createList(const int &data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = tail = node;
            node->link = head;
        }
        else
        {
            tail->link = node;
            tail = node;
            tail->link = head;
        }
    }

    void printList() const
    { // Made const as it doesn't modify the list
        cout << "Here is the Linked List -> ";
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << " " << temp->data << "->";
            temp = temp->link;
        } while (temp != head);
        cout << "head" << endl;
    }

private:
    Node *head;
    Node *tail;
};

int main()
{
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.createList(i);

    list.printList();

    return 0;
}