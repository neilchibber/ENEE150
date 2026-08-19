#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MAX_MATRICES 100

typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void printMatrix(Matrix m, int index, FILE *fp);
void printMenu();
int getMatrixIndex(int k, char *prompt);
void addMatrices(Matrix A, Matrix B, FILE *fp);

int main(int argc, char *argv[])
{

    int k = atoi(argv[1]);
    if (k <= 0) {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    FILE *input = fopen(argv[2], "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return 1;
    }

    Matrix M[MAX_MATRICES];

    for (int m = 0; m < k; m++) {
        fscanf(input, "%d %d", &M[m].rows, &M[m].cols);
        for (int i = 0; i < M[m].rows; i++) {
            for (int j = 0; j < M[m].cols; j++) {
                fscanf(input, "%d", &M[m].data[i][j]);
            }
        }
    }

    fclose(input);

    for (int i = 0; i < k; i++) {
        printMatrix(M[i], i, output);
    }

    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            int idx1 = getMatrixIndex(k, 
                "Select the first matrix: ");

            int idx2 = getMatrixIndex(k, 
                "Select the second matrix: ");

            addMatrices(M[idx1], M[idx2], output);
        }
        else if (choice == 9) {
            printf("Exit.\n");
            fprintf(output, "Exit.\n");
            break;
        }
        else {
            printf("Phase 1.\n");
        }
    }

    fclose(output);
    return 0;
}

void printMatrix(Matrix m, int index, FILE *fp)
{
    printf("M[%d]:\n", index);
    fprintf(fp, "M[%d]:\n", index);

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d", m.data[i][j]);
            fprintf(fp, "%d", m.data[i][j]);

            if (j < m.cols - 1) {
                printf(" ");
                fprintf(fp, " ");
            }
        }
        printf("\n");
        fprintf(fp, "\n");
    }
}

void printMenu()
{
    printf("\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose\n");
    printf("5. Reverse\n");
    printf("6. Scalar Multiplication\n");
    printf("7. Find Determinant\n");
    printf("8. Find Maximum\n");
    printf("9. Exit\n");
    printf("\n");
}

/* Get valid matrix index (3 attempts rule) */
int getMatrixIndex(int k, char *prompt)
{
    int index;
    int attempts = 0;

    while (attempts < 3) {
        printf("%s", prompt);
        scanf("%d", &index);

        if (index >= 0 && index < k) {
            return index;
        }

        attempts++;
        printf("Invalid index. Try again.\n");
    }

    printf("Too many invalid attempts. Returning to menu.\n");
    return -1;
}

/* Matrix addition */
void addMatrices(Matrix A, Matrix B, FILE *fp)
{
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Error: Matrices must have same size for addition.\n");
        fprintf(fp, "Error: Matrices must have same size for addition.\n");
        return;
    }

    Matrix C;
    C.rows = A.rows;
    C.cols = A.cols;

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }

    printf("Result of Addition:\n");
    fprintf(fp, "Addition Result:\n");

    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%d", C.data[i][j]);
            fprintf(fp, "%d", C.data[i][j]);

            if (j < C.cols - 1) {
                printf(" ");
                fprintf(fp, " ");
            }
        }
        printf("\n");
        fprintf(fp, "\n");
    }
}