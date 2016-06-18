#include <iostream>
using namespace std;

class samp {
	int a, b;
public:
	samp(int n, int m){a = n; b = m;}
	int get_a(){return a;}
	int get_b(){return b;}
};

int main()
{
	samp ob[2][2] = {

			samp(1,2), samp(3,4),
			samp(5,6), samp(7,8),
	};

	for (int i = 0; i < 2; i++)
	{
		cout << ob[i][0].get_a() << " " << ob[i][0].get_b() << endl;
		cout << ob[i][1].get_a() << " " << ob[i][1].get_b() << endl;
	}

	return 0;

}