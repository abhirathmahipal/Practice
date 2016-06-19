#include <iostream>
using namespace std;

class myclass {
	int a,b;
public:
	myclass(int n, int m) {this -> a = n; this -> b = m;}
	int add() {return this -> a + this -> b;}
	void show();
};

void myclass::show()
{
	int t;
	t = this -> add();
	cout << t << endl;
}

int main()
{
	myclass object(10,40);
	object.show();

	return 0;
}