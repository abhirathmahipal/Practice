#include <iostream>
using namespace std;

int main()
{
    double *lets_play = new double(-123.0987);
    cout << *lets_play;
    delete lets_play;
}
