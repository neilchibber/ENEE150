#include <stdio.h>
#include <stdlib.h>

int main() {
    int seed;
    printf("Enter the seed value:");
    scanf("%d", &seed);
    srand(seed);

    int row = rand() % 3 + 2;
    int col = rand() % 5 + 2;

    printf("         row = %d\n", row);
    printf("         col = %d\n", col);

    int **matrix = malloc(row * sizeof(int *));
    int *colCounts = malloc(row * sizeof(int));

    for (int i = 0; i < row; i++) {
        colCounts[i] = rand() % col + 1;
        printf("         The number of columns in row %d: %d\n", i + 1, colCounts[i]);

        matrix[i] = malloc(colCounts[i] * sizeof(int));
        for (int j = 0; j < colCounts[i]; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    for (int i = row - 1; i >= 0; i--) {
        for (int j = colCounts[i] - 1; j >= 0; j--) {
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(colCounts);

    return 0;
}