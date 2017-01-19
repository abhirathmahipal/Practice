#include <stdio.h>
// Referred stackoverflow for this challenge
int main()
{
    int curr_char, letter_count[26], mode = 0;

    for (int i = 0; i < 26; i++)
        letter_count[i] = 0;

    // counting only letters
    while ((curr_char = getchar()) != EOF) {
        if (curr_char >= 'a' && curr_char <= 'z') {
            letter_count[curr_char - 'a']++;
        }
    }

    // finding the largest
    for (int i = 0; i < 26; i++)
        if (letter_count[i] > mode)
            mode = letter_count[i];
    printf("Frequency of the most occuring letter:- %d\n\n", mode);    
    // printing the vertical histogram
    for (int i = mode; i > 0; i--) {
        printf("%3d", i);

        for (int j = 0; j < 26; j++)
        {
            if (letter_count[j] >= i)
                printf(" *");
            else 
                printf("  ");
        }
        printf("\n");
    }
    printf("   ");
    for (int i = 'a'; i <= 'z'; i++)
        printf(" %c", i);

    printf("\n");
    return 0;
}
