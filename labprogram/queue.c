#include<stdio.h>
#define SIZE 100
int arr[100];

int rear = -1;
int front = -1;
 int enqueue(int){
    int item;
    if(rear==SIZE-1)
    printf("Overflow condition\n");
    else{
        if(front=-1)
        front =0;
        scanf("%d",&item);
        rear = rear+1;
        arr[rear]=item;
    }

}

int dequeue(){
    int item;
    if(front ==-1|| front>rear)
    printf("Underflowcondition\n");

    else{
        printf("Element deleted %d",arr[item]);
        front = front + 1;

    }
}

int display(){
    int item;
    for(int i=front;i<=rear;i++)
    printf("%d",arr[item]);
}


int main(){
 enqueue(7);
 enqueue(8);
 enqueue(9);
 dequeue();
 display();
 
return 0;
}

