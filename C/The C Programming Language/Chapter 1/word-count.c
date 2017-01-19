#include <stdio.h>

#define IN   1  /* inside a word */
#define OUT  0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        // notice how the logic is separated even though 
        // state could have been made out along with \n itself
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d", nl, nw, nc);
}
