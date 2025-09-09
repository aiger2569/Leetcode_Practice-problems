#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];

    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    int a, b;
    int pairCount = 0;
    while (fscanf(in, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(out, "The GCD of %d and %d is %d\n", a, b, result);
        pairCount++;
    }

    fclose(in);
    fclose(out);

    if (pairCount < 10) {
        printf("Warning: Input file contains fewer than 20 numbers (10 pairs).\n");
    } else {
        printf("Successfully processed %d pairs. Output written to %s\n", pairCount, outputFile);
    }

    return 0;
}
