#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct strtype {
    strtype(char *ptr);
    ~strtype();
    void show();
private:
    char *p;
    int len;
};

strtype::strtype(char *ptr)
{
    len = strlen(ptr);
    p = (char *) malloc(len + 1);

    if(!p) {
        cout << "Allocation Error\n";
        exit(1);
    }

    strcpy(p, ptr);
}

strtype::~strtype()
{
    cout << "Freeing p \n";
    free(p);
}

void strtype::show()
{
    cout << p << " - length: " << len;
    cout << "\n";
}

int main()
{
    strtype s1("This is a test."), s2 ("I wish C++ were simpler");
    s1.show();
    s2.show();

    return 0;
}
