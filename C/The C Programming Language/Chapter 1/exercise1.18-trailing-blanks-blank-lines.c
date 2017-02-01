#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int limit);
void clean(char line[]);

int main()
{
    
    char line[MAXLINE];
    int len;
    while ((len = get_line(line, MAXLINE)) > 0) {
            // Removing trailing whitespaces
            clean(line);
            printf("%s", line);

    }

    return 0;
}

int get_line(char line[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

void clean(char line[])
{
    int last_desired_index = -1;
    
    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {

        if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
            last_desired_index = i; 
    }

    if (last_desired_index > 0)
        line[++last_desired_index] = '\n';

    line[++last_desired_index] = '\0';
}
