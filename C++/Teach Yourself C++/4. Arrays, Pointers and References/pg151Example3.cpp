#include <iostream>
#include <cstdlib>
using namespace std;

class array{
    int size;
    char* p;
public:
    array(int num);
    ~array(){delete [] p;}
    char &put(int i);
    char get(int i);
};

array::array(int num)
{
    p = new char[num];
    size = num;
}

char& array::put(int i)
{
    if(i < 0 || i >= size) {
        cout << "Bounds Error !!";
        exit(9);
    }

    return p[i];
}

char array::get(int i)
{
    if(i < 0 || i >= size)
    {
        cout << "Bounds Error !!";
        exit(1);
    }
    return p[i];
}

int main()
{
    array a(10);
    a.put(3) = 'x';
    a.put(2) = 'y';

    cout << a.get(3) << a.get(2);
    cout << "\n";

    a.put(11) = '!';

    return 0;
}
