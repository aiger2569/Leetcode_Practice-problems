#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    int arr[MAX_SIZE];
    int count = 0;
    FILE *file;

    printf("Enter 1 or any other number: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            file = fopen("f1.txt", "r");
            if (file == NULL) {
                file = fopen("f1.txt", "w");
                if (file == NULL) {
                    perror("Failed to create f1.txt");
                    return 1;
                }
                fprintf(file, "5 3 8 1 9\n"); // Add sample data
                fclose(file);
                file = fopen("f1.txt", "r");
            }
            break;

        default:
            file = fopen("f2.txt", "r");
            if (file == NULL) {
                file = fopen("f2.txt", "w");
                if (file == NULL) {
                    perror("Failed to create f2.txt");
                    return 1;
                }
                fprintf(file, "4 7 2 6 0\n"); // Add sample data
                fclose(file);
                file = fopen("f2.txt", "r");
            }
            break;
    }

    // Read integers from file
    while (fscanf(file, "%d", &arr[count]) == 1 && count < MAX_SIZE) {
        count++;
    }
    fclose(file);

    // Sort the array
    qsort(arr, count, sizeof(int), compare);

    // Print sorted array
    printf("Sorted numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
