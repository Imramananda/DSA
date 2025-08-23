#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
    Node(int d) : data(d), link(nullptr) {}
};

class LinkedList
{
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void createList(int d)
    {
        Node *node = new Node(d);
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->link = node;
            tail = node;
        }
    }

    void insetFromBegining(int d)
    {
        Node *node = new Node(d);
        node->link = head;
        head = node;
    }

    void insetFromEnd(int d)
    {
        Node *node = new Node(d);
        if (tail == nullptr)
            tail = node;
        tail->link = node;
        tail = node;
    }

    void insertAtPosition(int d, int pos)
    {
        Node *node = new Node(d);
        Node *tmp = head;
        Node *pre;
        for (int i = 0; i < 3; i++)
        {
            pre = tmp;
            tmp = tmp->link;
        }
        pre->link = node;
        node->link = tmp;
    }

    void deleteFromBegining()
    {
        if (head != nullptr)
        {
            Node *tmp = head;
            head = head->link;
            delete tmp;
        }
    }
    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->link == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *tmp = head;
        while (tmp->link->link != nullptr)
        {
            tmp = tmp->link;
        }
        delete tmp->link;
        tmp->link = nullptr;
    }

    void deleteFromPos(int pos)
    {
        if (head == nullptr)
            return;
        if (pos == 0)
            deleteFromBegining();
        Node *tmp = head;
        Node *del;
        for (int i = 0; i < pos; i++)
        {
            del = tmp;
            tmp = tmp->link;
        }
        del->link = tmp->link;
        delete tmp;
    }

    bool searchKey(int key)
    {
        if (head == nullptr)
            return false;
        Node *tmp = head;
        while (tmp->link != nullptr)
        {
            if (tmp->data == key)
                return true;
            else
                tmp = tmp->link;
        }
        return false;
    }

    void reverseList()
    {
        Node* cur = head;
        Node* pre = nullptr;
        Node* next = nullptr;
        while(cur!= nullptr)
        {
           next = cur->link;
           cur->link=pre;
           pre=cur;
           cur=next;
        }
        tail =head;
        head =pre;
    }

    bool detectLoop()
    {
        Node* fast =head;
        Node* slow =head;
        while(fast && fast->link!=nullptr)
        {
            slow=slow->link;
            fast=fast->link->link;
            if(fast == slow)
                return true;
        }
        return false;
    }

    int middleElement()
    {
        Node* fast =head;
        Node* slow =head;
        while(fast && fast->link!=nullptr)
        {
            slow=slow->link;
            fast=fast->link->link;
        }
        return slow->data;
    }

    void printList()
    {
        cout << "Here is the Linked List -> ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << " " << temp->data << "->";
            temp = temp->link;
        }
        cout << "null" << endl;
    }

    ~LinkedList()
    {
        Node *temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            Node *t = temp->link;
            delete temp;
            temp = t;
            i++;
        }
        cout << "Count of delete : " << i << endl;
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
    list.insetFromBegining(10);
    list.printList();
    list.insetFromEnd(20);
    list.printList();
    list.insertAtPosition(50, 3);
    list.printList();
    list.deleteFromBegining();
    list.printList();
    list.deleteFromEnd();
    list.printList();
    list.deleteFromPos(2);
    list.printList();
    cout<<"Data found in list : "<<list.searchKey(7)<<endl;

    list.reverseList();
    list.printList();
    cout<<"Loop detected in list : "<<list.detectLoop()<<endl; 
    cout<<"midle element of list "<<list.middleElement()<<endl;

    return 0;
}