#ifndef PIL_H
#define PIL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
char peek(Stack *stack);
int isOperator(char c);
int getPrecedence(char c);
void prefixToPostfix(char *prefix, char *postfix);
double evaluatePostfix(char *postfix);

#endif // PIL_H
