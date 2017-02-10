#include <iostream>
using namespace std;

#define SIZE 10

// Creating a generic stack class
template <class StackType> class stack {
    StackType stck[SIZE];
    int tos; // top of stack
public:
    void init() { tos = 0; }
    void push(StackType ch);
    StackType pop();
};

template <class StackType>
void stack<StackType> :: push(StackType ob)
{
    if (tos == SIZE) {
        cout << "Stack is full" <<endl;
        return;
    }
    stck[tos++] = ob;
}

template <class StackType>
StackType stack<StackType> :: pop()
{
    if (tos == 0) {
        cout << "Stack is empty" << endl;
        return 0; // null or empty Stack
    }
    return stck[--tos];
}

int main()
{
    stack<char> s1, s2;
    int i;

    s1.init(); s2.init();

    s1.push('a'); s2.push('b'); s1.push('1'); s2.push('2');

    for (int i = 0; i < 2; i++) {
        cout << "Pop s1 " << s1.pop() << endl;
        cout << "Pop s2 " << s2.pop() << endl;
    }

    return 0;
}