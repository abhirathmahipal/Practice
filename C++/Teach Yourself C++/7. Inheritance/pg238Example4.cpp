#include <iostream>
using namespace std;

class base {
    int x;
public:
    void setx(int n) { x = n;}
    void showx() {cout << x << '\n';}
};

class derived : private base {
    int y;
public:
    void setxy(int n, int m) {setx(n); y = m;}
    void showxy() {showx(); cout << y << '\n';}
};

int main() {
    derived ob;
    ob.setxy(1, 2);
    ob.showxy();
    return 0;
}
