#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int *data;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
} ROOT;

void removeDuplicates(ROOT *root) {
    if (root == NULL || root->head == NULL) return;

    NODE *outer = root->head;
    while (outer != NULL) {
        NODE *current = outer;
        while (current->next != NULL) {
            if (*(current->next->data) == *(outer->data)) {
                NODE *temp = current->next;
                current->next = temp->next;
                free(temp->data);
                free(temp);
            } else {
                current = current->next;
            }
        }
        outer = outer->next;
    }
}