#include <iostream>
using namespace std;

class base {
	int a;
public:
	void load_a(int n) {a = n;}
	int get_a() {return a;}
};

class derived : public base {
	int b;
public:
	//int aa; (just for trying out stuff)
	void load_b(int n) {b = n;}
	int get_b() {return b;}
};

int main()
{
	derived a, b;

	a.load_a(1); a.load_b(2);
	a.aa = 5;

	b = a;

	cout<< a.get_a() << "  " << a.get_b() << endl;
	cout<< b.get_a() << "  " << b.get_b() << endl;
	//cout << a.aa;

	return 0;
}