#include <iostream>
using namespace std;

int absolute(int);
long absolute(long);
double absolute(double);

int main(){

	cout << "Absolute Value of - 10 " << absolute(-10) << endl;
	cout << "Absolute Value of 100000000000 " << absolute(100000000000) << endl;
	cout << "Abolute Value of -10.01 " << absolute(-10.01) << endl;

	return 0;
}

// Function definitions

int absolute(int n)
{
	cout << "Int Absolute is \n";
	return n < 0 ? -n : n;
}

long absolute(long n)
{
	cout << "Long Absolute is \n";
	return n < 0 ? -n : n;
}

double absolute(double n)
{
	cout << "Double Absolute is \n";
	return n < 0 ? -n : n;
}
