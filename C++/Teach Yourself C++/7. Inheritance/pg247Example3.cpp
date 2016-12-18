#include <iostream>
using namespace std;

class base {
    int i;
public:
    base(int n) {
        cout << "Constructing BASE Class" << endl;
        i = n;
    }

    ~base() {
        cout << "Destructing BASE Class" << endl;
    }

    void showi() {cout << i << endl;}
};

class derived : public base {
    int j;
public:
    derived(int n) : base(n) { // passing n to base class
        cout << "Constructing DERIVED Class" << endl;
        j = n;
    }

    ~derived() {cout << "Destructing DERIVED class" << endl;}
    void showj() { cout << j << endl;}
};

int main() {
    derived o(10);
    o.showi();
    o.showj();
    return 0;
}

