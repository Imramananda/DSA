#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
    Vector() : size(0), capacity(0), arr(nullptr) {};
    ~Vector() { delete[] arr; }

    void printVector()
    {
        cout<<"Vector : ";
        for(int i=0;i<size;i++)
        cout<<arr[i]<<" , ";
        cout<<endl;
    }
    void popBack()
    {
       if(size!=0)
       {
        size--;
       } 
    }
    void sizeAndCapacityOfVector()
    {
        cout<<"Size "<<size<<endl;
        cout<<"Capacity : "<<capacity<<endl;
    }
void pushBack(const T var)
{
    if (capacity == 0) {
        capacity = 1;
        arr = new T[capacity];
    }
    else if (size == capacity) {
        capacity = capacity * 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = var;
}

private:
    int size;
    int capacity;
    T *arr;
};

int main()
{
    Vector<int> obj;
    obj.pushBack(1);
    obj.pushBack(2);
    obj.pushBack(4);
    obj.pushBack(5);
    obj.pushBack(7);
    obj.printVector();
    obj.sizeAndCapacityOfVector();
    obj.popBack();
    return 0;
}