#include <iostream>
using namespace std;

class myclass {
	int x;
public:
	myclass(int n = 0) {x = n;} // default arguments instead of overloading
	int getx() {return x;}
};

int main()
{
	myclass o1(10);
	myclass o2; // default argument comes into picture

	cout << "o1: " << o1.getx() << '\n';
	cout << "o2: " << o2.getx() << '\n';

	return 0;
}