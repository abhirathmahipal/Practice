#include <iostream>
using namespace std;

int main()
{
	class area_cl 
	{
	public:
		double height;
		double width;
	};

	class cylinder : area_cl 
	{
	public:
		cylinder(double x, double y) {height = x; width = y;}
		double area(){return (2 * 3.14 * (width * width/4) + 3.14 * width * height);}
	};

	cylinder mycyl(7.0, 8.9);

	cout << mycyl.area() << endl;
	return 0;
}