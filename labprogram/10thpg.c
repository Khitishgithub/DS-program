#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

void print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(int data)
{
    int position = 1;
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
}
int main()
{
    struct Node *head = NULL;
    int data1, n;
    printf("Enter the size of data :");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        printf("Enter dataa :");
        scanf("%d", &data1);
        insert(data1);
    }

    print();
    return 0;
}
