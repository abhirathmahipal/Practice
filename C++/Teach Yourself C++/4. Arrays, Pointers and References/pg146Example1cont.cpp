#include <iostream>
using namespace std;

class myclass {
    int who;
public:
    myclass(int n) {who = n; cout << "constructing" << endl;}
    ~myclass() {cout << "Destructing" << endl;}
    int id() {return who;}
};

// Passing by reference
void f(myclass &o)
{
    cout << "Recieved " << o.id() << "\n";
}

void fpointer(myclass *o)
{
    cout << "Recieved " << o->id() << "\n";
}
int main()
{
    myclass x(1);
    f(x);
    fpointer(&x);
    return 0;
}
