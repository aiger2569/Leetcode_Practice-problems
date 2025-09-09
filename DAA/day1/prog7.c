#include<stdio.h>
int main(void){
    int arr[5]={1,2,3,4,5};
  int arr2[5];
       for (int i=0;i<5;i++){
       if(i==0){
        arr2[0]=arr[0];
             }
        else{
        arr2[i]=arr[i]+arr[i-1];
        }
        }    
    
       for (int i=0;i <5;i++){
        printf("%d",arr2[i]);}
    
}