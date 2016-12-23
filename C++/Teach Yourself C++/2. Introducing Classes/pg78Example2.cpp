#include <iostream>
using namespace std;

inline int min(int a, int b)
{
    return a > b ? b : a;
}

inline long min(long a, long b)
{
    return a > b ? b : a;
}

inline double min(double a, double b)
{
    return a > b ? b : a;
}

int main()
{
    cout << min(-10, 10) << endl;
    cout << min(-10.01, 1000.2) << endl;
    cout << min(-10, 22) << endl;

    return 0;
}
