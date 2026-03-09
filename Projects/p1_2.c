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
void subtractMatrices(Matrix A, Matrix B, FILE *fp);
void multiplyMatrices(Matrix A, Matrix B, FILE *fp);

void transposeRecursive(Matrix A, Matrix *T, int i, int j);
void transposeMatrix(Matrix A, FILE *fp);

void reverseMatrix(Matrix A, FILE *fp);
void scalarMultiply(Matrix A, int scalar, FILE *fp);

int determinantRecursive(Matrix A, int n);
void determinantMatrix(Matrix A, FILE *fp);

int findMaxRecursive(Matrix A, int i, int j, int currentMax);
void findMaximum(Matrix A, FILE *fp);


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

            int idx1 = getMatrixIndex(k, "Select the first matrix: ");
            if (idx1 == -1) continue;

            int idx2 = getMatrixIndex(k, "Select the second matrix: ");
            if (idx2 == -1) continue;

            addMatrices(M[idx1], M[idx2], output);
        }

        else if (choice == 2) {

            int idx1 = getMatrixIndex(k, "Select the first matrix: ");
            if (idx1 == -1) continue;

            int idx2 = getMatrixIndex(k, "Select the second matrix: ");
            if (idx2 == -1) continue;

            subtractMatrices(M[idx1], M[idx2], output);
        }

        else if (choice == 3) {

            int idx1 = getMatrixIndex(k, "Select the first matrix: ");
            if (idx1 == -1) continue;

            int idx2 = getMatrixIndex(k, "Select the second matrix: ");
            if (idx2 == -1) continue;

            multiplyMatrices(M[idx1], M[idx2], output);
        }

        else if (choice == 4) {

            int idx = getMatrixIndex(k, "Select matrix: ");
            if (idx == -1) continue;

            transposeMatrix(M[idx], output);
        }

        else if (choice == 5) {

            int idx = getMatrixIndex(k, "Select matrix: ");
            if (idx == -1) continue;

            reverseMatrix(M[idx], output);
        }

        else if (choice == 6) {

            int idx = getMatrixIndex(k, "Select matrix: ");
            if (idx == -1) continue;

            int scalar;
            printf("Enter scalar: ");
            scanf("%d", &scalar);

            scalarMultiply(M[idx], scalar, output);
        }

        else if (choice == 7) {

            int idx = getMatrixIndex(k, "Select matrix: ");
            if (idx == -1) continue;

            determinantMatrix(M[idx], output);
        }

        else if (choice == 8) {

            int idx = getMatrixIndex(k, "Select matrix: ");
            if (idx == -1) continue;

            findMaximum(M[idx], output);
        }

        else if (choice == 9) {

            printf("Exit.\n");
            fprintf(output, "Exit.\n");
            break;
        }

        else {
            printf("Invalid option.\n");
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

    printf("Addition Result:\n");
    fprintf(fp, "Addition Result:\n");

    printMatrix(C, -1, fp);
}



void subtractMatrices(Matrix A, Matrix B, FILE *fp)
{
    if (A.rows != B.rows || A.cols != B.cols) {

        printf("Error: Matrices must have same size.\n");
        fprintf(fp, "Error: Matrices must have same size.\n");
        return;
    }

    Matrix C;
    C.rows = A.rows;
    C.cols = A.cols;

    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            C.data[i][j] = A.data[i][j] - B.data[i][j];

    printf("Subtraction Result:\n");
    fprintf(fp, "Subtraction Result:\n");

    printMatrix(C, -1, fp);
}



void multiplyMatrices(Matrix A, Matrix B, FILE *fp)
{
    if (A.cols != B.rows) {

        printf("Error: Invalid dimensions for multiplication.\n");
        fprintf(fp, "Error: Invalid dimensions for multiplication.\n");
        return;
    }

    Matrix C;
    C.rows = A.rows;
    C.cols = B.cols;

    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {

            C.data[i][j] = 0;

            for (int k = 0; k < A.cols; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    printf("Multiplication Result:\n");
    fprintf(fp, "Multiplication Result:\n");

    printMatrix(C, -1, fp);
}



void transposeRecursive(Matrix A, Matrix *T, int i, int j)
{
    if (i == A.rows) return;

    T->data[j][i] = A.data[i][j];

    if (j + 1 < A.cols)
        transposeRecursive(A, T, i, j + 1);
    else
        transposeRecursive(A, T, i + 1, 0);
}



void transposeMatrix(Matrix A, FILE *fp)
{
    Matrix T;
    T.rows = A.cols;
    T.cols = A.rows;

    transposeRecursive(A, &T, 0, 0);

    printf("Transpose:\n");
    fprintf(fp, "Transpose:\n");

    printMatrix(T, -1, fp);
}



void reverseMatrix(Matrix A, FILE *fp)
{
    int temp[MAX_SIZE * MAX_SIZE];
    int index = 0;

    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            temp[index++] = A.data[i][j];

    index--;

    Matrix R = A;

    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            R.data[i][j] = temp[index--];

    printf("Reverse:\n");
    fprintf(fp, "Reverse:\n");

    printMatrix(R, -1, fp);
}



void scalarMultiply(Matrix A, int scalar, FILE *fp)
{
    Matrix R = A;

    for (int i = 0; i < A.rows; i++)
        for (int j = 0; j < A.cols; j++)
            R.data[i][j] = scalar * A.data[i][j];

    printf("Scalar Multiplication Result:\n");
    fprintf(fp, "Scalar Multiplication Result:\n");

    printMatrix(R, -1, fp);
}



int determinantRecursive(Matrix A, int n)
{
    if (n == 1)
        return A.data[0][0];

    int det = 0;
    Matrix sub;

    for (int x = 0; x < n; x++) {

        int subi = 0;

        for (int i = 1; i < n; i++) {

            int subj = 0;

            for (int j = 0; j < n; j++) {

                if (j == x) continue;

                sub.data[subi][subj++] = A.data[i][j];
            }

            subi++;
        }

        int sign = (x % 2 == 0) ? 1 : -1;

        det += sign * A.data[0][x] * determinantRecursive(sub, n - 1);
    }

    return det;
}



void determinantMatrix(Matrix A, FILE *fp)
{
    if (A.rows != A.cols) {

        printf("Error: Determinant requires square matrix.\n");
        fprintf(fp, "Error: Determinant requires square matrix.\n");
        return;
    }

    int det = determinantRecursive(A, A.rows);

    printf("Determinant: %d\n", det);
    fprintf(fp, "Determinant: %d\n", det);
}



int findMaxRecursive(Matrix A, int i, int j, int currentMax)
{
    if (i == A.rows)
        return currentMax;

    if (A.data[i][j] > currentMax)
        currentMax = A.data[i][j];

    if (j + 1 < A.cols)
        return findMaxRecursive(A, i, j + 1, currentMax);
    else
        return findMaxRecursive(A, i + 1, 0, currentMax);
}



void findMaximum(Matrix A, FILE *fp)
{
    int max = findMaxRecursive(A, 0, 0, A.data[0][0]);

    printf("Maximum value: %d\n", max);
    fprintf(fp, "Maximum value: %d\n", max);
}