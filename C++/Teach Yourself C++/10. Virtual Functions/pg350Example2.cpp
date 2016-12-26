#include <iostream>
using namespace std;

class base {
public:
    int i;
    base(int x) { i = x; }
    virtual void func()
    {
        cout << "using base version of func(): ";
        cout << i << '\n';
    }
};

class derived1 : public base {
public:
    derived1(int x) : base(x) {}
    void func()
    {
        cout << "using derived1's version of func(): ";
        cout << i * i << '\n';
    }
};

class derived2 : public base {
public:
    derived2(int x) : base(x) {}
    // does not override the virtual function func
};

int main()
{
    base *p;
    base ob(10);
    derived1 dob1(10);
    derived2 dob2(10);

    p = &ob;
    p->func(); // uses base's function

    p = &dob1;
    p->func(); // uses derived1's function

    p = &dob2;
    p->func(); // uses base's function as dob2 doesn't override the function

    return 0;
}
