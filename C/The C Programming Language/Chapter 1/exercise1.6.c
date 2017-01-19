// A program to verify the expression if getchar() != EOF is 0 or 1
#include <stdio.h>

int main()
{
    int c;

    printf("%d", (getchar() != EOF));
    return 0;
}
