#include <iostream>
#include <cmath>
using namespace std;

void round(double &num, int removeAmbiguity);

int main()
{
    double i = 100.4;

    cout << i << " rounded is ";
    round(i, 1);
    cout << i << "\n";

    i = 10.9;
    cout << i << " rounded is";
    round(i, 1);
    cout << i << "\n";

    return 0;
}

void round(double &num, int removeAmbiguity)
{
    double frac;
    double val;

    frac = modf(num, &val);

    if (frac < 0.5) num = val;
    else num = val + 1.0;
}
