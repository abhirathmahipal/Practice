#include <iostream>
using namespace std;

class box
{
	double volume;
public:
	box(double l, double b, double h)
	{
		volume = l * b * h;
	}
	double vol()
	{
		cout << "Volume of the box is " << volume << endl;
	}

};

int main()
{

	box one(15.9, 10.0, 10.0);
	one.vol();
	return 0;
}