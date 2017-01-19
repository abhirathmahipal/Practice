#include <stdio.h>

#define IN  0
#define OUT 0

int main()
{
    // Let's assume that the max length of a word is 20 characters
    int ch, wordlengths[21], state = OUT, wordlen = 0;

    for (int i = 1; i <= 21; i++)
        wordlengths[i] = 0;
    
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n' || ch == '\t' || ch == ' ')
            state = OUT;
        else
        {
            state = IN;
            while (state == IN && (ch = getchar()) != EOF)
            {
                wordlen++;
                if (ch == '\n' || ch == '\t' || ch == ' ') {
                    state = OUT;
                    break;
                }
            }
            
            wordlengths[wordlen]++;
            wordlen = 0;
        }
    }

    for (int i = 1; i <= 20; i++) {
        printf("%2d   ", i);
        for (int j = 1; j <= wordlengths[i]; j++)
            printf("|");

        printf("\n");
    }
    return 0;
}
