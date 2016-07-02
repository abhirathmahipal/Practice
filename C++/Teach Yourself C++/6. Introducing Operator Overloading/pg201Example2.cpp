#include <iostream>
using namespace std;

class coord {
	int x, y;
public:
	coord() {x = 0; y = 0;}
	coord(int i, int j) {x = i; y = j;}
	void get_xy(int &i, int &j) { i = x; j = y;}
	coord operator +(coord ob2);
	coord operator -(coord ob2);
	void operator =(coord ob2); 
	// you can return the object as well (use *this pointer)
	// returning an object allows a series of assignments to be made.
	// o3 = o2 = o1 (you have to return an object in this case);
};

// overload + 

coord coord::operator+(coord ob2)
{
	coord temp;

	temp.x = x + ob2.x;
	temp.y = y + ob2.y;

	return temp;
}

// overload - 

coord coord::operator-(coord ob2)
{
	coord temp;

	temp.x = x - ob2.x;
	temp.y = y - ob2.y;

	return temp;
}

// overload = 
void coord::operator =(coord ob2)
{
	x = ob2.x;
	y = ob2.y;
}

int main()
{
	coord o1(10, 10), o2(5, 3), o3;
	int x, y;

	o3 = o1 + o2;
	o3.get_xy(x, y);
	cout << "o3: " << x << "  " << y << " \n";

	o3 = o1 - o2;
	o3.get_xy(x, y);

	cout << "o3: " << x << "  " << y << " \n";

	return 0;
}