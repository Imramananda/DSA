#include <iostream>
#include <memory>
using namespace std;

class B; // Forward declaration

class A {
public:
    shared_ptr<B> ptrB;
    A() { cout << "A ctor\n"; }
    ~A() { cout << "A dtor\n"; }
};

class B {
public:
    shared_ptr<A> ptrA;
    B() { cout << "B ctor\n"; }
    ~B() { cout << "B dtor\n"; }
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->ptrB = b;
    b->ptrA = a;

    // Both destructors will NOT be called due to cyclic reference
    return 0;
}