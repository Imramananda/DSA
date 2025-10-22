#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node(T d)
    {
        data = d;
        link = nullptr;
    }
    T data;
    Node *link;
};

template <class T>
class Queue
{
public:
    Queue()
    {
        rear = front = nullptr;
    }

    void push(T d)
    {
        if (front == nullptr)
        {
            Node<T> *node = new Node<T>(d);
            front = node;
            rear = node;
            cout << "Element : " << d << endl;
        }
        else
        {
            Node<T> *node = new Node<T>(d);
            rear->link = node;
            rear = node;
            cout << "Element else : " << d << endl;
        }
    }
    void Display()
    {
        cout << "Element : ";
        Node<T> *tmp = front;
        while (tmp != nullptr)
        {
            cout << "->" << tmp->data;
            tmp = tmp->link;
        }
        cout << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queuc is empty " << endl;
            return;
        }
        else
        {
            Node<T> *tmp = front;
            front = front->link;
            delete[] tmp;
        }
    }
    ~Queue()
    {
        while (!isEmpty())
            pop();
    }
    bool isEmpty()
    {
        return front == nullptr;
    }

private:
    Node<T> *front;
    Node<T> *rear;
};

int main()
{
    Queue<int> obj;
    for (int i = 1; i <= 50; i = i + 5)
    {
        obj.push(i);
    }
    obj.Display();
    obj.pop();
    obj.Display();
    return 0;
}
