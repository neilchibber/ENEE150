#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
CODE ANALYSIS PRACTICE - Doubly Linked Lists
Based on finals announcement: "short code analysis problems"

These problems use confusing function names to test if you can understand
what the code is doing, not just memorize patterns!
==============================================================================
*/

// Doubly linked list structures
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
    NODE *tail;
} DLLIST;

/*
==============================================================================
PROBLEM 1: What does this function do?

Analyze this code and explain its purpose:
==============================================================================
*/

void foo(DLLIST *list) {
    NODE *current = list->head;
    int count = 0;
    
    while (current != NULL) {
        if (current->data % 2 == 0) {
            count++;
        }
        current = current->next;
    }
    
    printf("Result: %d\n", count);
}

/*
QUESTION 1A: What is the purpose of this function?
QUESTION 1B: Why check current->data % 2 == 0?
QUESTION 1C: What would be output for list [1,2,3,4,5]?
QUESTION 1D: How would you modify this to count odd numbers?
*/

/*
YOUR ANSWERS:
ANSWER 1A:
ANSWER 1B:
ANSWER 1C:
ANSWER 1D:
*/

/*
==============================================================================
PROBLEM 2: Find the bug in this function

This function has a critical bug. Find and explain it:
==============================================================================
*/

NODE* bar(DLLIST *list, int target) {
    NODE *current = list->head;
    
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    
    return current;
}

/*
QUESTION 2A: What is this function supposed to do?
QUESTION 2B: What's the bug when target is NOT in list?
QUESTION 2C: What happens when target is the LAST element?
QUESTION 2D: How would you fix this bug?
*/

/*
YOUR ANSWERS:
ANSWER 2A:
ANSWER 2B:
ANSWER 2C:
ANSWER 2D:
*/

/*
==============================================================================
PROBLEM 3: Analyze the complexity

Consider this function that removes duplicates:
==============================================================================
*/

void baz(DLLIST *list) {
    NODE *current = list->head;
    NODE *prev = NULL;
    
    while (current != NULL) {
        NODE *runner = current->next;
        
        while (runner != NULL) {
            if (runner->data == current->data) {
                if (prev != NULL) {
                    prev->next = current->next;
                } else {
                    list->head = current->next;
                }
                
                if (current->next != NULL) {
                    current->next->prev = prev;
                } else {
                    list->tail = prev;
                }
                
                NODE *temp = current;
                current = current->next;
                free(temp);
                break;
            }
            runner = runner->next;
        }
        
        if (current != NULL) {
            prev = current;
            current = current->next;
        }
    }
}

/*
QUESTION 3A: What is the time complexity of this function?
QUESTION 3B: Why are there two nested loops?
QUESTION 3C: What's the purpose of the 'prev' pointer tracking?
QUESTION 3D: How could you optimize this function?
*/

/*
YOUR ANSWERS:
ANSWER 3A:
ANSWER 3B:
ANSWER 3C:
ANSWER 3D:
*/

/*
==============================================================================
PROBLEM 4: Edge case analysis

Analyze this function for edge cases:
==============================================================================
*/

int qux(DLLIST *list, int position) {
    if (position < 0) return -1;
    if (list == NULL) return -1;
    
    NODE *current = list->head;
    int count = 0;
    
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    
    if (current == NULL) return -2;
    if (count != position) return -3;
    
    return current->data;
}

/*
QUESTION 4A: What does each return code mean?
QUESTION 4B: What happens if position is 0?
QUESTION 4C: What happens if position is larger than list length?
QUESTION 4D: Which edge case is NOT handled?
*/

/*
YOUR ANSWERS:
ANSWER 4A:
ANSWER 4B:
ANSWER 4C:
ANSWER 4D:
*/

/*
==============================================================================
PROBLEM 5: Memory leak analysis

Find the memory leaks in this code:
==============================================================================
*/

DLLIST* quux() {
    DLLIST *list = (DLLIST*)malloc(sizeof(DLLIST));
    list->head = NULL;
    list->tail = NULL;
    
    // Add some nodes
    for (int i = 0; i < 5; i++) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = i * 10;
        new_node->prev = NULL;
        new_node->next = NULL;
        
        if (list->head == NULL) {
            list->head = new_node;
        } else {
            NODE *current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    
    // Function ends here - no free!
    return list;
}

/*
QUESTION 5A: What memory is leaked?
QUESTION 5B: How many bytes are leaked per call?
QUESTION 5C: How would you fix the memory leak?
QUESTION 5D: What's the proper cleanup pattern?
*/

/*
YOUR ANSWERS:
ANSWER 5A:
ANSWER 5B:
ANSWER 5C:
ANSWER 5D:
*/

/*
==============================================================================
PROBLEM 6: Pointer manipulation analysis

Analyze this complex pointer operation:
==============================================================================
*/

void quuz(DLLIST *list) {
    NODE **array = (NODE**)malloc(10 * sizeof(NODE*));
    NODE *current = list->head;
    int i = 0;
    
    while (current != NULL && i < 10) {
        array[i++] = current;
        current = current->next;
    }
    
    // Reverse the first 5 nodes
    for (int j = 0; j < 5 && j < i/2; j++) {
        NODE *temp = array[j];
        array[j] = array[i-1-j];
        array[i-1-j] = temp;
    }
    
    printf("Reversed nodes: ");
    for (int k = 0; k < 5 && k < i; k++) {
        printf("%d ", array[k]->data);
    }
    printf("\n");
    
    free(array);
}

/*
QUESTION 6A: What does this function do overall?
QUESTION 6B: Why use NODE** (array of pointers)?
QUESTION 6C: What's the purpose of the reversal loop?
QUESTION 6D: What happens if list has fewer than 5 nodes?
*/

/*
YOUR ANSWERS:
ANSWER 6A:
ANSWER 6B:
ANSWER 6C:
ANSWER 6D:
*/

/*
==============================================================================
TEST FUNCTIONS
==============================================================================
*/

void create_test_list(DLLIST *list) {
    for (int i = 1; i <= 5; i++) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = i;
        new_node->prev = NULL;
        new_node->next = NULL;
        
        if (list->head == NULL) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            list->tail->next = new_node;
            new_node->prev = list->tail;
            list->tail = new_node;
        }
    }
}

void run_tests() {
    printf("=== CODE ANALYSIS PRACTICE TESTS ===\n\n");
    
    DLLIST *list = (DLLIST*)malloc(sizeof(DLLIST));
    list->head = NULL;
    list->tail = NULL;
    
    create_test_list(list);
    
    printf("Test list created: ");
    NODE *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
    
    printf("=== RUNNING ANALYSIS FUNCTIONS ===\n\n");
    
    printf("1. Testing foo():\n");
    foo(list);
    printf("\n");
    
    printf("2. Testing bar() with target 3:\n");
    NODE *result = bar(list, 3);
    if (result != NULL) {
        printf("Found node with data: %d\n", result->data);
    } else {
        printf("Target 3 not found\n");
    }
    printf("\n");
    
    printf("3. Testing baz() - removing duplicates:\n");
    baz(list);
    printf("List after removing duplicates: ");
    current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        NODE *temp = current;
        current = current->next;
        free(temp);  // Clean up for this test
    }
    printf("\n\n");
    
    printf("4. Testing qux() with position 2:\n");
    int data = qux(list, 2);
    printf("Data at position 2: %d\n", data);
    printf("\n");
    
    printf("5. Testing quux() - memory leak demo:\n");
    DLLIST *leaky_list = quux();
    printf("Created list with memory leak\n");
    // Note: Not freeing leaky_list to demonstrate the leak
    
    printf("6. Testing quuz() - pointer array reversal:\n");
    create_test_list(list);
    quuz(list);
    
    printf("\n=== ANALYSIS COMPLETE ===\n");
    printf("Check your answers against the expected results!\n");
}

int main() {
    run_tests();
    return 0;
}
