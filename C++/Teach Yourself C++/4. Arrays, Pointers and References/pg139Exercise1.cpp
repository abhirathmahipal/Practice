#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char *p = new char[1000];
    strcpy(p, "this is a test");
    cout << p;

    delete [] p;
}
