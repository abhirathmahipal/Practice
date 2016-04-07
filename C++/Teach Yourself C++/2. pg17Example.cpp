#include <iostream>
using namespace std;

int main(){

	int i;
	float f;
	char s[80];

	cout << "Enter an integer, float and string: ";
	cin >> i >> f >> s;

	cout << "You Entered ";
	cout << i << "  " << f << "  " << s << endl;

	cout << "Enter a string ";
	cin >> s;
	cout << s;
	return 0;
}