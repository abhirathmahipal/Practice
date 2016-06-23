#include <iostream>
#include <cstring>
using namespace std;

class contact {
    char name[15];
    long number;
public:
    contact(const char* id, long num);
    void display();

};

contact::contact(const char* id, long num)
{
    strcpy(name, id);
    number = num;
}

void contact::display()
{
    cout << name << "  " << number << endl;
}

int main()
{
    contact *pointer;

    pointer = new contact("Abhirath", 9999999999);
    pointer->display();

    delete pointer;

    return 0;
}
