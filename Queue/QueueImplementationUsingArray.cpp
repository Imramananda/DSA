#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
    Queue(int s)
    {
        capacity = s;
        front = back = -1;
        arr = new T[s];
        size = 0;
    }
    void push(T data)
    {
        if (isFull())
        {
            cout << "It is fulled " << endl;
            return;
        }
        else
        {
            cout << "Getting push from here : " << data << endl;
            back = (back + 1) % capacity;
            arr[back] = data;
            size++;
            if (front == -1)
                front++;
        }
    }
    void disaplay()
    {
        cout << "Here is the Queue element stored ::: " << endl;
        for (int idx = front; idx <= back; idx++)
        {
            cout << "Items : " << arr[idx] << endl;
        }
    }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }
    void pop()
    {
        if (isEmpty())
        {
            cout << "It is already emty , cant do pop " << endl;
        }
        else
        {
            front = (front + 1) % capacity;
            size--;
            if (size == 0)
                front = back = -1;
        }
    }
    ~Queue()
    {
        cout << "dtor " << endl;
        delete[] arr;
    }

private:
    int capacity;
    int front;
    int back;
    int size;
    T *arr;
};

int main()
{
    cout << "From main function -> " << endl;
    Queue<int> obj(5);
    for (int i = 0; i <= 40; i = i + 5)
    {
        obj.push(i);
    }
    obj.disaplay();
    obj.pop();
    obj.disaplay();

    return 0;
}