#include <iostream>
using namespace std;

int main(){

	int a, b, c, d, min;
	cout << "Enter Two Numbers:  ";
	cin >> a >> b;

	min = a > b? b: a;

	for (d = 2; d < min; d++)
		if((a % d == 0) && (b % d == 0)) break;

	if (d == min)
	{
		cout << "No Common Denominators" << endl;
		return 0;
	}

	cout << "The lowest common Denominator is " << d << endl;
	return 0;
}