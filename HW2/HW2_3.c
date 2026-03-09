#include <stdio.h>

void merge(int A[], int nA, int B[], int nB, int merged[], int *total) {
    *total = nA + nB;
    for (int i = 0; i < nA; i++) merged[i] = A[i];
    for (int i = 0; i < nB; i++) merged[nA + i] = B[i];
}

void bubbleSortRecursive(int merged[], int total, int i, int j) {
    if (i >= total - 1) return;
    
    if (j >= total - i - 1) {
        bubbleSortRecursive(merged, total, i + 1, 0);
        return;
    }
    
    if (merged[j] > merged[j + 1]) {
        int temp = merged[j];
        merged[j] = merged[j + 1];
        merged[j + 1] = temp;
    }
    
    bubbleSortRecursive(merged, total, i, j + 1);
}

int main() {
    int A[10], B[10], merged[20];
    int nA = 0, nB = 0;

    printf("Enter array A (ascending, up to 10 integers, separated by space):\n");
    while (nA < 10 && scanf("%d", &A[nA]) == 1) nA++;

    getchar();

    printf("Enter array B (descending, up to 10 integers, separated by space):\n");
    while (nB < 10 && scanf("%d", &B[nB]) == 1) nB++;

    int total;
    merge(A, nA, B, nB, merged, &total);

    bubbleSortRecursive(merged, total, 0, 0);

    printf("Merged array in ascending order:\n");
    for (int i = 0; i < total; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
