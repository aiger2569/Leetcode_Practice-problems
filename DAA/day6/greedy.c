

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int V; // Number of vertices
int E; // Number of edges

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
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

void printKruskalMST(struct Edge result[], int mstE, int V) {
    int totalCost = 0;
    int mst[MAX][MAX] = {0};
    printf("Edge \tWeight\n");
    for (int i = 0; i < mstE; i++) {
        printf("%d - %d \t%d\n", result[i].src+1, result[i].dest+1, result[i].weight);
        mst[result[i].src][result[i].dest] = mst[result[i].dest][result[i].src] = result[i].weight;
        totalCost += result[i].weight;
    }
    printf("\nCost Adjacency Matrix of MST:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", mst[i][j]);
        printf("\n");
    }
    printf("\nTotal cost of Minimum Spanning Tree: %d\n", totalCost);
}

void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];
    int mstE = 0;
    qsort(edges, E, sizeof(struct Edge), cmpEdge);
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int i = 0;
    while (mstE < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[mstE++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printKruskalMST(result, mstE, V);
    free(subsets);
}

int main() {
    FILE *fp = fopen("UnAdjMat.dat", "r");
    if (fp == NULL) {
        printf("Error in opening the file\n");
        return -1;
    }

    int graph[MAX][MAX];
    V = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        int col = 0;
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            graph[V][col++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }
        V++;
    }
    fclose(fp);

    // Build edge list from adjacency matrix
    struct Edge edges[MAX*MAX];
    E = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) { // Only upper triangle for undirected
            if (graph[i][j] != 0) {
                edges[E].src = i;
                edges[E].dest = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    kruskalMST(edges, V, E);

    return 0;
}