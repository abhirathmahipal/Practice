#include <stdio.h>

#define LOWER  0
#define UPPER  300  // Upper limit of table
#define STEP   20   // Calculate in this interval


int main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
