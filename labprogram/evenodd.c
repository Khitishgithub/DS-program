#include<stdio.h>
int main(){
    int arr1[]={1,2,3,4,5,6,7,8,9,10};
    int arr2[5];
    int arr3[5];
    int j =0, k=0;
    for(int i=0;i<10;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<10;i++){
        if(arr1[i]%2==0){
            arr2[j]=arr1[i];
            j++;
        }
        else{
            arr3[k]=arr1[i];
            k++;       
     }}  
     for(int j=0;j<5;j++){
        printf(" %d ",arr2[j]);
     }
     for(int k=0;k<5;k++){
        printf(" %d ",arr3[k]);
     };
     return 0;
    }
