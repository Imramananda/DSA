#include <iostream>
using namespace std;

template <class T>
class UniquePtr {
public:
    // Default constructor
    UniquePtr() : ptr(nullptr) {
        cout << "Default Ctor" << endl;
    }
    
    // Constructor with value
    explicit UniquePtr(T* p) : ptr(p) {
        cout << "Ctor with pointer" << endl;
    }
    
    // Delete copy constructor and assignment
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    
    // Move constructor
    UniquePtr(UniquePtr&& obj) noexcept {
        cout << "Move copy ctor" << endl;
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }
    
    // Move assignment
    UniquePtr& operator=(UniquePtr&& obj) noexcept {
        cout << "Move assignment" << endl;
        if (this != &obj) {
            delete ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }
    
    // Destructor
    ~UniquePtr() {
        cout << "Dtor" << endl;
        delete ptr;
    }
    
    // Operator overloads for pointer-like behavior
    T& operator*() const {
        return *ptr;
    }
    
    T* operator->() const {
        return ptr;
    }
    
    // Get the raw pointer
    T* get() const {
        return ptr;
    }
    
    // Release ownership
    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }
    
    // Reset with new pointer
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    
    // Check if pointer is valid
    explicit operator bool() const {
        return ptr != nullptr;
    }

private:
    T* ptr;
};

int main() {
    cout << "Main" << endl;
    
    // Create a unique pointer with new int
    UniquePtr<int> obj1(new int(42));
    cout << "Value in obj1: " << *obj1 << endl;
    
    // Move obj1 to obj2
    UniquePtr<int> obj2 = std::move(obj1);
    cout << "Value in obj2: " << *obj2 << endl;
    
    // Create another unique pointer
    UniquePtr<int> obj3(new int(100));
    
    // Move assignment
    obj2 = std::move(obj3);
    cout << "New value in obj2: " << *obj2 << endl;
    
    return 0;
}