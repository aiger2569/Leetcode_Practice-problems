/*Aim of the program: Write a program to find out the Longest Common Subsequence of two
given strings. Calculate length of the LCS.
Input:
Enter the first string into an array: 10010101
Enter the second string into an array: 010110110
Output:
 LCS: 100110
 LCS Length: 6*/
 #include <stdio.h>

 int main(){
    //ok so here we will first enter the strings 
    printf("Enter the first string into an array: ");
    char str1[20], str2[20];
    scanf("%s", str1);
   printf("Enter the second string into an array: ");
    scanf("%s", str2);
    int n1=0,n2=0;
    //now we will calculate the length of both strings
    while(str1[n1]!='\0'){
        n1++;
    }
    while(str2[n2]!='\0'){
        n2++;
    }
    // now we will wil use a memoization approach to find the lcs
    int arr[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0){
                arr[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                if(arr[i-1][j]>arr[i][j-1]){
                    arr[i][j]=arr[i-1][j];
                }
                else{
                    arr[i][j]=arr[i][j-1];
                }
            }
        }
    }
    //now we will print the lcs length
    printf("LCS Length: %d\n",arr[n1][n2]);
    //and the lcs itself
    int index=arr[n1][n2];
    char lcs[index+1];
    lcs[index]='\0';
    int i=n1,j=n2;
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            lcs[index-1]=str1[i-1];
            i--;
            j--;
            index--;
        }
        else if(arr[i-1][j]>arr[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }   
    printf("LCS: %s\n", lcs);
    //now we end the program
    return 0;
 }

