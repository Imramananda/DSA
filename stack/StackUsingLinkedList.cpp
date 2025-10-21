#include <iostream>
#include <memory>
using namespace std;

template <class T>
class Node
{
public:
    Node(T d)
    {
        link = nullptr;
        data = d;
    }
    Node *link;
    T data;
};

template <class T>
class Stack
{
public:
    Stack(int size)
    {
        cout << "ctor " << endl;
        top = nullptr;
    }
    void push(T d)
    {
        cout<<"data is pushing : "<<d<<endl;
        Node<T> *node = new Node<T>(d);
        node->link = top;
        top = node;
    }
    void display()
    {
        while (top != nullptr)
        {
            cout << " ELement : " << top->data << endl;
            top = top->link;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            Node<T> *tmp = top;
            top = top->link;
            delete tmp;
        }
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    ~Stack()
    {
        if (!isEmpty())
            pop();
    }

private:
    Node<T> *head;
    Node<T> *top;
};

int main()
{
    cout << "Stack using linkedList " << endl;
    Stack<int> obj(5);
    for (int i = 1; i < 40; i = i + 5)
    {
        obj.push(i);
    }
    obj.display();
    obj.pop();
    obj.display();
    return 0;
}