// cc -std=c99 -Wall evaluation.c mpc.c -ledit -lm -o evaluation
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

// see operation to perform

long eval_op(long x, char *op, long y) {
    if (strcmp(op, "+") == 0) { return x + y; }
    if (strcmp(op, "-") == 0) { return x - y; }
    if (strcmp(op, "*") == 0) { return x * y; }
    if (strcmp(op, "/") == 0) { return x / y; }

    return 0;
}

long eval(mpc_ast_t* t) {
    // if tagged as number return directly
    if (strstr(t-> tag, "number")) {
        return atoi(t->contents);
    }

    // Operator always the second child
    char *op = t-> children[1]->contents;

    // third child stored in x
    long x = eval(t -> children[2]);

    // Iterate the remaining children and combining
    int i = 3;
    while (strstr(t -> children[i] -> tag, "expr")) {
        x = eval_op(x, op, eval(t -> children[i]));
        i++;
    }

    return x;
}

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
                
                // Just to print info. This block isn't required
                /* Load AST from output */
                mpc_ast_t* a = r.output;
                printf("Tag: %s\n", a->tag);
                printf("Contents: %s\n", a->contents);
                printf("Number of children: %i\n", a->children_num);

                /* Get First Child */
                mpc_ast_t* c0 = a->children[0];
                printf("First Child Tag: %s\n", c0->tag);
                printf("First Child Contents: %s\n", c0->contents);
                printf("First Child Number of children: %i\n",
                c0->children_num);

                // Not required till here.


                // on success print and delete the AST
                long result = eval(r.output);
                printf("%li\n", result);
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