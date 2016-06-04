#include <iostream>
#include <stdlib.h>
using namespace std;

void sleep(const char*);
void sleep(int);

int main()
{
	sleep(2);
	cout << "The computer executed 2 loops" << endl;
	sleep("1");
	cout << "The computer executed 1 loop" << endl;
	return 0;
}

void sleep(const char *input)
{
	int a = atoi(input);

	for(int i = 0; i < a; i++)
		for (int j = 0; j < 1000000000; j++){}

}

void sleep(int a)
{
	for(int i = 0; i < a; i++)
		for (int j = 0; j < 1000000000; j++){}

}