#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main() {
    char prefix[MAX_SIZE];
    char postfix[MAX_SIZE];
    double result;

    // Teste 1
    strcpy(prefix, "* + 3 4 5");
    prefixToPostfix(prefix, postfix);
    printf("Teste 1 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 2
    strcpy(prefix, "+ * 7 2 + 4 * 7 2 4");
    prefixToPostfix(prefix, postfix);
    printf("Teste 2 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 3
    strcpy(prefix, "+ + 8 * 5 + 2 4 8");
    prefixToPostfix(prefix, postfix);
    printf("Teste 3 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 4
    strcpy(prefix, "* + 6 / 2 3 * 4 + 6 / 2 3 4");
    prefixToPostfix(prefix, postfix);
    printf("Teste 4 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 5
    strcpy(prefix, "+ + 9 * 5 + 2 8 * 4 9");
    prefixToPostfix(prefix, postfix);
    printf("Teste 5 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 6
    strcpy(prefix, "/ / log + 2 3 log 5 l");
    prefixToPostfix(prefix, postfix);
    printf("Teste 6 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 7
    strcpy(prefix, "+ ^ log 3 2 ^ + ^ 3 l 10 2");
    prefixToPostfix(prefix, postfix);
    printf("Teste 7 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 8
    strcpy(prefix, "* + 45 60 * cos + 45 60 30");
    prefixToPostfix(prefix, postfix);
    printf("Teste 8 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 9
    strcpy(prefix, "+ + 0.5 ^ 45 sin ^ 2 0.5 45");
    prefixToPostfix(prefix, postfix);
    printf("Teste 9 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    // Teste 10
    strcpy(prefix, "* + 3 4 * 5 tan * 3 4 5");
    prefixToPostfix(prefix, postfix);
    printf("Teste 10 (Posfixa): %s\n", postfix);
    result = evaluatePostfix(postfix);
    printf("Resultado: %lf\n", result);

    return 0;
}
