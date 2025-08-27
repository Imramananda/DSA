#include <iostream>
#include <memory>
using namespace std;

class Node
{
public:
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to prevent memory leaks
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *n = current->next;
            delete current;
            current = n;
        }
    }

    void createList(const int &data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void insertATEnd(const int &data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void insertAtBeginig(const int &data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }

    void deleteAtpos(const int &pos)
    {
        if (head == nullptr)
            return; // Empty list
        if (pos < 0)
            return; // Invalid position
        Node *tmp = head;
        int i = 0;
        while (i < pos && tmp != nullptr)
        {
            tmp = tmp->next;
            i++;
        }
        if (tmp == nullptr)
            return;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
    }

    void printList() const
    { // Made const as it doesn't modify the list
        cout << "Here is the Linked List -> ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << " " << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    // void prinsizeOftList() const
    // { // Made const as it doesn't modify the list
    //     cout << "Here is the Linked List size ";
    //     Node *temp = head;
    //     while (temp != nullptr)
    //     {
    //         size++;
    //         cout << " " << temp->data << "->";
    //         temp = temp->next;
    //     }
    //     cout << size << "null" << endl;
    // }

private:
    Node *head;
    Node *tail;
    int size = 0;
};

int main()
{
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.createList(i);

    list.printList();

    list.insertATEnd(10);
    list.printList();
    list.insertAtBeginig(20);
    list.printList();
    list.deleteAtpos(3);
    list.printList();

    return 0;
}