#include <iostream>
using namespace std;

#define SIZE 10

class stack {
	char stck[SIZE]; // holds it
	int tos; // top 

public:
	void init();
	void push(char ch);
	char pop(); // removes top
};

// Initialise the stack
void stack::init()
{
	tos = 0;
}

// Push a char
void stack::push(char ch)
{
	if (tos == SIZE) {
		cout << "Stack isn't empty" << "\n";
		return;
	}
	stck[tos] = ch;
	tos++;
}

char stack::pop()
{
	if (tos == 0) {
		cout << "Stack is empty" << "\n";
		return 'a';
	}
	tos--;
	return stck[tos];
}

int main()
{
	stack s1, s2;
	int i;
	s1.init();
	s2.init();

	s1.push('a');
	s2.push('b');
	s1.push('c');
	s1.push('d');
	s2.push('g');

	for (int i = 1; i < 4; i++)
		cout << "Element No " << i <<" " << s1.pop() << endl;

	for (int i = 1; i < 3; i++)
		cout << "Element No " << i << " " << s2.pop() << endl;

	return 0;

}