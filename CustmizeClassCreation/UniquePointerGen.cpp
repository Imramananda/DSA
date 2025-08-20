#include <iostream>
using namespace std;
template <typename T>
class Unq
{
public:
    Unq() {
        ptr = new T(); // value-initialize T
    }
    Unq(const T& value) {
        ptr = new T(value); // initialize with value
    }
    Unq(const Unq &ptr) = delete;
    Unq &operator=(const Unq &ptr) = delete;

    Unq(Unq &&obj)
    {
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }
    Unq &operator=(Unq &&obj)
    {
        if (this != &obj)
        {
            delete ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }
    ~Unq()
    {
        delete ptr;
    }
    T *getPtr()
    {
        return ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }

private:
    T *ptr = nullptr;
};

int main()
{
    Unq<int> Obj;
    Unq<int> obj2 = std::move(Obj);
    Unq<int> obj3;
    obj3 = std::move(obj2);

    Unq<int> obj4(424); // Parameterized constructor call
    cout << "Value in obj4: " << *obj4.getPtr() << endl;
   // (*obj);
  //  obj->function();
  //  obj.reset();

    return 0;
}