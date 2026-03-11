#include <stdio.h>

#define N 10

void printArray(int a[], int n, int i, int j) {
    printf("After i=%d, j=%d: { ", i, j);
    for (int k = 0; k < n; k++) {
        printf("%d", a[k]);
        if (k < n - 1) printf(", ");
    }
    printf(" }\n");
}

int main() {
    int a[N] = {2, 5, -3, 0, 12, 7, 3, 5, -1, 8};

    printf("Original array:    { ");
    for (int k = 0; k < N; k++) {
        printf("%d", a[k]);
        if (k < N - 1) printf(", ");
    }
    printf(" }\n\n");


    int snap[4][2] = {{0,1}, {0,5}, {2,5}, {3,7}};
    int snapIdx = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

            for (int s = 0; s < 4; s++) {
                if (snap[s][0] == i && snap[s][1] == j) {
                    printArray(a, N, i, j);
                }
            }
        }
    }

    printf("\nFinal sorted array: { ");
    for (int k = 0; k < N; k++) {
        printf("%d", a[k]);
        if (k < N - 1) printf(", ");
    }
    printf(" }\n");

    return 0;
}