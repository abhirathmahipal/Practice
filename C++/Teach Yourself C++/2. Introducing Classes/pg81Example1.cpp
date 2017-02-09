#include <iostream>
using namespace std;

class samp {
    int i, j;
public:
    samp(int a, int b) { i = a; j = b; }
    int divisible() { return !(i%j); }
};
