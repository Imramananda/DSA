#include <iostream>
using namespace std;

template <class T>
class SharedPtr
{
public:
    SharedPtr()
    {
        cout << "ctor" << endl;
        ptr = new T;
        refCount = new int(1);
    }
    SharedPtr(const T &v)
    {
        cout << "parameter ctor" << endl;
        ptr = new T(v);
        refCount = new int(1);
    }

    SharedPtr(const SharedPtr &obj)
    {
        ptr = obj.ptr;
        refCount = obj.refCount;
        ++(*refCount);
        cout << "Rama copy construcotr " << (*refCount) << endl;
    }

    SharedPtr &operator=(const SharedPtr &obj)
    {
        if (this != &obj)
        {
            release();
            ptr = obj.ptr;
            refCount = obj.refCount;
            ++(*refCount);
        }
        cout << "copy assignment" << *(refCount) << endl;
        return *this;
    }
    SharedPtr(SharedPtr &&obj)
    {

        ptr = obj.ptr;
        obj.ptr = nullptr;
        refCount = obj.refCount;
        obj.refCount = nullptr;
        cout << "copy move " << *(refCount) << endl;
    }
    SharedPtr &operator=(SharedPtr &&obj)
    {
        if (this != &obj)
        {
            release();
            ptr = obj.ptr;
            obj.ptr = nullptr;
            refCount = obj.refCount;
            obj.refCount = nullptr;
            cout << " move assignmnet " << endl;
        }
        
        return *this;
    }
    ~SharedPtr()
    {
        cout << "dtor " << endl;
        release();
    }
    void release()
    {
        cout << "Release " << endl;
    }

private:
    T *ptr = nullptr;
    int *refCount;
    int data;
};

int main()
{
    SharedPtr<int> obj;
    SharedPtr<int> obj1 = obj;
    SharedPtr<int> obj2 = move(obj);

    cout << "-----------Shared pointer ------------ " << endl;
    SharedPtr so = obj1; // copy constructor
    SharedPtr<int> so1;
    so1 = obj2; // assignment operator
    so1 = move(obj);
    return 0;
}