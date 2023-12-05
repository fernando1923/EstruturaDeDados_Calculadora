#include <stdiio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "struct.h"

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

char peek(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'l' || c == 's' || c == 'c' || c == 't');
}

int getPrecedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case 'l':
        case 's':
        case 'c':
        case 't':
            return 2;
        case '*':
        case '/':
            return 1;
        case '+':
        case '-':
            return 0;
        default:
            return -1; // Operador não reconhecido
    }
}

void prefixToPostfix(char *prefix, char *postfix) {
    Stack stack;
    initialize(&stack);

    int length = strlen(prefix);
    int postfixIndex = 0;

    for (int i = length - 1; i >= 0; i--) {
        char current = prefix[i];

        if (isdigit(current) || (current == '-' && isdigit(prefix[i - 1]))) {
            while (i >= 0 && (isdigit(prefix[i]) || prefix[i] == '.' || (prefix[i] == '-' && isdigit(prefix[i - 1])))) {
                postfix[postfixIndex++] = prefix[i--];
            }
            postfix[postfixIndex++] = ' ';
        } else if (isOperator(current)) {
            while (!isEmpty(&stack) && isOperator(peek(&stack)) && getPrecedence(peek(&stack)) > getPrecedence(current)) {
                postfix[postfixIndex++] = pop(&stack);
                postfix[postfixIndex++] = ' ';
            }
            push(&stack, current);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[postfixIndex++] = pop(&stack);
        postfix[postfixIndex++] = ' ';
    }

    postfix[postfixIndex] = '\0';
}

double evaluatePostfix(char *postfix) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i]) || (postfix[i] == '-' && isdigit(postfix[i + 1]))) {
            push(&stack, atof(&postfix[i]));
            while (isdigit(postfix[i]) || postfix[i] == '.') {
                i++;
            }
        } else if (postfix[i] == ' ') {
            i++;
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result = 0;

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                case 'l':
                    result = log10(operand2);
                    break;
                case 's':
                    result = sin(operand2);
                    break;
                case 'c':
                    result = cos(operand2);
                    break;
                case 't':
                    result = tan(operand2);
                    break;
                default:
                    printf("Operador não reconhecido: %c\n", postfix[i]);
                    exit(EXIT_FAILURE);
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}
