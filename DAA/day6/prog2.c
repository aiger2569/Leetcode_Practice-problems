#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int cmpEdge(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edges[i].src--;  // zero-based indexing
        edges[i].dest--;
    }

    qsort(edges, m, sizeof(struct Edge), cmpEdge);

    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));
    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int totalCost = 0;
    printf("Edge Cost\n");
    int e = 0, i = 0;
    while (e < n - 1 && i < m) {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            printf("%d--%d %d\n", next_edge.src + 1, next_edge.dest + 1, next_edge.weight);
            totalCost += next_edge.weight;
            Union(subsets, x, y);
            e++;
        }
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalCost);

    free(subsets);
    return 0;
}