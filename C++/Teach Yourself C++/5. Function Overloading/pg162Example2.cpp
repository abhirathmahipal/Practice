#include <iostream>
using namespace std;

class myclass {
    int x;
public:
    // overloaded to declare without initialisation
    myclass() {x = 0;}
    myclass(int n){x = n;}
    int getx(){return x;}

};

int main()
{
    myclass o1[5];

    myclass o2[5] = {1,2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        cout <<"  " << o1[i].getx();
    }

    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << "  " << o2[i].getx();
    return 0;
}
