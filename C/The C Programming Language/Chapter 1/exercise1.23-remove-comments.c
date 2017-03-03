#include<stdio.h>

int main()
{
    int in_comment = 0;

    while(get_line(storage, 1000)) {
        int iter = 0;
        while (storage[iter] != '\0') {
            
            if (storage[iter] == '/' && storage[iter + 1] == '/') {
                break;
            }
            else if (iter >= 1000) {

            }
            else {

                putchar(storage[iter]);
            }

            iter++;
        }

    }

    return 0;
}

