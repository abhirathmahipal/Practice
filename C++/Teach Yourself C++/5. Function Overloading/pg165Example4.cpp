#include <iostream>
using namespace std;

class myclass {
    int x;
public:
    myclass() {/*do nothing*/} // no argument required
    myclass(int n) {x = n;}
    int getx() {return x;}
    int setx(int n) {x = n;}
};

int main()
{
    myclass *p;
    myclass ob(20); // single object initialisation

    p =  new myclass[10];
    // an array of objects, can't use initialisers here

    for (int i = 0; i < 10; i++)
    	p[i] = ob;

    for (int i = 0; i < 10; i++)
    {
    	cout << i+1 << ".  " << p[i].getx() << "  ";
    }
    return 0;
}
