#include <iostream>
using namespace std;

int main()
{

	int *p;
	p = new int;

	if(!p)
	{
		cout << "Error";
		return 1;
	}

	*p = 1000;

	cout << "Value of P is " << *p << "\n";
	return 0;
}