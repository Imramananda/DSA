#include <iostream>
using namespace std;
template <typename T>

class SP
{
public:
    SP()
    {
        item = new T;
        refCount = new int(1);
        cout << "construction done" << endl;
    }
    SP(const T &value)
    {
        cout << "Rama parame" << endl;
        item = new T(value);
        refCount = new int(1);
        var = value;
    }

    SP(const SP &obj)
    {
        item = obj.item;
        refCount = obj.refCount;
        ++(*refCount);
        cout << "Rama copy construcotr " << (*refCount) << endl;
    }
    SP &operator=(const SP &obj)
    {
        if (this != &obj)
        {
            release();
            item = obj.item;
            refCount = obj.refCount;
            ++(*refCount);
        }
        cout << "Rama copy assignemnet  " << (*refCount) << endl;
        return *this;
    }

    SP(const SP &&obj) // not required
    {
        item = obj.item;
        refCount = obj.refCount;
        var = obj.var;
        obj.item = nullptr;
        obj.refCount = nullptr;
    }
    SP &operator=(const SP &&obj) // not required
    {
        if (this != &obj)
        {
            release();
            item = obj.item;
            obj.item = nullptr;
            refCount = obj.refCount;
            obj.refCount = nullptr;
            var = obj.var;
        }
        return *this;
    }
    void method()
    {
        cout << "Rama method functon var " << var << endl;
    }
    
    int useCount() const
    { 
        return *refCount;
    }

    ~SP()
    {
        release();
    }

    T *getPtr()
    {
        return item;
    }

    void release()
    {
        if (--(*refCount) == 0)
        {
            delete item;
            delete refCount;
            cout << "Onject deleted" << endl;
        }
    }
    void f()
    {
        cout<<"rama f"<<endl;
    }
    T* operator->()
    {
        return item;
    }
    T& operator*()
    {
        return *item;
    }
private:
    T *item;
    int *refCount = 0;
    int var;
};

int main()
{
    SP<int> obj;
    SP<int> obj1(55);
    cout << "obj1 : " << *(obj1.getPtr()) << endl;
    SP<int> obj2(100);
    obj1.method();
    obj2.method();

    cout << "-----------Shared pointer ------------ " << endl;
    SP so = obj1; // copy constructor
    SP<int> so1;
    so1 = obj2; // assignment operator

    cout<<*(obj)<<endl;
   // obj->f();

    return 0;
}