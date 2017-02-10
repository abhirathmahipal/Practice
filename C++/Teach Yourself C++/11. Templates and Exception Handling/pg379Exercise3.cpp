#include <iostream>
using namespace std;

template <class x> int find(x object, x *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] == object)
            return i;
    }

    return -1;
}

int main()
{
    float f_list[] = {5.0, 4.0, 4.1, 3.5};
    int i_list[] = {1, 2, 4, 5};
    char c_list[] = {'a', 'b', 'c', 'd', 'e'};

    cout << find((float)5.0, f_list, 4) << endl;
    cout << find(6, i_list, 4) << endl;
    cout << find('e', c_list, 5) << endl;

    return 0;
}