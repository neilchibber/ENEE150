/*
==============================================================================
HW5 ASSIGNMENT OUTLINE - Complete Guide
Based on HW5TESTING.c - 18 Linked List Problems

This outline provides structure and hints for each problem
==============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==================== STRUCTURES (from HW5) ====================

typedef struct node {
    int *data;           // Pointer to integer value
    struct node *next;   // Next node in list
} NODE;

typedef struct {
    NODE *head;          // First node in list
} ROOT;

// ==================== HELPER FUNCTIONS ====================

// Create a new node with given value
NODE* create_node(int value) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = (int*)malloc(sizeof(int));
    *(new_node->data) = value;
    new_node->next = NULL;
    return new_node;
}

// Insert node at head of list
void insert_at_head(ROOT *root, int value) {
    NODE *new_node = create_node(value);
    new_node->next = root->head;
    root->head = new_node;
}

// Print entire list
void print_list(ROOT *root) {
    NODE *current = root->head;
    while (current != NULL) {
        printf("%d ", *(current->data));
        current = current->next;
    }
    printf("\n");
}

// ==================== PROBLEM OUTLINES ====================

/*
==============================================================================
PROBLEM 1: Create 10 random nodes (10-20) and connect them
==============================================================================
OUTLINE:
1. Create ROOT pointer with malloc
2. Initialize root->head = NULL
3. Use srand(time(NULL)) for random numbers
4. Loop 10 times:
   - Generate random number (10-20): rand() % 11 + 10
   - Create node with this value
   - Insert into list
5. Return ROOT pointer

HINT: Use insert_at_head() helper function
*/

ROOT* problem1() {
   ROOT* list = (ROOT*)malloc(sizeof(ROOT));
   list->head = NULL;
   while(list->head != NULL) {
    for(i=0; i<10; i++){
      NODE* new_node = (NODE*)malloc(sizeof(NODE));
      NODE* (new_node->data) = (NODE*)malloc(sizeof(int));
      *(new_node->data) = rand() % 11 + 10
      new_node->next == list->head;
      list->head = new_node;

  } 
}
}

/*
==============================================================================
PROBLEM 2: Print all data values in list
==============================================================================
OUTLINE:
1. Check if root is NULL or root->head is NULL
2. Start at root->head
3. While current != NULL:
   - Print *(current->data)
   - Move to current->next
4. Print newline

HINT: Simple traversal - use print_list() or write your own
*/

void problem2(ROOT *root) {
    if (root == NULL || root->head == NULL) {
        return;
    }
    NODE* current = root->head;
    while(current != NULL){
        printf("%d ", *(current->data));
        current = current->next;
    }
    printf("\n");
}

/*
==============================================================================
PROBLEM 3: Find and print largest value
==============================================================================
OUTLINE:
1. Handle empty list case
2. Initialize max = *(root->head->data)
3. Traverse list:
   - If *(current->data) > max, update max
4. Print max value

HINT: Keep track of running maximum
*/

void problem3(ROOT *root) {
    if (root == NULL || root->head == NULL){
        return;
    }
    NODE* current = root->head;
    int max = *(current->data);
    while(current != NULL){
        if(current->data > max){
            max = current->data;
            current = current->next;
        }
    }
    printf("%d\n", max);
}

/*
==============================================================================
PROBLEM 4: Count occurrences of value x
==============================================================================
OUTLINE:
1. Initialize count = 0
2. Traverse list:
   - If *(current->data) == x, increment count
3. Print count

HINT: Simple comparison while traversing
*/

void problem4(ROOT *root, int x) {
    if(root == NULL || root->head == NULL){
        return;
    }
    NODE* current = root->head;
    int count = 0;
    while(current != NULL){
        if(*(current->data) == x){
            count++;
        }
        current = current->next;
    }
    printf("%d\n", count);
}

/*
==============================================================================
PROBLEM 5: Find k-th node value (1-indexed)
==============================================================================
OUTLINE:
1. Safety check: k <= 0 -> print error
2. Traverse list with index counter:
   - If index == k, print value and return
   - If reach end before k, print "not found"
3. Handle edge cases

HINT: Use counter starting from 1
*/

void problem5(ROOT *root, int k) {
    if(root == NULL || root->head == NULL){
        return;
    }
    if(k <= 0){
        return;
    }
    NODE* current = root->head;
    while(current != NULL){
        for(int i = 0; i <= k; i++){
            current = current->next;
        }
        printf("%d\n", *(current->data));
    }

}

/*
==============================================================================
PROBLEM 6: Find k-th node from END (single pass)
==============================================================================
OUTLINE:
1. Use two-pointer technique:
   - Move first pointer k steps ahead
   - Then move both pointers together
2. When first reaches end, second is at k-th from end
3. Safety checks for k > list length

HINT: Classic two-pointer problem
*/

void problem6(ROOT *root, int k) {

    if (root == NULL || root->head == NULL){
        return;
    }
    NODE* fast = root->head;
    NODE* slow = root->head;

    for(int i = 0; i < k; i++){
        fast = fast->next;
    }
    printf("%d\n", *(slow->data));
}

/*
==============================================================================
PROBLEM 7: Insert new node as k-th position
==============================================================================
OUTLINE:
1. Create new node with value x
2. Handle k = 1 (insert at head)
3. Traverse to (k-1)-th node
4. Insert new node after that node
5. Handle edge cases (k > length)

HINT: Need to find node BEFORE insertion point
*/

void problem7(ROOT *root, int k, int x) {
    if (root == NULL || root->head == NULL){return;}
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = (int*)malloc(sizeof(int));
    NODE* curr = root->head;
    NODE* next = curr->next;

    for (int i = 0; i < k; i++){
        if(next == NULL){
            return;
        }
        curr = next;
        next = next->next;
    }
    *(curr->data) = x;
    curr->next = next;
}

/*
==============================================================================
PROBLEM 8: Remove all nodes with value x
==============================================================================
OUTLINE:
1. Handle head deletions separately
2. Use prev pointer to track previous node
3. For each node with value x:
   - prev->next = current->next
   - free current
4. Continue traversal

HINT: Need to maintain prev pointer for deletions
*/

void problem8(ROOT *root, int x) {
    if(root == NULL || root->head == NULL){
        return;
    }
    NODE* curr = root->head;
    while(curr != NULL){
        if(*(curr->data) == x){
            NODE* todelete = curr;
            NODE* temp = curr;
            free(curr->data);
            free(curr);
            curr = temp->next;
        }
        curr = curr->next;
    }
}

/*
==============================================================================
PROBLEM 9: Remove duplicate values (keep first occurrence)
==============================================================================
OUTLINE:
1. Use nested loops:
   - Outer loop: current node
   - Inner loop: check for duplicates after current
2. For each duplicate found:
   - Remove node using prev pointer
3. Keep only first occurrence

HINT: O(n²) solution is acceptable
*/

void problem9(ROOT *root) {
    if (root == NULL || root->head == NULL) {return;}
    NODE* curr = root->head;
    while (curr != NULL){
        NODE* runner = root->head->next;
            while(runner != NULL){
                if(*(curr->data) = *(runner->data)){
                    NODE* delete = runner;
                    NODE* temp = runner;
                    free(runner->data);
                    free(runner);
                    runner = temp->next;
                }
    
    }
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 10: Sort list in increasing order
==============================================================================
OUTLINE:
1. Use bubble sort or selection sort
2. For bubble sort:
   - Compare adjacent nodes
   - Swap data values if out of order
   - Repeat until no swaps
3. Don't swap node pointers, swap data

HINT: Easier to swap data values than pointers
*/

void problem10(ROOT *root) {
    if(root == NULL || root->head == NULL){
        return;
    }
    NODE* curr = root->head;
    NODE* next = root->head->next;
    while(curr != NULL){
        if(*(curr->data) > *(next->data)){
            int temp = *(curr->data);
            *(curr->data) = *(next->data);
            *(next->data) = temp;
        }
    }

}

/*
==============================================================================
PROBLEM 11: Rearrange odd-indexed nodes before even-indexed
==============================================================================
OUTLINE:
1. Create two separate lists: odd and even
2. Traverse original list:
   - Odd index -> add to odd list
   - Even index -> add to even list
3. Connect odd list to even list
4. Update root->head

HINT: Similar to HW5_11.c oddEvenRearrange()
*/

void problem11(ROOT *root) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 12: Reverse the list
==============================================================================
OUTLINE:
1. Use three pointers: prev, current, next
2. While current != NULL:
   - next = current->next
   - current->next = prev
   - prev = current
   - current = next
3. Update root->head = prev

HINT: Classic linked list reversal
*/

void problem12(ROOT *root) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 13: Merge two lists alternately
==============================================================================
OUTLINE:
1. Create new ROOT for result
2. Use two pointers: p1 and p2
3. While both lists have nodes:
   - Add p1 node to result
   - Add p2 node to result
4. Add remaining nodes from longer list
5. Return result

HINT: Don't modify original lists
*/

ROOT* problem13(ROOT *list1, ROOT *list2) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 14: Check if P2 is sub-list of P1
==============================================================================
OUTLINE:
1. For each possible starting position in P1:
   - Compare sequence with P2
   - If full match found, return 1
2. If no match found after checking all positions, return 0

HINT: String matching pattern for linked lists
*/

int problem14(ROOT *P1, ROOT *P2) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 15: Remove all nodes in P2 from P1
==============================================================================
OUTLINE:
1. For each value in P2:
   - Remove all occurrences of that value from P1
2. Use problem8() function for each value
3. Handle multiple occurrences

HINT: Reuse problem8() logic
*/

void problem15(ROOT *P1, ROOT *P2) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 16: Append reversed P2 to back of P1
==============================================================================
OUTLINE:
1. Reverse P2 using problem12() logic
2. Find tail of P1
3. Connect tail to head of reversed P2
4. Don't modify original P2 (create copy if needed)

HINT: Combine reversal and list joining
*/

void problem16(ROOT *P1, ROOT *P2) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 17: Merge two sorted lists (maintain sorted order)
==============================================================================
OUTLINE:
1. Both lists are already sorted
2. Use two pointers to traverse both lists
3. Always add smaller value to result
4. When one list ends, add remaining from other
5. Return merged sorted list

HINT: Classic merge algorithm (like merge sort)
*/

ROOT* problem17(ROOT *P1, ROOT *P2) {
    // YOUR CODE HERE
}

/*
==============================================================================
PROBLEM 18: Find pair where one value is multiple of another
==============================================================================
OUTLINE:
1. Use nested loops to check all pairs
2. For each pair (i, j):
   - If values[i] % values[j] == 0 or vice versa
   - Return index of smaller value
3. If no such pair found, return 0

HINT: Check both directions for multiples
*/

int problem18(ROOT *root) {
    // YOUR CODE HERE
}

// ==================== MAIN FUNCTION TEMPLATE ====================

int main() {
    printf("HW5 Complete Assignment\n");
    printf("======================\n\n");
    
    // Test each problem here
    // ROOT *list = problem1();
    // problem2(list);
    // problem3(list);
    // ... etc
    
    return 0;
}
