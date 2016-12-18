#include <iostream>
using namespace std;

class samp {
    int a;
protected: // private to samp
    int b;
public:
    int c;

    samp(int n, int m) { a = n; b = m;}
    int geta() {return a;}
    int getb() {return b;}
};

int main()
{
    samp ab(10, 20);
    //ab.b = 99; illegal as B is protected
    
    ab.c = 100; // allowed as it's public
    cout << ab.geta() << ' ';
    cout << ab.getb() << ' ' << ab.c << '\n';
    return 0;
}
