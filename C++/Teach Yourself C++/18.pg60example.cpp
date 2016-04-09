#include <iostream>
using namespace std;

class b
{
	int i;
public:
	void set_i(int n)
	{
		i = n;
	}
	int get_i()
	{
		return i;
	}
};

class d : public b 
{
	int j;
public:
	void set_j(int n)
	{
		j = n;
	}
	int mul()
	{
		return j * get_i();
	}
};

int main()
{
	d obj;

	obj.set_i(10);
	obj.set_j(40);

	cout << obj.mul();

	return 0;
}