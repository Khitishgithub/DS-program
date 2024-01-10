#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = data;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }

    int data = queue[front];

    if (front == rear)
    {
        front = rear = -1; 
    }
    else
    {
        front++;
    }

    return data;
}

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return (rear == MAX_SIZE - 1);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;

    printf("\tQUEUE IMPLEMENTATION USING ARRAY\n");
   

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Queue is full. Cannot enqueue.\n");
            }
            else
            {
                printf("Enter a value to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
            }
            break;
        case 2:
            if (isEmpty())
            {
                printf("Queue is empty. Cannot dequeue.\n");
            }
            else
            {
                printf("Dequeued value: %d\n", dequeue());
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
