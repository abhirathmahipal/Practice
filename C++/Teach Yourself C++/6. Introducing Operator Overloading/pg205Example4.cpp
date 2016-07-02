#include <iostream>
using namespace std;

class coord {
	
public:
	int x, y;
	coord() { x = 0; y = 0;}
	coord(int i, int j){x = i; y = j;}
	coord operator+(coord &ob2);
};

coord coord::operator+(coord &ob2)
{
	coord temp;

	temp.x = x + ob2.x;
	temp.y = y + ob2.y;

	return temp;
}

int main()
{
	coord o1(10, 10), o2(5, 3), o3;

	o3 = o2 + o1;
	cout << o3.x << "  " << o3.y << endl;
	o3.x = 5;
	cout << o3.x << '\n';
	return 0;
}