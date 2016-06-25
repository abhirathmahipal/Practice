#include <iostream>
using namespace std;

int& f(); // This returns a reference
int* fpointer();
int x;

int main()
{
    f() = 100;

    cout << x << "\n";

    *(fpointer()) = 200;

    cout << x << endl;
    return 0;
}

int& f()
{
    return x;
}

int* fpointer()
{
    int *add = &x;
    return add;
}
