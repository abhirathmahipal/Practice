#include <iostream>
using namespace std;

class samp {
	int i;
public:
	samp(int n){i = n;}
	int get_i() {return i;}
};

// Return square of o.i
int sqr_it(samp o)
{
	int x = o.get_i();
	return x * x;
}

int main()
{
	samp a(10), b(2);

	cout << sqr_it(a) << "\n";
	cout << sqr_it(b) << "\n";

	return 0;
}