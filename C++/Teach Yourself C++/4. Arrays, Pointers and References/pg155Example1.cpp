#include <iostream>
using namespace std;

int main()
{
    // Example of an independent reference
    int x;
    int &ref = x;
    x = 100;

    cout << x << "  " << ref << "\n";
    return 0;
}
