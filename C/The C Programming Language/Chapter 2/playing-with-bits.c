#include <stdio.h>

int main()
{
    int n, m, o, p, q;

    n = 12286546;
    printf("n before bit operation %d\n", n);
    n = n & 0177;
    printf("n after bit operation %d\n", n);

    m = 0;
    printf("m before operation %d\n", m);
    m = m & ~m; 
    printf("m after operation %d\n", m);
    return 0;
}
