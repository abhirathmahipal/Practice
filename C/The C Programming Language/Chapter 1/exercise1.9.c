#include <stdio.h>

int main()
{
    int stream_char, previous_char = '1'; // giving it some non blank value

    while ((stream_char = getchar()) != EOF)
    {
        if (stream_char == ' ')
        {
            if (previous_char == ' ')
                ;
            else
                putchar(stream_char);
        }
        else
        {
            putchar(stream_char);
        }

        previous_char = stream_char;
    }

    return 0;
}
