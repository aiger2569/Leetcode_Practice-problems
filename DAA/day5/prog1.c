''' Aim of the program: Write a program to find the maximum profit nearest to but not  exceeding the given knapsack capacity using the Fractional Knapsack algorithm. 
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and  profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,  according to their profit /weight. 
Input: 
Enter the number of items: 3 
Enter the profit and weight of item no 1: 27 16 
Enter the profit and weight of item no 2: 14 12 
Enter the profit and weight of item no 3: 26 13 
Enter the capacity of knapsack:18
Output: 
Item No profit Weight Amount to be taken 
3 26.000000 13.000000 1.000000 
1 27.000000 16.000000 0.312500 
2 14.000000 12.000000 0.000000 
Maximum profit: 34.437500 
'''
#include <stdio.h>
#include<stdlib.h>
struct item{
    int item_id;
    float item_profiit;
    float item_weight;
    float profit_weight_ratio;

}
int main(void){
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    float profit=0;
    float  weight=0;
    struct item *arr=(struct item *)malloc(n*sizeof(struct item));
    //maximum knappsack capacity is =18;
    float capacity=18;
    //planning touuse heap sort ot sort the items in non increasing order according to their profit/weight ratio
    for(int i=0;i<n;i++){
        arr[i].item_id=i+1;
        printf("Enter the profit and weight of item no %d: ",i+1);
        scanf("%f%f",&arr[i].item_profiit,&arr[i].item_weight);
        arr[i].profit_weight_ratio=arr[i].item_profiit/arr[i].item_weight;
    }
    //caling the functions one by one

    knapsack(arr,n,capacity);
    return 0;
}
void swap(struct item *a,struct item *b){
    struct item temp=*a;
    *a=*b;
    *b=temp;
}
void maxHeapify_bottom_up(struct item *arr,int n,int idx){
    while(idx>0 && arr[(idx-1)/2].profit_weight_ratio<arr[idx].profit_weight_ratio){
        swap(&arr[(idx-1)/2],&arr[idx]);
        idx=(idx-1)/2;
    }
}
void heapSort(struct item *arr, int n){
    for(int i=1;i<n;i++){
        maxHeapify_bottom_up(arr, n, i);
    }
}
void knapsack(struct item *arr, int n, float capacity){
    heapSort(arr, n);
    float profit=0;
    float weight=0;
    for(int i=0;i<n;i++){
        if(weight+arr[i].item_weight<=capacity){
            weight+=arr[i].item_weight;
            profit+=arr[i].item_profiit;
        }
        else{
            float remaining=capacity-weight;
            profit+=arr[i].profit_weight_ratio*remaining;
            weight+=remaining;
            break;
        }
        printf("Item No profit Weight Amount to be taken\n");
        printf("%d %f %f %f\n", arr[i].item_id, arr[i].item_profiit, arr[i].item_weight, weight);
    }
    printf("Maximum profit: %f\n", profit);
}
    
    