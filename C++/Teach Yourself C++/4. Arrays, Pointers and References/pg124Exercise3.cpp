#include <iostream>
using namespace std;


class letters 
{
	char ch;
public:
	letters(char c) {ch = c;}
	char get_ch() {return ch;}
};
int main()
{
	letters object_array[10] = 
	{letters(97), letters(98), letters(99), 
	 letters(100), letters(101), letters(102), 
	 letters(103), letters(104), letters(105), letters(106)};

	for (int i = 0; i < 10; i++)
		cout << object_array[i].get_ch();
	
	return 0;
}