#include <stdio.h>
#include <stdlib.h>


void convertToBinary(int n, FILE *out, int bits) {
    if (bits == 0) return;
    convertToBinary(n / 2, out, bits - 1);
    fprintf(out, "%d", n % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *inputFile = argv[2];
    char *outputFile = argv[3];
      
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

    int value;
    for (int i = 0; i < n; i++) {
        if (fscanf(in, "%d", &value) != 1) {
            printf("Not enough numbers in input file.\n");
            break;
        }

        fprintf(out, "The binary equivalent of %d is ", value);
        convertToBinary(value, out, 16);
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);

    // Display output file contents
    out = fopen(outputFile, "r");
    if (!out) {
        perror("Error reopening output file");
        return 1;
    }

    char ch;
    while ((ch = fgetc(out)) != EOF)
        putchar(ch);

    fclose(out);
    return 0;
}
