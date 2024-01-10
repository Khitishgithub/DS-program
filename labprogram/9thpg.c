#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


int isAlphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}


int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isAlphanumeric(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; 
            }
        } else if (isOperator(c)) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}