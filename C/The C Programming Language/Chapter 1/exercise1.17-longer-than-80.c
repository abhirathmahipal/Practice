#define MAXLEN 10000
#include <stdio.h>

int get_line(char line[], int max);
int main()
{
    char line[MAXLEN];
    int len;

    while ((len = get_line(line, MAXLEN)) > 0)
        if (len > 80)
            printf("%s", line);

    return 0;
}

int get_line(char line[], int max)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && i < max - 1 && c != '\n'; i++ )
        line[i] = c;

    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}
