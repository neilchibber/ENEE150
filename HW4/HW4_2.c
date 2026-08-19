#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int seed;
    printf("Enter the seed value:");
    scanf("%d", &seed);
    srand(seed);

    // Dynamic array to store last 5 digits of each random number
    int *nums = NULL;
    int count = 0;

    while (1) {
        int r = rand() % 100000; // last 5 digits

        // Check if this number already exists in our array
        int found = -1;
        for (int i = 0; i < count; i++) {
            if (nums[i] == r) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            // Print the duplicate and its two occurrences (1-indexed)
            printf("%05d repeats: %d %d\n", r, found + 1, count + 1);
            free(nums);
            return 0;
        }

        // Not found, add to dynamic array
        count++;
        nums = realloc(nums, count * sizeof(int));
        if (nums == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        nums[count - 1] = r;
    }

    return 0;
}