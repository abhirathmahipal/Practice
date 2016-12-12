// Copying the solution from the book to refresh syntax and other nuances

#include <iostream>

using namespace std;

void recip(double &d);

int main()
{
    double x = 100.0;

    cout << "x is " << x << '\n';

    recip(x);

    cout << "Reciprocal is " << x << '\n';

    return 0;
}

void recip(double &d)
{
    d = 1/d;
}
