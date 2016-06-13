#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class samp
{
	char s[20];
public:
	void show() {cout << s << "\n";}
	void set(char *str) {strcpy(s, str);}
};

samp input ()
{
	char s[20];
	samp str;

	cout << "Enter a string: ";
	scanf("%[^\n]s", s);

	str.set(s);

	return str;
}

int main()
{
	samp object;

	object = input();
	object.show();

	return 0;
}