#include <iostream>
using namespace std;

class pr2; // forward declaration

class pr1 {
	int printing;
public:
	pr1() {printing = 0;}
	void set_print(int status) {printing = status;}

	friend bool inuse(pr1 printer1, pr2 printer2);
};

class pr2 {
	int printing;

public:
	pr2() {printing = 0;}
	void set_print(int status) {printing = status;}

	friend bool inuse(pr1 printer1, pr2 printer2);
};

bool inuse(pr1 printer1, pr2 printer2)
{
	if (printer1.printing || printer2.printing) return true;
	else return false;
}

int main()
{
	pr1 p1;
	pr2 p2;

	if(!inuse(p1, p2)) cout << "printer is not in use \n";
	else cout << "Printer is in use \n";

	p1.set_print(4);
	
	if(!inuse(p1, p2)) cout << "printer is not in use \n";
	else cout << "Printer is in use \n";

	return 0;
}