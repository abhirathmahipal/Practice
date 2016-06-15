#include <iostream>
using namespace std;

class truck; // forward declaration

class car
{
	int passengers, speed;
public:
	car (int p , int s){passengers = p; speed = s;}
	int sp_greater(truck t);
};

class truck {
	int weight, speed;
public:
	truck (int a, int b){weight = a; speed = b;}

	friend int car::sp_greater(truck t);
};

int car::sp_greater(truck t)
{
	return speed - t.speed;
}

int main()
{
	int t;
	car c1(6, 55);
	truck t1(10000, 75);

	int difference = c1.sp_greater(t1);

	if (difference > 0) cout << "the car is faster \n";
	else if (difference == 0) cout << "both are equally fast \n";
	else cout << "the truck is faster \n";

	return 0;
}