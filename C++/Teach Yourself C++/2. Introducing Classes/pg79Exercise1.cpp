#include <iostream>
using namespace std;

inline int abs(int x)
{
	return (x > 0)? x : -x;
}

inline long abs(long x)
{
	return (x > 0)? x : -x;
}

inline double abs(double x)
{
	return (x > 0)? x:-x;
}

int main()
{
	cout << abs(-7) << endl;
	cout << abs(-78.87) << endl;
	cout << abs(38748937898908) << endl;

	return 0;
}