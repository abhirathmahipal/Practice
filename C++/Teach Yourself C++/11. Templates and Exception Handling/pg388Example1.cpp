#include <iostream>
using namespace std;

int main()
{
    cout << "start\n";

    try {
        cout << "Inside try block\n";
        throw 10;
        cout << "this will not execute";
    }
    catch (int i) {
        cout << "Caught one! Number is : ";
        cout << i << "\n";
    }

    cout << "end";

    return 0;
}