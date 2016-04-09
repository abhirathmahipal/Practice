#include <iostream>
#include <ctime>
using namespace std;

class stopwatch 
{
	clock_t start, stop, objstart, objend;

public:
	// Constructor
	stopwatch()
	{
		objstart = clock();
	}
	// Destructor
	~stopwatch()
	{
		objend = clock();
		cout << "Time between creation and destruction of stopwatch one " << endl;
		cout << (objend - objstart)/CLOCKS_PER_SEC << endl;
	}

	void begin()
	{
		start = clock();
	}

	void end()
	{
		stop = clock();
	}

	int show()
	{
		return (stop - start)/CLOCKS_PER_SEC;
	}

};

int main()
{
	stopwatch one;

	// Timing the first time
	one.begin();
	// Time Delay
	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < 10000; j++){}

	one.end();
	cout << "Time Taken: " << one.show() << endl;

	// Timing the second time
	one.begin();
	// Time Delay
	for (int i = 0; i < 100000; i++)
		for (int j = 0; j < 10000; j++){}
	one.end();
	cout << "Time Taken: " << one.show() << endl;

	// Timing the Third time
	one.begin();
	// Time Delay
	for (int i = 0; i < 100000; i++)
		for (int j = 0; j < 10000; j++){}
	one.end();
	cout << "Time Taken: " << one.show() << endl;

	return 0;
}