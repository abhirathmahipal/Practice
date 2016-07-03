#include <iostream>
using namespace std;

class coord {
	int x, y;
public:
	coord(){x = 0; y = 0;}
	coord(int i, int j){x = i; y = j;}
	void get_xy(int &i, int &j){i = x; j = y;}
	int operator ==(coord ob2);
	int operator &&(coord ob2);
};

// Overloading the == operator

int coord::operator ==(coord ob2)
{
	return x==ob2.x && y==ob2.y;
}

// overloading the && operator
int coord::operator &&(coord ob2)
{
	return (x && ob2.x) && (y && ob2.y);
}

int main()
{
	coord o1 (10,10), o2(5, 3), o3(10,10), o4(0,0);

	if(o1 == o2) cout << "o1 and o2 are the same \n";
	else cout << "o1 and o2 are different \n";

	if(o1 && o2) cout << "o1 && o2 is true \n";
	else cout << "o1 && o2 is false";

	if(o1 && o3) cout << "o1 and o2 are the same \n";
	else cout << "o1 and o3 are different\n";

	return 0;
}