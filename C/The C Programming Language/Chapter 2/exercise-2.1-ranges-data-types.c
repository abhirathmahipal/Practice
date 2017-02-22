#include <limits.h>
#include <stdio.h>
#include <float.h>

int main(void)
{
    printf("Sizes of different data types\n");
    printf("chars - %ld byte\n", sizeof(char));
    printf("ints - %ld bytes\n", sizeof(int));
    printf("longs - %ld bytes\n", sizeof(long));
    printf("float - %ld bytes\n", sizeof(float));
    printf("double - %ld bytes\n", sizeof(double));

    // easy to compute them as well. 2 ^ n bytes - 1
    // If I recall correctly limits.h already has the required
    // value (min and max for every data type) stored in a variable.

    return 0;
}
