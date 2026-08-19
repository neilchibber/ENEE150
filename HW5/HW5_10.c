#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int *data;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
} ROOT;

void sortList(ROOT *root) {
    if (root == NULL || root->head == NULL || root->head->next == NULL) return;

    int swapped;
    do {
        swapped = 0;
        NODE *current = root->head;
        while (current->next != NULL) {
            if (*(current->data) > *(current->next->data)) {
                int temp = *(current->data);
                *(current->data) = *(current->next->data);
                *(current->next->data) = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}