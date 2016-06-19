#include <iostream>
using namespace std;

class samp {
	int i, j;
public:
	void set_ij(int a, int b) {i = a, j = b;}
	int get_product() {return i * j;}
};

int main()
{
	samp *p;

	p = new samp;

	if(!p)
	{
		cout << "Error";
		return 1;
	}

	p -> set_ij(4,5);

	cout << "The product is " << p -> get_product() << "\n";
	return 0;

}