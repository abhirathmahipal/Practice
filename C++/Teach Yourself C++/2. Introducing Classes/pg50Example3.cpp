#include <iostream>
#include <ctime>

using namespace std;

class timer {
	clock_t start;
public:
	timer();
	~timer();
};

timer::timer()
{
	start = clock();
}
timer::~timer()
{
	clock_t end;
	end = clock();
	cout << "Elapsed time:  " << (end - start)/CLOCKS_PER_SEC << endl;
}

int main()
{
	timer ob;
	char c;

	// Delay
	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < 1000000; j++){}

	cout << "Press any key followed by ENTER: \n";
	cin >> c;

	return 0;
}