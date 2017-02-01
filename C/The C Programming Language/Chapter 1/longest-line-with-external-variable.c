#include <stdio.h>
#define MAXLINE 1000

int max;                     /* Max length seen so far */
char line[MAXLINE];          /* current line input */
char longest[MAXLINE];       /* Longest line saved so far */

int get_line(void);
void copy(void);

/* print longest input line; */
main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int get_line(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1
        && (c = getchar()) != EOF && c != '\n'; ++i)
            line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
