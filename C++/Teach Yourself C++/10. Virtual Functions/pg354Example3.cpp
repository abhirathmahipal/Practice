#include <iostream>
#include <cstdlib>
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
        cout << i*i << '\n';
    }
};

class derived2 : public base {
public:
    derived2(int x) : base(x) {}
    void func()
    {
        cout << "using derived2's version of func(): ";
        cout << i+i << '\n';
    }
};

int main()
{
    base *p;
    derived1 dob1(10);
    derived2 dob2(10);
    
    for (int i = 0; i < 10; i++)
    {
        int j = rand();
        if (j % 2) p = &dob1; // if odd use dob1
        else p = &dob2;

        p->func();
    }
    
    return 0;

};
