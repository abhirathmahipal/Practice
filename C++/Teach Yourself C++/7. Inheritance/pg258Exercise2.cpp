#include <iostream>
using namespace std;

class A {
    int i;
public:
    A(int a) { i = a; }
    int showa() {return i;}
};

class B {
    int j;
public:
    B(int a) { j = a; }
    int showb() {return j;}
};

class C : public A, public B {
    int k;
public:
    C(int a, int b, int c) : A(a), B(b) { k = c; }
    void show() {cout << showa() << showb() << k;}
};

int main()
{
    C ob(1,2,3);
    ob.show();
    return 0;
}
