#include<iostream>
using namespace std;

template<class T>
class StackArray
{
    public:
    StackArray(int size)
    {
        capacity = size;
        arr =new T[size];
        top = -1;
    }
    void push(T element)
    {
        if(isFulled())
        {
            cout<<"stack is fulled "<<endl;
        }
        else
        {
            arr[++top]=element;
        cout<<"pusing "<<endl;
        } 
    }
    void pop()
    {
        if(isEmty())
        cout<<"Stack is empty "<<endl;
        cout<<"pop -> "<< arr[top--]<<endl;
    }
    bool isEmty() const
    {
        return top == -1;
    }
    bool isFulled() const
    {
       return top == capacity-1;
    }
    void disaply()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<"stack element : "<<arr[i]<<endl;
        }
    }
    ~StackArray()
    {
        cout<<"Destring the dynamic memory "<<endl;
        delete []arr;
    }
    private:
    T *arr;
    int capacity;
    int top;

};

int main()
{
    StackArray<int> sa(5);
    sa.push(1);
    sa.push(12);
    sa.push(13);
    sa.push(15);
    sa.push(14);
    sa.push(50);
    sa.disaply();
    sa.pop();
    sa.disaply();
    return 0;
}