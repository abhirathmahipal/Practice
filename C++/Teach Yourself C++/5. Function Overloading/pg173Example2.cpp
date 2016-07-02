#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype {
    char *p;
public:
    strtype(char *s);
    strtype(const strtype &o); // copy constructor
    ~strtype(){delete [] p;}
    char* get() {return p;}
};

strtype::strtype(char *s)
{
	int l;
	l = strlen(s) + 1;

	p = new char [l];
	strcpy(p, s);

}

// copy constructor
strtype::strtype(const strtype &o)
{
	int l;
	l = strlen(o.p) + 1;

	p = new char [l];

	strcpy(p, o.p); // copy string to the new array
}

void show(strtype x)
{
	char *s;

	s = x.get();
	cout << s << '\n';
}

int main()
{
	char hello[] = "Hello"; // avoiding warning of constant to char* deprecation
	char there[] = "There";
	strtype a(hello), b(there);
	strtype c =  b;
	show(a);
	show(b);
	show(c);
	return 0;
}