#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype {
	char *p;
	int len;
public:
	strtype(const char *s);
	~strtype() {
		cout << "Freeing  " << p << '\n';
		delete [] p;
	}

	char *get() {return p;}
	strtype& operator = (strtype &ob);
};

strtype::strtype(const char *s)
{
	int l;

	l = strlen(s) + 1;
	p = new char [l];

	if(!p)
	{
		cout << "Allocation Error \n";
		exit(1);
	}

	len = 1;
	strcpy(p, s);
}

strtype& strtype::operator=(strtype &ob)
{
	if (len < ob.len)
	{
		delete [] p;
		p = new char [ob.len];

		p = new char[ob.len];
		if (!p)
		{
			cout << "Allocation Error \n";
			exit(1);
		}

	}
	len = ob.len;
	strcpy(p, ob.p);
	return *this;




	return *this;
}

int main()
{
	strtype a("Hello"), b("There");

	cout << a.get() << '\n';
	cout << b.get() << '\n';

	a = b; // p is not overwritten

	cout << a.get() << '\n';
	cout << b.get() << '\n';

	return 0;
}