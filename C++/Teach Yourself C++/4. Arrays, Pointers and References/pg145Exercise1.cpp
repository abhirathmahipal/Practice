#include <iostream>
using namespace std;

void neg_pointers(int *n);
void neg_reference(int &n);

int main()
{

    int n, m;
    n = -35; m = 900;
    
    cout << n << " neg using pointers ";
    neg_pointers(&n);
    cout << n << endl;
    
    cout << m << " neg using references ";
    neg_reference(m);
    cout << m << endl;

    int x = 89;
    x = -x;
    cout << x;
    return 0;
}

void neg_pointers(int *n)
{
    *n *= -1;
}

void neg_reference(int &n)
{
    n *= -1;
}
