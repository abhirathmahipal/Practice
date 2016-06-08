#include <iostream>
using namespace std;

class prompt
{
	int count;
public:
	prompt (const char *s) {cout << s; cin >> count;}
	~prompt();

};

prompt::~prompt()
{
	for(int i = 0; i < count; i++)
	{
		cout << '\a';
		for(int j = 0; j < 88000000; j++);
	}
}

int main()
{
	prompt myobject("My String ");

	return 0;
}