#include <stdio.h>
#include <stdlib.h> 

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; 

void push()
{
    int data;
    printf("Enter a value to be pushed: ");
    scanf("%d", &data);

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node)); 
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void display()
{
    struct Node *temp = head;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int pop()
{
    
    if (head == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    }
    
    int data = head->data;
    struct Node *temp = head;
    head = head->next;
    free(temp); 
    return data;
}
int main()
{
    int choice,n;
    printf("Enter the size of STACK [MAX=100]: ");
    scanf("%d", &n);

    printf("\n\tSTACK OPERATIONS USING LINKED LIST");
    printf("\n\t----------------------------------");
    printf("\n\t1. PUSH\n\t2. POP\n\t3. DISPLAY\n\t4. EXIT");

    do
    {
        printf("\nEnter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEXIT POINT\n");
            break;
        default:
            printf("\nPlease Enter a Valid Choice (1/2/3/4)\n");
        }
    } while (choice != 4);

    return 0;
}