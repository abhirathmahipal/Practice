// cc -std=c99 -Wall parsing.c mpc.c -ledit -lm -o parsing
#include "mpc.h"

#ifdef _WIN32

static char buffer[2048];

// functions for windows
char* readline(char *prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

// fake function for windows
void add_history(char *unused) {}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char **argv) {

    /* create some parsers */
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lispy = mpc_new("lispy");

    // defining a language
    mpca_lang(MPCA_LANG_DEFAULT,
        "                                                         \
            number      : /-?[0-9]+/ ;                            \
            operator    : '+' | '-' | '*' | '/';                  \
            expr        : <number> | '(' <operator> <expr>+ ')' ; \
            lispy       : /^/ <operator> <expr>+ /$/;             \
        ",
        Number, Operator, Expr, Lispy);

        puts("Lispy Version 0.0.0.0.2");
        puts("Press Ctrl + C to exit\n");

        while (1) {

            char *input = readline("lispy> ");
            add_history(input);

            // Attempt to parse the user input
            mpc_result_t r;

            if (mpc_parse("<stdin>", input, Lispy, &r)) {
                // on success print and delete the AST
                mpc_ast_print(r.output);
                mpc_ast_delete(r.output);
            } else {
                // print and then delete the error
                mpc_err_print(r.error);
                mpc_err_delete(r.error);
            }

            free(input);
        }

        mpc_cleanup(4, Number, Operator, Expr, Lispy);

        return 0;
}