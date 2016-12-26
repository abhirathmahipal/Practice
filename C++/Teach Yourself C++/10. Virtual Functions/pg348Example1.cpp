#include <iostream>
using namespace std;

class base {
    int x;
public:
    void setx(int i) {x = i;}
    int getx() {return x;}
};

class derived : public base {
    int y;
public:
    void sety(int i) {y = i;}
    int gety() {return y;}
};

int main()
{
    base *p; // pointer to base type
    base bob; // object of type base
    derived dob; // object of the derived class

    p = &bob;
    p->setx(10); // base object function
    cout << "Base object x: " << p->getx() << '\n';

    // using base object pointer to access derived object
    p = &dob;
    p->setx(100); // derived object's setx function

    // can't access  members that aren't a part of the base
    // class in a derived object using the base class pointer
    dob.sety(99);
    cout << "Derived object x: " << p->getx() << '\n';
    cout << "Derived object y: " << dob.gety() << '\n';

    return 0;

}
