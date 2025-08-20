#include<iostream>
#include<memory>
using namespace std;

class WP
{
    public:
    WP()
    {
        cout<<"Ctor called "<<endl;
    }
    ~WP()
    {
      cout<<"Dtor called "<<endl;   
    }
    void f()
    {
        cout<<"Print function"<<endl;
    }
};

int main()
{
    shared_ptr<WP> wp1 = make_shared<WP>();
    {
    cout<<"Ref count wp1:  "<<wp1.use_count()<<endl;
    shared_ptr<WP>wp2 = wp1;
    weak_ptr<WP>wp3=wp1;
    cout<<"Ref count wp1 : "<<wp1.use_count()<<endl;
    cout<<"Ref count wp2 : "<<wp2.use_count()<<endl;
    wp2->f();
    wp1->f();
    if(auto sp = wp3.lock())  // weak ptr doesnot own object and not direct access
    {
        sp->f();
    }
    //delete wp2;  will do free here and later wp1 trying to access the memory is already deleted 
    }
    cout<<"Ref count wp1 : "<<wp1.use_count()<<endl;

    return 0;
}
