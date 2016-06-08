#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define SIZE 255

class strtype
{
	char *p;
	int len;
public:
	strtype();
	~strtype();
	void set(const char *ptr);
	void show();
};

void strtype::set(const char *ptr)
{
	if(strlen(p) >= SIZE)
	{
		cout << "String too big" << endl;
		return;
	}
	strcpy(p, ptr);
	len = strlen(p);
}

void strtype::show()
{
	cout << p << "\t Length: " << len << endl;
}

strtype::strtype()
{
	p = (char *) malloc(SIZE);
	*p = '\0';
	len = 0;
}

strtype::~strtype()
{
	cout << "Freeing Memory" << endl;
	free(p);
}

int main()
{
	strtype s1, s2;
	s1.set("I live in Chennai?");
	s2.set("Where do you live?");

	s1.show();
	s2.show();

	return 0;
}