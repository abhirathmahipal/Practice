#include <iostream>

using namespace std;
class a_type {
    double a, b;

public:
    a_type(double x, double y) {
        a = x;
        b = y;
    }
    void show() { cout << a << ' ' << b << "\n"; }
};


int main() {
    
    a_type array[2][5] = {
        a_type(1,1), a_type(1,2),
        a_type(1,1), a_type(1,2),    
        a_type(1,1), a_type(1,2),    
        a_type(1,1), a_type(1,2),    
        a_type(1,1), a_type(1,2)         
    };


    for(int i = 0; i < 2; i++)
        for (int j = 0; j < 5; j++)
            array[i][j].show();


    return 0;
}
