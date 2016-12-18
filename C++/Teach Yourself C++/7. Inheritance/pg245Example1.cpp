#include <iostream>
using namespace std;

class base {
public:
    base() {cout << "Constructing Base Class \n";}
    ~base() {cout << "Destructing Base Class \n";}
};

class derived : public base {
public:
    derived() {cout << "Constructing Derived Class \n";}
    ~derived() {cout << "Destructing Derived Class \n";}
};

int main() {
    derived o;
    return 0;
}
