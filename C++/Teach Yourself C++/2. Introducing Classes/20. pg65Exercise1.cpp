#include <iostream>
using namespace std;

int main(void)
{
	class area_c1 {
	public:
		double height;
		double width;
	};

	class rectangle:area_c1 {

	public:	
		double area() {return height * width;};
		rectangle(double x, double y) {height = x; width = y;}
	};

	class isosceles:area_c1 {
	public:
		double area() {return (height * width * 0.5);};
		isosceles(double x, double y) {height = x; width = y;}

	};

	rectangle rect(10, 7);
	isosceles iso(5, 6);

	cout << "Area of the rectangle is " << rect.area() << endl;
	cout << "Area of the triangle is " << iso.area() << endl;

	return 0;
}