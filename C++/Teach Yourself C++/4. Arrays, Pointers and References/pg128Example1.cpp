#include <iostream>
#include <cstring>
using namespace std;

class inventory {
	char item[20];
	double cost;
	int in_hand;

public:
	inventory(const char* i, double c, int o)
	{
		strcpy(this -> item, i);
		this -> cost = c;
		this -> in_hand = o;
	}

	void show();
};

void inventory::show()
{
	cout << this -> item;
	cout << " $ " << this -> cost;
	cout << " In Hand: " << this -> in_hand << "\n";
}

int main()
{
	inventory object("Natural Gas", 45.67, 3);

	object.show();
	return 0;
}