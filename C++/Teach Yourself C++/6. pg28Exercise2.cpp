#include <iostream>
using namespace std;

class card {
	char title[80];
	char author[80];
	int count;
public:
	void store (const char[], const char*, int);
	int show();

};

void card::store(const char tentry[], const char* aentry, int n)
{
	for (int i = 0; tentry[i] != '\0'; i++)
		title[i] = tentry[i];

	for (int i = 0; aentry[i] != '\0'; i++)
		author[i] = aentry[i];

	count = n;
}

int card::show()
{
	cout << "The Name of the Book is " << endl;
	for (int i = 0; title[i] != '\0'; i++)
		cout << title[i];

	cout << "\nThe Available Qty is " << count;

	cout << "\nThe Author is " << endl;
	for (int i = 0; author[i] != '\0'; i++)
		cout << author[i];

	return 0;
}


int main(){

	card book1;
	book1.store("Harry Potter", "J.K. Rowling", 100);
	book1.show();

	return 0;
}