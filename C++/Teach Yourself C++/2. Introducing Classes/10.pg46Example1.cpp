#include <iostream>
using namespace std;

#define SIZE 10

class stack
{
	char stck[SIZE];
	int top;

public:
	stack();
	void push(char);
	char pop();

};

stack::stack()
{
	cout << "constructing a stack" << endl;
	top = 0;
}

void stack::push(char ch)
{
	if(top == SIZE)
	{
		cout << "Stack is full" << endl;
		return;
	}
	stck[top++] = ch;
}

char stack::pop()
{
	if (top == 0)
	{
		cout << "Stack is empty" << endl;
		return 0;
	}

	return stck[--top];
}

int main()
{
	stack s1, s2;
	s1.push('a');
	s2.push('b');
	s1.push('c');
	s2.push('e');

	for (int i = 0; i < 2; i++)
	{
		cout << s1.pop() << endl;
		cout << s2.pop() << endl;
	}

	cout << s1.pop();

	return 0;
}