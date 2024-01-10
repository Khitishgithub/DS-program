#include<stdio.h>
int main(){
    int n;
    printf("Enter the length of a number :");
    scanf("%d",&n);
    int arr[n];
    int count =0;
    printf("Enter the number:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]==arr[n-1-i]){
            count++;
        }
        else{
            count=0;
        }
    }
    if(count==n){
        printf("Pallindrome\n");

    }
    else{
        printf("Not palllindrome\n");
    }
    return 0;

}
