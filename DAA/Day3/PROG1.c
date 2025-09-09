#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int merge_comparisons = 0;
int merge_exchanges = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[MAX_SIZE], R[MAX_SIZE];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        merge_comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            merge_exchanges++;
        } else {
            arr[k++] = R[j++];
            merge_exchanges++;
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
        merge_exchanges++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        merge_exchanges++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void){
   
    int n;
   int  arr[MAX_SIZE];
     FILE *file;
    printf("Enter 1 or any other number: ");
     
     scanf("%d",&n);
    switch (n) {
        case 1:
            file = fopen("ascending.txt", "r");
            if (file == NULL) {
                file = fopen("ascending.txt", "w");
                if (file == NULL) {
                    perror("Failed to create ascending.txt");
                    return 1;
                }
                fprintf(file, "5 3 8 1 9\n"); // Add sample data
                fclose(file);
                file = fopen("ascending.txt", "r");
            }
            break;

       case 2:
            file = fopen("descending.txt", "r");
            if (file == NULL) {
                file = fopen("descending.txt", "w");
                if (file == NULL) {
                    perror("Failed to create descending.txt");
                    return 1;
                }
                fprintf(file, "4 7 2 6 0\n"); // Add sample data
                fclose(file);
                file = fopen("descending.txt", "r");
            }
            break;
    default:
      printf("Exit program");
      exit(0);
      break;

    }
    // Read numbers from file into arr
    int count = 0;
    while (fscanf(file, "%d", &arr[count]) == 1 && count < MAX_SIZE) {
        count++;
    }
    fclose(file);

    printf("Original array: ");
    for (int i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");

    // Perform merge sort
    merge_comparisons = 0;
    merge_exchanges = 0;
    mergeSort(arr, 0, count - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("Comparisons: %d\n", merge_comparisons);
    printf("Exchanges: %d\n", merge_exchanges);
}