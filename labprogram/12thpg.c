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

int performOperation(int operand1, int operand2, char operator) {
    int result;
    switch (operator) {
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
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                printf("Error: Division by zero\n");
                exit(1);
            }
            break;
        case '^':
            result = 1;
            for (int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            break;
        default:
            result = 0;
    }
    return result;
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

int evaluatePostfix(char postfix[]) {
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isAlphanumeric(c)) {
            int operand = c - '0';
            stack[++top] = operand;
        } else if (isOperator(c)) {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result = performOperation(operand1, operand2, c);
            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("The postfix expression is %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("The result of the expression is %d\n", result);

    return 0;
}