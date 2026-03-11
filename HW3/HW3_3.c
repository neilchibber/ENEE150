#include <stdio.h>

// Function to print the array with a star (*) on the recursive portion
void printArray(int arr[], int left, int right, int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (i >= left && i <= right) {
            printf("*%d*", arr[i]); // Star to mark the current recursive portion
        } else {
            printf("%d", arr[i]);
        }
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
}

// Partition function using last element as pivot
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[right]; arr[right] = temp;
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int left, int right, int n) {
    if (left < right) {
        printf("QuickSort ");
        printArray(arr, left, right, n);

        int pi = partition(arr, left, right);

        quickSort(arr, left, pi - 1, n);
        quickSort(arr, pi + 1, right, n);
    }
}

int main() {
    int a[] = {2, 5, -3, 0, 12, 7, 3, 5, -1, 8};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Note: *number* indicates the current recursive portion of array\n\n");

    printf("Original array: ");
    printArray(a, 0, n - 1, n);

    quickSort(a, 0, n - 1, n);

    printf("\nSorted array: ");
    printArray(a, 0, n - 1, n);

    return 0;
}