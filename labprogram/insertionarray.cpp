#include<stdio.h>
int main(){
    int arr[100],i,position,c,n,value;
    printf("Enter the no of elements in an array:");

    scanf("%d",&n);
    printf("Enter elemrnts\n");
    for(c=0;c<n;c++)
    {
       scanf("%d",&arr[c]);
    }
    printf("Enter the position where the array element is inserted");
   scanf("%d",&position);
    printf("Enter the no which is to be inserted ");
    scanf("%d",&value) ;
    for (c = n-1 ;c>=position-1;c--){
        arr[c+1]= arr[c];
    }
    arr[position-1] = value ;
    printf("The resultant array is \n");
    for(c=0;c<=n;c++){
        printf(" %d ",arr[c]);
    }
    return 0;


    }

