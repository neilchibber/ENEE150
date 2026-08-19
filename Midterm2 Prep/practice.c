#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Implement a function that takes a ROOT pointer as input and prints
out the largest value in the linked list.
*/

typedef struct node{
    int * data;
    struct node * next;
} NODE;

typedef struct{
    NODE * head;
} ROOT;

void any_function(ROOT *list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    NODE *curr = list->head;

    // 3. Traverse the list
    while (curr != NULL) {


        curr = curr->next;
    }
}
int main() {
    ROOT *my_list = (ROOT* )malloc(sizeof(ROOT));
    my_list->head = NULL;
}
