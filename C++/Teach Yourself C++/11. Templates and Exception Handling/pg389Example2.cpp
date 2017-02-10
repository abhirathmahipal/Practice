#include <iostream>
using namespace std;

int main()
{
    cout << "Start\n";

    try {
        cout << "inside try block\n";
        throw 10;
        cout << "this will not execute";
    }
    catch (double i) {
        cout << "Caught. Number is ";
        cout << i << endl;
    }

    cout << "end";

    return 0;
}