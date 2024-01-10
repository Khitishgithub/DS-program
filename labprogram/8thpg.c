
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
struct Stack
{
    char data;
    struct Stack *next;
};
void push(struct Stack **top, char c)
{
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}
char pop(struct Stack **top)
{
    if (*top == NULL)
    {
        return '\0';
    }
    char c = (*top)->data;
    struct Stack *temp = *top;
    *top = (*top)->next;
    return c;
}
bool isValidParentheses(char *str)
{
    struct Stack *stack = NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(&stack, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            char popped = pop(&stack);
            if ((str[i] == ')' && popped != '(') ||
                (str[i] == '}' && popped != '{') ||
                (str[i] == ']' && popped != '['))
            {
                return false;
            }
        }
    }
    return stack == NULL;
}
int main()
{
    char str[100];

    printf("Enter a string with parentheses: ");
    scanf("%s", str);

    if (isValidParentheses(str))
    {
        printf("The parenthesis are valid \n");
    }
    else
    {
        printf("The parenthesis are not valid\n");
    }
    return 0;
}