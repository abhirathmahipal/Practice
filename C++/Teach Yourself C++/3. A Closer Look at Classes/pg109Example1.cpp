#include <iostream>
using namespace std;

class truck; // forward declaration

class car {
	int passengers;
	int speed;
public:
	car(int p, int s) {passengers = p; speed = s;}
	friend int sp_greater(car c, truck t);
};

class truck {
	int weight; 
	int speed;
public:
	truck(int w, int s) {weight = w; speed = s;}
	friend int sp_greater(car c, truck t);
};

int sp_greater(car c, truck t)
{
	return c.speed - t.speed;
}

int main()
{
	int t;
	car c1(6, 55);
	truck t1(12000, 45);

	cout << "comparing c1 and t1" << endl;

	t = sp_greater(c1, t1);

	if(t > 0) cout << "The car is faster";
	else if (t == 0) cout << "both are equally fast";
	else cout << "The truck is faster";

	cout << "\n";

	return 0;

}