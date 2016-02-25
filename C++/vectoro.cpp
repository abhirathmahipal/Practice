#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector <int> sample;


	cout << "Vector Size " << sample.size() << endl;

	sample.push_back(3);
	sample.push_back(4);
	sample.push_back(5);

	cout << "Vector Size After Push " << sample.size() << endl;
	int n = sample.size();

	cout << sample[0] << " " << sample[1] << " " << sample[2] << endl;
	

	sample.pop_back();

	n = sample.size();

	for (int i = 0; i < n; i++)
		cout << sample[i] << " ";

	return 0;

}