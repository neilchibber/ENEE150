#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int *data;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
} ROOT;

int insertKth(ROOT *root, int k, int x) {
    if (root == NULL) return -1;

    int length = 0;
    NODE *current = root->head;
    while (current != NULL) { length++; current = current->next; }

    if (k < 1 || k > length + 1) {
        fprintf(stderr, "Error: k=%d out of bounds (1 to %d).\n", k, length + 1);
        return -1;
    }

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) return -1;

    newNode->data = (int *)malloc(sizeof(int));
    if (!newNode->data) { free(newNode); return -1; }

    *(newNode->data) = x;
    newNode->next = NULL;

    if (k == 1) {
        newNode->next = root->head;
        root->head = newNode;
        return 0;
    }

    current = root->head;
    for (int i = 1; i < k - 1; i++) current = current->next;

    newNode->next = current->next;
    current->next = newNode;

    return 0;
}