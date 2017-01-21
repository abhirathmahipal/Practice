#include <stdio.h>
#define MAXLEN 1000

// didn't get the various lengths to fit right in. So expect some
// random new lines while reversing strings.

int get_line(char line[], int max);
void print_reverse(char line[], int len);

int main()
{
    int len;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0)
        print_reverse(line, len);

    return 0;
}

int get_line(char line[], int max)
{
    int i, c;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i; 
}

void print_reverse(char line[], int len)
{
    for (int i = len - 1; i >= 0; i--)
        putchar(line[i]);
}
