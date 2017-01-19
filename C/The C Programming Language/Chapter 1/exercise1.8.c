#include <stdio.h>

int main()
{
    int blanks, tabs, newlines, next_char;

    for (blanks = 0, tabs = 0, newlines = 0; (next_char = getchar()) != EOF;)
    {
        if (next_char == ' ')
            blanks++;
        else if (next_char == '\t')
            tabs++;
        else if (next_char == '\n')
            newlines++;
    }
    printf("\nBlanks:- %d\nTabs:- %d\nNewlines:- %d", blanks, tabs, newlines);
    return 0;
}
