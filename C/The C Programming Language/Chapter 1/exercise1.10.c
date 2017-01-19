#include <stdio.h>

int main()
{
    int stream_char;

    // can also use switch cases or continue statements with individual
    // if statements instead of a ladder
    while ((stream_char = getchar()) != EOF)
    {
        if (stream_char == '\t')
            printf("\\t");
        else if (stream_char == '\n')
            printf("\\n");
        else
            putchar(stream_char);
    }

    return 0;
}
