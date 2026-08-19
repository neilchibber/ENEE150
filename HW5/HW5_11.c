#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int *data;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
} ROOT;

void oddEvenRearrange(ROOT *root) {
    if (root == NULL || root->head == NULL || root->head->next == NULL) return;

    NODE *oddHead = NULL, *oddTail = NULL;
    NODE *evenHead = NULL, *evenTail = NULL;

    NODE *current = root->head;
    int index = 1;

    while (current != NULL) {
        NODE *next = current->next;
        current->next = NULL;

        if (index % 2 == 1) {
            if (oddHead == NULL) { oddHead = oddTail = current; }
            else { oddTail->next = current; oddTail = current; }
        } else {
            if (evenHead == NULL) { evenHead = evenTail = current; }
            else { evenTail->next = current; evenTail = current; }
        }

        current = next;
        index++;
    }

    // Join odd list and even list
    if (oddHead == NULL) { root->head = evenHead; return; }
    oddTail->next = evenHead;
    root->head = oddHead;
}