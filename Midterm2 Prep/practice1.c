#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Implement a function that takes a ROOT pointer as input
and checks whether there is a pair of NODEs where the value of
one NODE is a multiple of the other. Return the “index” of the
NODE with the smaller value and 0 if no such pair. For example,
on 3->8->4->7->9->2, you can return either 3 (for 4) or 6 (for 2).
*/

typedef struct NODE {
    int * data;
    struct NODE* next;
}NODE;

typedef struct ROOT {
    NODE* head;
}ROOT;

int function(ROOT* x, int val) {
    if (x == NULL || x->head == NULL) {
        return 0;
    }

    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = (int*)malloc(sizeof(int));
    *(newnode->data) = val;
    newnode->next = x->head;
    x->head = newnode;

    NODE* newnode1 = (NODE* ) malloc(sizeof(NODE));
    newnode1->data = (int*)malloc(sizeof(int));
    *(newnode1->data) = val;
    current = x->head;
    next = current->next;

    while (next != NULL) {
        current = current->next;
    }
    current->next = newnode1;



}

int main() {
    ROOT* mylist = (ROOT*)malloc(sizeof(ROOT));
    mylist->head = NULL;
}



