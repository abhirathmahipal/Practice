#include <stdio.h>
#define TABSTOP 4

int get_line(char storage[], int limit);

int main(void)
{
    


    return 0;
}

int get_line(char line[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c == getchar()) != EOF && c != '\n'
        && c != '\0'; i++)
           line[i] = c;
    
    if (c  == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}
