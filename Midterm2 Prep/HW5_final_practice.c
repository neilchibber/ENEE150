#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
HW5-BASED FINAL PRACTICE - Singly Linked Lists
Based on finals announcement: "questions will be similar to Homework 5"

This covers coding problems and code analysis using singly linked lists
==============================================================================
*/

// Singly linked list structures (from HW5)
typedef struct node {
    int *data;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
} ROOT;

/*
==============================================================================
PROBLEM 1: Code Analysis - Bubble Sort

Analyze this bubble sort implementation from HW5_10.c:

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

PART A: What is the time complexity of this bubble sort?
PART B: What happens if the list has duplicate values?
PART C: Is this sort stable or unstable? Explain why.
PART D: What's the purpose of the outer "do-while" loop?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
==============================================================================
PROBLEM 2: Code Analysis - List Rearrangement

Analyze this odd/even rearrangement from HW5_11.c:

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

PART A: What is the purpose of the index variable?
PART B: Why are there separate odd and even lists?
PART C: What happens to the original list structure?
PART D: What's the time complexity of this algorithm?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
==============================================================================
PROBLEM 3: Coding Challenge - Find Middle Node

Write a function to find the middle node of a singly linked list.
Return NULL if list is empty or has no middle.

Requirements:
- Use only one pass through the list
- Handle both even and odd length lists
- Return pointer to middle node
*/

NODE* find_middle(ROOT *root) {
    NODE* current = root->head;
    NODE* middle = root->head;
    if (root == NULL || root->head == NULL) {
        return NULL;
    }
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    if (count % 2 == 0) {
        count = count/2;
        for(int i = 0; i < count; i++) {
            middle = middle->next;
        }
    } else {
        // Odd length list
        return NULL;
    }
    // Hint: Use two-pointer technique (slow and fast)
    return middle;
}

PART A: What is the two-pointer technique?
PART B: How does this work for odd-length lists?
PART C: How does this work for even-length lists?
PART D: What's the advantage over first counting then traversing?
*/

/*
YOUR CODE:
*/

/*
==============================================================================
PROBLEM 4: Coding Challenge - Remove Duplicates

Write a function to remove duplicate values from a singly linked list.
Keep only the FIRST occurrence of each value.

Requirements:
- Return a new ROOT with duplicates removed
- Do not modify the original list
- Handle edge cases properly
*/

ROOT* remove_duplicates(ROOT *root) {
    // YOUR CODE HERE
    // Hint: Use hash set approach or nested loops
}

PART A: What's the time complexity of nested loops approach?
PART B: What's the time complexity of hash set approach?
PART C: Why can't we modify the list in place?
PART D: What happens if all values are the same?
*/

/*
YOUR CODE:
*/

/*
==============================================================================
PROBLEM 5: Code Analysis - Memory Management

Analyze this function for potential memory issues:

void create_and_leak() {
    ROOT *list = (ROOT*)malloc(sizeof(ROOT));
    list->head = NULL;
    
    for (int i = 0; i < 5; i++) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = (int*)malloc(sizeof(int));
        *(new_node->data) = i * 10;
        new_node->next = list->head;
        list->head = new_node;
    }
    
    // Function ends - no cleanup!
}

PART A: What memory is leaked in this function?
PART B: How many bytes are leaked total?
PART C: What's the proper cleanup sequence?
PART D: What's the difference between malloc and free?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
==============================================================================
PROBLEM 6: Coding Challenge - List Intersection

Write a function to find the intersection of two singly linked lists.
Return a new ROOT containing nodes that appear in BOTH lists.

Requirements:
- Nodes should appear in the order they first appear in list1
- Do not modify the original lists
- Handle empty lists properly
*/

ROOT* find_intersection(ROOT *list1, ROOT *list2) {
    // YOUR CODE HERE
    // Hint: Use hash set or nested loops
}

PART A: What does "intersection" mean in this context?
PART B: What's the time complexity of efficient solution?
PART C: How would you handle duplicate values within a single list?
PART D: What happens if one list is empty?
*/

/*
YOUR CODE:
*/

/*
==============================================================================
PROBLEM 7: Code Analysis - Edge Cases

Analyze this function for edge case handling:

NODE* get_nth(ROOT *root, int n) {
    if (root == NULL || root->head == NULL) return NULL;
    if (n < 0) return NULL;
    
    NODE *current = root->head;
    int count = 0;
    
    while (current != NULL) {
        if (count == n) return current;
        current = current->next;
        count++;
    }
    
    return NULL;  // Not found
}

PART A: What edge cases are handled by the first three conditions?
PART B: What happens if n is larger than list length?
PART C: Why is count initialized to 0?
PART D: What would happen if the while condition was "current != NULL && count < n"?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
==============================================================================
PROBLEM 8: Coding Challenge - Rotate List

Write a function to rotate a singly linked list to the right by k positions.
Each node moves k positions to the right, wrapping around as needed.

Requirements:
- Handle k > list length (use modulo)
- Handle empty list
- Do not create new nodes (rearrange existing ones)
*/

ROOT* rotate_right(ROOT *root, int k) {
    // YOUR CODE HERE
    // Hint: Break list at rotation point, then reconnect
}

PART A: What's the time complexity of this operation?
PART B: How would you rotate left instead of right?
PART C: What happens if k is 0?
PART D: Why is this operation useful in circular buffers?
*/

/*
YOUR CODE:
*/

// ==================== TEST FUNCTIONS ====================

void create_test_list(ROOT *list, int size) {
    for (int i = 1; i <= size; i++) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = (int*)malloc(sizeof(int));
        *(new_node->data) = i * 5;
        new_node->next = list->head;
        list->head = new_node;
    }
}

void print_list(ROOT *list) {
    NODE *current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", *(current->data));
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("HW5-BASED FINAL PRACTICE\n");
    printf("=============================\n\n");
    
    printf("This practice covers coding and analysis of singly linked lists\n");
    printf("similar to your Homework 5 and midterm questions!\n\n");
    
    printf("Answer the analysis questions first, then implement coding challenges.\n");
    printf("Focus on understanding pointer manipulation and edge cases.\n\n");
    
    return 0;
}
