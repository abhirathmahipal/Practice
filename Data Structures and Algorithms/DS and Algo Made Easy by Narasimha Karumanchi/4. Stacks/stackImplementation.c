#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
    int top;
    int capacity;
    int *array;
} ArrayStack;

ArrayStack *createStack();
int isStackEmpty(ArrayStack *s);
int isFullStack(ArrayStack *s);
int insertIntoStack(ArrayStack *s, int data);
int peekTop(ArrayStack *s);
int pop(ArrayStack *s);
int printStack(ArrayStack *s);
int freeStack(ArrayStack *s);

int main() {
    
    printf("Creating stack\n");
    ArrayStack *s = createStack();

    printf("Is the stack empty? %d\n", isStackEmpty(s));

    printf("Inserting 1 into stack\n");
    insertIntoStack(s, 1);
    printf("Inserting 5 into stack\n");
    insertIntoStack(s, 5);

    printStack(s);
    printf("Is the stack full? %d\n", isFullStack(s));
    printf("Is the stack empty? %d\n", isStackEmpty(s));
   
    printf("Inserting 10 into stack\n");
    insertIntoStack(s, 10);
    printf("Inserting 3 into stack\n");
    insertIntoStack(s, 3);

    peekTop(s);
    printStack(s);

    return 0;
}

int isStackEmpty(ArrayStack *s) {
    return (s->top == -1);
}

int isFullStack(ArrayStack *s) {
    return (s->top == s->capacity - 1);
}

ArrayStack *createStack() {
    ArrayStack *s = (ArrayStack*)malloc(sizeof(ArrayStack));
    s->capacity = 15;
    s->top = -1;
    s->array = malloc(s->capacity * sizeof(int));
    return s;
}

int insertIntoStack(ArrayStack *s, int data) {

    if (!isFullStack(s)) {
       s->array[++s->top] = data;
       return 0;
    }
    else {
        printf("Stack is full.\n");
        return -1;
    }
}

int pop(ArrayStack *s) {
    if(!isStackEmpty(s)) {
        s->top--;
        return 0;
    }
    else {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
}

int peekTop(ArrayStack *s) {
    if(!isStackEmpty(s)) {
        printf("Element on top is: %d \n", s->array[s->top]);
        return 0;
    }
    else {
        printf("Stack is empty. Nothing on top.\n");
        return -1;
    }
}

int printStack(ArrayStack *s) {

    if(isStackEmpty(s)) {
        printf("Stack is empty. \n");
        return -1;
    }
    printf("\n\nCurrently in stack from top to bottom\n");
    for (int i = s->top; i > -1; i--) {
        printf("%d\n", s->array[i]);
    }
    printf("\n\n\n");

    return 0;
}

int freeStack(ArrayStack *s) {
    free(s->array);
    free(s);
    return 0;
}
