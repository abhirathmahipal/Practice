// A brilliant way to remove occurences of a character from a 
// string. Nice run time, no extra storage required. In all
// it's amazing.
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];

    s[j] = '\0';
}
