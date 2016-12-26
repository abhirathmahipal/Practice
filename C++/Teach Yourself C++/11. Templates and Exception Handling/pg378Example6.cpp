#include <iostream>
using namespace std;

template <class X> void swapargs(X &a, X &b)
{
    X temp;

    temp = a;
    a = b;
    b = temp;
}

// This function overrides the generic version of swapargs

void swapargs(int a, int b)
{
    cout << "this is inside swapargs(int, int)\n";
}

int main()
{
    int i = 10, j = 20;
    float x = 10, y = 23.3;

    cout << "Original i, j :" << i << ' ' << j << endl;
    cout << "Original x, y :" << x << ' ' << y << endl;

    swapargs(i, j); // calls overloaded swapargs() and doesn't actually swap
    swapargs(x, y); //swap floats

    cout << "overloaded template i, j: " << i << ' ' << j << endl;
    cout << "swapped x, y: " << x << ' ' << y << endl;

    return 0;
}
