#include <iostream>
using namespace std;

int main()
{
    float *fl; int *in; char *ch;

    fl = new float;
    in = new int;
    ch = new char;

    *fl = 45.67; *in = 23; *ch = 'T';

    cout << *fl << "  " << *in << "  "<< *ch;

    delete fl;
    delete in;
    delete ch;

    return 0;
}
