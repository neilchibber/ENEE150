#include <stdio.h>

int main() {
    int A[10], B[10], merged[20];
    int nA = 0, nB = 0;

    printf("Enter array A (ascending, up to 10 integers, separated by space):\n");
    while (nA < 10 && scanf("%d", &A[nA]) == 1) nA++;

    getchar(); 

    printf("Enter array B (descending, up to 10 integers, separated by space):\n");
    while (nB < 10 && scanf("%d", &B[nB]) == 1) nB++;

    for (int i = 0; i < nA; i++) merged[i] = A[i];
    for (int i = 0; i < nB; i++) merged[nA + i] = B[i];

    int total = nA + nB;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    printf("Merged array in ascending order:\n");
    for (int i = 0; i < total; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
