#include <iostream>
using namespace std;

class coord {
	int x, y;
public:
	coord(){x = 0; y = 0;}
	coord(int i, int j){x = i; y = j;}
	void get_xy(int &i, int &j){i = x; j = y;}
	friend coord operator++(coord &ob); // passed by reference
};
/*
 * this is for the perfix operator ++
 * however modern compilers identify it 
 * and it works fine even for post fix.
 * Better to specify the function for ++ postfix
 * separately so that it works with all compilers
 * Format for postfix ++
 * friend coord operator++(coord &ob, int notused);
 */

 coord operator++(coord &ob)
 {
 	ob.x++;
 	ob.y++;

 	return ob;
 }

int main()
{
	coord o1(10, 10);
	int x, y;

	++o1;
	o1.get_xy(x, y);

	cout << " (++o1) X:  " << x << ", Y : " << y << " \n";

	return 0;
}