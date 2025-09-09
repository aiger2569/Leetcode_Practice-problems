#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include <string.h>

struct person {
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

typedef struct {
    struct person *arr;
    int size;
    int capacity;
} heap;

heap* createHeap() {
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = 10;
    h->arr = (struct person *)malloc(h->capacity * sizeof(struct person));
    return h;
}
void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify_bottom_up(heap *h, int idx) {
    while (idx > 0 && h->arr[(idx-1)/2].age > h->arr[idx].age) {
        swap(&h->arr[(idx-1)/2], &h->arr[idx]);
        idx = (idx-1)/2;
    }
}

void minInsert(heap* h, struct person p) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->arr = (struct person *)realloc(h->arr, h->capacity * sizeof(struct person));
    }
    h->arr[h->size] = p;
    minHeapify_bottom_up(h, h->size);
    h->size++;
}

void maxHeapify_bottom_up(heap *h, int idx) {
    while (idx > 0 && h->arr[(idx-1)/2].weight < h->arr[idx].weight) {
        swap(&h->arr[(idx-1)/2], &h->arr[idx]);
        idx = (idx-1)/2;
    }
}

void maxInsert(heap* h, struct person p) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->arr = (struct person *)realloc(h->arr, h->capacity * sizeof(struct person));
    }
    h->arr[h->size] = p;
    maxHeapify_bottom_up(h, h->size);
    h->size++;
}
void printHeap(heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", h->arr[i].id, h->arr[i].name, h->arr[i].age, h->arr[i].height, h->arr[i].weight);
    }
}

void minHeap(FILE *fp) {
    heap *h = createHeap();
    struct person p;
    while (fscanf(fp, "%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight) == 5) {
        minInsert(h, p);
    }
    printf("Min heap (by age):\n");
    printHeap(h);
    free(h->arr);
    free(h);
}

void maxHeap(FILE *fp) {
    heap *h = createHeap();
    struct person p;
    while (fscanf(fp, "%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight) == 5) {
        maxInsert(h, p);
    }
    printf("Max heap (by weight):\n");
    printHeap(h);
    free(h->arr);
    free(h);
}


int main(void) {
    FILE *fp;
    int n;
    printf("1. Create a person\n");
    printf("2. Min heap all people based on age\n");
    printf("3. Maxheap all people based on weight\n");
    printf("4. Display the weight of the youngest person\n");
    printf("5. Insert new person in the min heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n) {
        case 1: {
            struct person p;
            printf("Enter id name age height weight: ");
            scanf("%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight);
            fp = fopen("person.txt", "a");
            if (!fp) { printf("Error opening file\n"); return 1; }
            fprintf(fp, "%d %s %d %d %d\n", p.id, p.name, p.age, p.height, p.weight);
            fclose(fp);
            printf("Person added.\n");
            break;
        }
        case 2:
            fp = fopen("person.txt", "r");
            if (!fp) { printf("Error opening file\n"); return 1; }
            minHeap(fp);
            fclose(fp);
            break;
        case 3:
            fp = fopen("person.txt", "r");
            if (!fp) { printf("Error opening file\n"); return 1; }
            maxHeap(fp);
            fclose(fp);
            break;
        case 4: {
            fp = fopen("person.txt", "r");
            if (!fp) { printf("Error opening file\n"); return 1; }
            struct person youngest;
            youngest.age = INT_MAX;
            struct person p;
            while (fscanf(fp, "%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight) == 5) {
                if (p.age < youngest.age) youngest = p;
            }
            fclose(fp);
            if (youngest.age != INT_MAX)
                printf("Weight of youngest person: %d\n", youngest.weight);
            else
                printf("No person found.\n");
            break;
        }
        case 5: {
            struct person p;
            printf("Enter id name age height weight: ");
            scanf("%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight);
            fp = fopen("person.txt", "a");
            if (!fp) { printf("Error opening file\n"); return 1; }
            fprintf(fp, "%d %s %d %d %d\n", p.id, p.name, p.age, p.height, p.weight);
            fclose(fp);
            printf("Person inserted in min heap.\n");
            break;
        }
        case 6: {
            fp = fopen("person.txt", "r");
            if (!fp) { printf("Error opening file\n"); return 1; }
            int max_age = -1, idx = -1, count = 0;
            struct person arr[100], p;
            while (fscanf(fp, "%d %s %d %d %d", &p.id, p.name, &p.age, &p.height, &p.weight) == 5) {
                arr[count] = p;
                if (p.age > max_age) { max_age = p.age; idx = count; }
                count++;
            }
            fclose(fp);
            if (idx == -1) { printf("No person found.\n"); break; }
            fp = fopen("person.txt", "w");
            for (int i = 0; i < count; i++) {
                if (i != idx)
                    fprintf(fp, "%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
            }
            fclose(fp);
            printf("Oldest person deleted.\n");
            break;
        }
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
    return 0;
}