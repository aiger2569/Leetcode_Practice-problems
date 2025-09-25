#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (j == -1) return;

    if (parent[j] == -1) {
        printf("%d", j + 1);
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

int main() {
   FILE *fp = fopen("inDiAdjMat1.dat", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    int n;
    if (fscanf(fp, "%d", &n) != 1 || n <= 0) {
        printf("Error: Invalid number of vertices\n");
        fclose(fp);
        return 1;
    }

    // Dynamically allocate adjacency matrix
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            int w;
            fscanf(fp, "%d", &w);
            if (w == 0 && i != j) {
                graph[i][j] = INT_MAX; // no edge
            } else {
                graph[i][j] = w; // weight or 0 for self-loop
            }
        }
    }
    fclose(fp);

    int src;
    printf("Enter the Source Vertex (1 to %d): ", n);
    scanf("%d", &src);
    if (src < 1 || src > n) {
        printf("Error: Invalid source vertex\n");
        return 1;
    }
    src--;

    int *dist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));
    int *parent = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break; // no more reachable nodes
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nSource Destination  Cost  Path\n");
    for (int i = 0; i < n; i++) {
        printf("%6d %11d ", src + 1, i + 1);
        if (dist[i] == INT_MAX) {
            printf(" INF  -");
        } else {
            printf("%4d  ", dist[i]);
            printPath(parent, i);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) free(graph[i]);
    free(graph);
    free(dist);
    free(visited);
    free(parent);

    return 0;
}
