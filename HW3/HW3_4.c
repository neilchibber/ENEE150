#include <stdio.h>

void printArray(int arr[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Print array after each iteration
        printf("After i=%d: ", i);
        printArray(arr, n);
    }
}

int main() {
    int a[] = {2, 5, -3, 0, 12, 7, 3, 5, -1, 8};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    printArray(a, n);

    insertionSort(a, n);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}