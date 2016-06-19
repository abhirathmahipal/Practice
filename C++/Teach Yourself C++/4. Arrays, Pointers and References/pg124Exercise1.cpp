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
	letters object_array[10] = {97, 'b', 99, 100, 101, 102, 103, 104, 105, 106};

	for (int i = 0; i < 10; i++)
		cout << object_array[i].get_ch();
	
	return 0;
}