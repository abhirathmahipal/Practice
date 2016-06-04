#include <iostream>
#include <string.h>
using namespace std;

char* rev_string(char*);
char* rev_string(const char*, char*);

int main()
{
	char s1[80] = "Hello!", s2[80];
	cout << rev_string(s1) << endl;
	cout << rev_string(s1, s2) << endl;

	
	return 0;
}

char* rev_string(char *s)
{
	int len = strlen(s) - 1;
	int len2 = len/2;
	char temp;
	for (int i = 0; i < len2; i++, len--)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
	}
	return s;
}

char* rev_string(const char* s1, char* s2)
{
	int len = strlen(s1);
	int lencopy = len;

	for (int i = 0; i < lencopy; i++)
	{
		s2[i] = s1[--len];
	}


	return s2;
}