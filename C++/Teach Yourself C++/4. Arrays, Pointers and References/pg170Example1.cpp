#include <iostream>
#include <cstdlib>
using namespace std;

class array{
    int *p;
    int size;
public:
    array(int sz)
    {
        p = new int[sz];
        if(!p) exit(1);
        size = sz;
        cout << "Using normal constructor\n";
    }

    ~array() {delete [] p;}

    array(const array &a); // Declaring copy constructor

    void put(int i, int j)
    {
        if(i >= 0 && i < size)p[i] = j;
    }

    int get(int i)
    {
        return p[i];
    }
};

array::array(const array &a)
{
    size = a.size;

    p = new int[a.size];

    for (int i = 0; i < a.size; i++) p[i] = a.p[i]; // copying the contents

    cout <<"Constructing using copy constructors\n";

}

int main()
{
    array num(10);

    for (int i = 0; i < 10; i++) num.put(i, i);

    for (int i = 9; i > -1; i--) cout << num.get(i);
    cout <<"\n";

    array x = num;

    // display the new object created
    for (int i = 0; i < 10; i++) cout << x.get(i);

    return 0;

}
