#include <iostream>
using namespace std;

class num {
public:
    int val;
    num(int n) { val = n; }
    virtual void shownum() { cout << val; }
};

class outhex : public num {
public:
    outhex(int n) : num(n) {}
    void shownum() { cout << hex << val << '\n'; }
};

class outoct : public num {
public:
    outoct(int n) : num(n) {}
    void shownum() { cout << oct << val << '\n'; }
};

int main()
{
    outoct o(100);
    outhex h(200);

    o.shownum();
    h.shownum();

    return 0;
}
