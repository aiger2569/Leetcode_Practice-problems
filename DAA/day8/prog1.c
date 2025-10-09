#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to print the optimal parenthesization using the s table
void printOptimalParens(int s[20][20], int i, int j) {
    if (i == j)
        printf("A%d", i+1); // Print matrix name
    else {
        printf("(");
        // Recursively print left and right subchains
        printOptimalParens(s, i, s[i][j]-1);
        printf(" ");
        printOptimalParens(s, s[i][j], j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n); // Input number of matrices

    int p[21]; // Array to store matrix dimensions
    int rows[20], cols[20]; // Arrays to store row and column sizes

    // Input dimensions for each matrix
    for (int i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i+1);
        scanf("%d %d", &rows[i], &cols[i]);
        // Check for dimension compatibility
        if (i > 0 && rows[i] != cols[i-1]) {
            printf("Error: Incompatible dimensions for multiplication!\n");
            return 1;
        }
    }

    // Build p array for matrix chain dimensions
    p[0] = rows[0];
    for (int i = 0; i < n; i++) p[i+1] = cols[i];

    int m[20][20] = {0}; // Table to store minimum multiplications
    int s[20][20] = {0}; // Table to store split points

    // Dynamic programming to fill m and s tables
    for (int l = 2; l <= n; l++) { // l is chain length
        for (int i = 0; i <= n-l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Initialize to infinity
            for (int k = i; k < j; k++) {
                // Calculate cost of splitting at k
                int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (q < m[i][j]) {
                    m[i][j] = q; // Update minimum
                    s[i][j] = k+1; // Store split point
                }
            }
        }
    }

    // Print m table (minimum multiplications)
    printf("M Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) printf("0 ");
            else printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Print s table (split points)
    printf("S Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) printf("0 ");
            else printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    // Print optimal parenthesization
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 0, n-1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[0][n-1]);
    return 0;
}
