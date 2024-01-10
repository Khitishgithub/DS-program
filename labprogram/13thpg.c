#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue()
{
    int data;
    printf("Enter a value to be enqueued: ");
    scanf("%d", &data);

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = front->data;
    struct Node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    free(temp);
    return data;
}

void display()
{
    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, n;
    printf("Enter the size of data : ");
    scanf("%d", &n);

    printf("\n\tqueue operatioon in linked list");
   
    printf("\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit");

    do
    {
        printf("\nEnter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
        {
            int dequeuedValue = dequeue();
            if (dequeuedValue != -1)
            {
                printf("Dequeued value: %d\n", dequeuedValue);
            }
            break;
        }
        case 3:
            display();
            break;
        case 4:
            printf("\nexit point\n");
            break;
        default:
            printf("\nPlease Enter a Valid Choice (1/2/3/4)\n");
        }
    } while (choice != 4);

    return 0;
}