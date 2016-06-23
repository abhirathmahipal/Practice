#include <iostream>
using namespace std;

void swapargs(int &x, int &y);

int main()
{
    int i, j;
    i = 10; j = 20;

    cout <<"i: " << i << ", ";
    cout <<"j: " << j << "\n";

    swapargs(i, j);

    cout << "After Swapping: ";
    cout << "i: " << i << ",  ";
    cout << "j: " << j << ",  ";

    return 0;
}

void swapargs(int &x, int &y)
{
    int t;

    t = x;
    x = y;
    y = t;
}
