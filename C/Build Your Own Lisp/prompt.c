#include <stdio.h>
#include <stdlib.h>

/* To make readline and history compatible with windows */

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// Fake readline function
char* readline(char *prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

// Fake add_history function
void add_history(char *unused) {}

// code below works for Mac and Linux
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {

   

    // Version and exit information
    puts("Lispy Version 0.0.0.1");
    puts("Press Ctrl + C to exit");

    while(1) {

     // output the param and read input as well
    char *input = readline("lispy> ");

    // add input to history
    add_history(input);

    printf("No you're a %s\n", input);

    free(input);

    }

    return 0;

}