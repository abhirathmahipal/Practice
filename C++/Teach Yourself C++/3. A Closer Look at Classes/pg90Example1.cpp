#include <iostream>
using namespace std;

class myClass
{
	int a, b;
public:
	void set(int i, int j) {a = i; b = j;};
	void show(){cout << a << "  " << b << "\n";}
};

class yourClass
{
	int a, b;
public:
	void set(int i, int j) {a = i; b = j;};
	void show(){cout << a << "  " << b << "\n";}
};

int main()
{
	yourClass o1;
	myClass o2;
	o1.set(4, 5);
	o2 = o1; 
	// This will give an error even though both are the same.
	// They appear as diff objects to the compiler
	o1.show();
	o2.show();


	return 0;
}