#include<iostream>
using namespace std ;


void pallindrome(char arr[],char ch){
    for(int i=0;i<ch/2 && ch!=0; i++){
        if(arr[i]!= arr[ch-i-1]){
            cout<<"The array is not pallindrome"<<endl;
            return ;
        }
    
    else{
        cout<<"array is pallindrome"<<endl;
    }
    }
}
int main(){
    // int arr[] = {1 ,2 ,1};
    char arr[100];
    
   
     char ch = sizeof(arr)/sizeof(arr[0]);
     int c;
    cout<<"Enter the no of elements in an array";
    cin>>ch;
    cout<<"Enter elements \n"<<endl;
    for(c=0;c<ch;c++)
    {
        cin>>arr[c];
    }
    pallindrome(arr,ch);
    return 0;


   
    }