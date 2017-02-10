#include <iostream>
using namespace std;

template <class X> X mina(X a, X b)
{
    return ((a <= b) ? a : b);
}

int main()
{
    cout << mina(3, 4) << endl;
    cout << mina('c', 'a') << endl;

    return 0;
}