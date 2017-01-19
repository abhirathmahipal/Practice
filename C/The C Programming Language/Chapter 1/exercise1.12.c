#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
    int ch;
    // using the definition of word as mentioned in the example
    while((ch = getchar()) != EOF)
    {
       if (ch == '\n' || ch == '\t' || ch == ' ')
           putchar('\n');
       else
           putchar(ch);
    }

    return 0;
}
