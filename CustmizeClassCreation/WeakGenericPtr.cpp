#include<iostream>
using namespace std;

// Forward declaration for SharedPtr
template<typename T> class SharedPtr;

template<typename T>
class WeakPtr {
public:
    WeakPtr() : ptr(nullptr), refCount(nullptr) {}
    WeakPtr(const SharedPtr<T>& shared) : ptr(shared.getPtr()), refCount(shared.getRefCountPtr()) {}

    bool expired() const { return !refCount || *refCount == 0; }
    T* lock() const { return expired() ? nullptr : ptr; }

private:
    T* ptr;
    int* refCount;
};

int main()
{
    // Example usage (requires SharedPtr implementation)
    // SharedPtr<int> sp(new int(42));
    // WeakPtr<int> wp(sp);
    // if (!wp.expired()) cout << *wp.lock() << endl;
    return 0;
}