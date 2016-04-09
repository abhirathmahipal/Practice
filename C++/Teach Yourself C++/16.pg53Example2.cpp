#include <iostream>
using namespace std;
#define SIZE 10

class stack
{
	char stck[SIZE]; // holder
	int tos; // index
	char who; // name or identifier
public:
	stack(char c)
	{
		tos == 0;
		who = c;
		cout << "constructing stack " << who << endl;

	}
	void push(char c)
	{
		stck[tos++] = c;

	}
	char pop()
	{
		return stck[--tos];

	}
	bool isFull()
	{
		return (SIZE == tos ? true : false);
	}
};

int main()
{
	stack s1('A'), s2('B');
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s2.push('d');
	s2.push('f');
	s2.push('s');

	while(!s1.isFull())
		s1.push('1');

	for (int i = 0; i < 10; i++)
		cout << s1.pop() << "  ";

	cout << endl;

	// This will generate an error
	for (int i = 0; i < 5; i++)
		cout <<"Pop S2: " << s2.pop() << "\n";

	return 0;
}