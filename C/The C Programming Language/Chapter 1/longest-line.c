#include <stdio.h>
#define MAXLINE 1000 /* max line input size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; // current line length
    int max; // max length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;

    while((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0) //there was actual stuff in the line
        printf("%s", longest);
    
    printf("\nLength of the longest line is %d\n", max);
    return 0;
}

// get_line: reads a line into s, return length
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
