#include <stdio.h>

void printArray(int arr[], int start, int end) {
    printf("{ ");
    for (int i = start; i <= end; i++) {
        printf("%d", arr[i]);
        if (i < end) printf(", ");
    }
    printf(" }\n");
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    printf("Merge -> ");
    printArray(arr, left, right);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        printf("MergeSort ");
        printArray(arr, left, mid);
        mergeSort(arr, left, mid);

        printf("MergeSort ");
        printArray(arr, mid + 1, right);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int a[] = {2, 5, -3, 0, 12, 7, 3, 5, -1, 8};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    printArray(a, 0, n - 1);

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    printArray(a, 0, n - 1);

    return 0;
}