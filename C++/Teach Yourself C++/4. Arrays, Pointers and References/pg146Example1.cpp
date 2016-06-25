#include <iostream>
using namespace std;

class myclass {
    int who;
public:
    myclass(int n) {who = n; cout << "Constructing " << who << "\n";}
    ~myclass() {cout << "Destructing " << endl;}
    int id(){return who;}
};

void f(myclass o)
{
    cout << "Received " << o.id() << "\n";
}

int main()
{
    // Destructor is called twice
    myclass x(10);
    f(x);
    return 0;
}
