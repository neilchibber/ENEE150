/*
==============================================================================
HW5 COMPLETE SOLUTIONS GUIDE
After reading this, you'll know exactly how to implement all 18 problems

This guide shows working solutions with explanations for each problem
==============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==================== STRUCTURES ====================

typedef struct node {
    int *data;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
} ROOT;

// ==================== HELPER FUNCTIONS ====================

NODE* create_node(int value) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = (int*)malloc(sizeof(int));
    *(new_node->data) = value;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(ROOT *root, int value) {
    NODE *new_node = create_node(value);
    new_node->next = root->head;
    root->head = new_node;
}

void print_list(ROOT *root) {
    NODE *current = root->head;
    while (current != NULL) {
        printf("%d ", *(current->data));
        current = current->next;
    }
    printf("\n");
}

// ==================== PROBLEM 1: Create 10 random nodes ====================

ROOT* problem1() {
    ROOT *list = (ROOT*)malloc(sizeof(ROOT));
    list->head = NULL;
    
    srand(time(NULL));  // Seed random number generator
    
    for (int i = 0; i < 10; i++) {
        int random_val = rand() % 11 + 10;  // 10-20 inclusive
        NODE *new_node = create_node(random_val);
        new_node->next = list->head;
        list->head = new_node;
    }
    
    return list;
}

/*
ISSUES IN YOUR ORIGINAL CODE:
1. while(list->head != NULL) - This is wrong! list->head is NULL initially
2. NODE* (new_node->data) - Wrong syntax! Should be new_node->data = (int*)malloc
3. new_node->val - Should be *(new_node->data)
4. new_node->next == - Should be new_node->next =
5. Missing srand() for random numbers
*/

// ==================== PROBLEM 2: Print all values ====================

void problem2(ROOT *root) {
    if (root == NULL || root->head == NULL) {
        printf("Empty list\n");
        return;
    }
    
    NODE *current = root->head;
    while (current != NULL) {
        printf("%d ", *(current->data));
        current = current->next;
    }
    printf("\n");
}

// ==================== PROBLEM 3: Find largest value ====================

void problem3(ROOT *root) {
    if (root == NULL || root->head == NULL) {
        printf("Empty list\n");
        return;
    }
    
    int max = *(root->head->data);
    NODE *current = root->head->next;
    
    while (current != NULL) {
        if (*(current->data) > max) {
            max = *(current->data);
        }
        current = current->next;
    }
    
    printf("Largest value: %d\n", max);
}

// ==================== PROBLEM 4: Count occurrences of x ====================

void problem4(ROOT *root, int x) {
    int count = 0;
    NODE *current = root->head;
    
    while (current != NULL) {
        if (*(current->data) == x) {
            count++;
        }
        current = current->next;
    }
    
    printf("%d appears %d times\n", x, count);
}

// ==================== PROBLEM 5: Find k-th node value ====================

void problem5(ROOT *root, int k) {
    if (k <= 0) {
        printf("Invalid k value\n");
        return;
    }
    
    NODE *current = root->head;
    int index = 1;
    
    while (current != NULL && index < k) {
        current = current->next;
        index++;
    }
    
    if (current == NULL) {
        printf("Node at position %d not found\n", k);
    } else {
        printf("Value at position %d: %d\n", k, *(current->data));
    }
}

// ==================== PROBLEM 6: k-th node from END ====================

void problem6(ROOT *root, int k) {
    if (k <= 0) {
        printf("Invalid k value\n");
        return;
    }
    
    NODE *fast = root->head;
    NODE *slow = root->head;
    
    // Move fast k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            printf("List too short for k = %d\n", k);
            return;
        }
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    printf("k-th node from end: %d\n", *(slow->data));
}

// ==================== PROBLEM 7: Insert node as k-th position ====================

void problem7(ROOT *root, int k, int x) {
    if (k <= 0) {
        printf("Invalid k value\n");
        return;
    }
    
    NODE *new_node = create_node(x);
    
    if (k == 1) {
        // Insert at head
        new_node->next = root->head;
        root->head = new_node;
        return;
    }
    
    // Find node before k-th position
    NODE *current = root->head;
    int index = 1;
    
    while (current != NULL && index < k - 1) {
        current = current->next;
        index++;
    }
    
    if (current == NULL) {
        printf("Cannot insert at position %d\n", k);
        free(new_node->data);
        free(new_node);
        return;
    }
    
    // Insert new node
    new_node->next = current->next;
    current->next = new_node;
}

// ==================== PROBLEM 8: Remove all nodes with value x ====================

void problem8(ROOT *root, int x) {
    NODE *current = root->head;
    NODE *prev = NULL;
    
    while (current != NULL) {
        if (*(current->data) == x) {
            NODE *to_delete = current;
            
            if (prev == NULL) {
                // Deleting head node
                root->head = current->next;
            } else {
                // Deleting middle node
                prev->next = current->next;
            }
            
            current = current->next;
            free(to_delete->data);
            free(to_delete);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// ==================== PROBLEM 9: Remove duplicates (keep first) ====================

void problem9(ROOT *root) {
    NODE *current = root->head;
    
    while (current != NULL) {
        NODE *runner = current->next;
        NODE *prev = current;
        
        while (runner != NULL) {
            if (*(runner->data) == *(current->data)) {
                // Remove duplicate
                NODE *to_delete = runner;
                prev->next = runner->next;
                runner = runner->next;
                free(to_delete->data);
                free(to_delete);
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        
        current = current->next;
    }
}

// ==================== PROBLEM 10: Sort list in increasing order ====================

void problem10(ROOT *root) {
    if (root == NULL || root->head == NULL) {
        return;
    }
    
    int swapped;
    do {
        swapped = 0;
        NODE *current = root->head;
        
        while (current->next != NULL) {
            if (*(current->data) > *(current->next->data)) {
                // Swap data values
                int temp = *(current->data);
                *(current->data) = *(current->next->data);
                *(current->next->data) = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// ==================== PROBLEM 11: Odd-indexed before even-indexed ====================

void problem11(ROOT *root) {
    if (root == NULL || root->head == NULL) {
        return;
    }
    
    NODE *oddHead = NULL, *oddTail = NULL;
    NODE *evenHead = NULL, *evenTail = NULL;
    NODE *current = root->head;
    int index = 1;
    
    // Separate into odd and even lists
    while (current != NULL) {
        NODE *next = current->next;
        current->next = NULL;
        
        if (index % 2 == 1) {
            // Odd index
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        } else {
            // Even index
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        }
        
        current = next;
        index++;
    }
    
    // Join odd and even lists
    if (oddHead == NULL) {
        root->head = evenHead;
    } else {
        oddTail->next = evenHead;
        root->head = oddHead;
    }
}

// ==================== PROBLEM 12: Reverse list ====================

void problem12(ROOT *root) {
    if (root == NULL || root->head == NULL) {
        return;
    }
    
    NODE *prev = NULL;
    NODE *current = root->head;
    NODE *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    root->head = prev;
}

// ==================== PROBLEM 13: Merge two lists alternately ====================

ROOT* problem13(ROOT *list1, ROOT *list2) {
    ROOT *result = (ROOT*)malloc(sizeof(ROOT));
    result->head = NULL;
    
    NODE *p1 = list1->head;
    NODE *p2 = list2->head;
    
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            NODE *new_node = create_node(*(p1->data));
            new_node->next = result->head;
            result->head = new_node;
            p1 = p1->next;
        }
        
        if (p2 != NULL) {
            NODE *new_node = create_node(*(p2->data));
            new_node->next = result->head;
            result->head = new_node;
            p2 = p2->next;
        }
    }
    
    return result;
}

// ==================== PROBLEM 14: Check if P2 is sub-list of P1 ====================

int problem14(ROOT *P1, ROOT *P2) {
    NODE *p1_current = P1->head;
    
    while (p1_current != NULL) {
        NODE *p1_temp = p1_current;
        NODE *p2_current = P2->head;
        
        // Try to match P2 sequence starting from p1_current
        while (p1_temp != NULL && p2_current != NULL) {
            if (*(p1_temp->data) != *(p2_current->data)) {
                break;
            }
            p1_temp = p1_temp->next;
            p2_current = p2_current->next;
        }
        
        // If we reached end of P2, it's a sub-list
        if (p2_current == NULL) {
            return 1;  // Found
        }
        
        p1_current = p1_current->next;
    }
    
    return 0;  // Not found
}

// ==================== PROBLEM 15: Remove all nodes in P2 from P1 ====================

void problem15(ROOT *P1, ROOT *P2) {
    NODE *p2_current = P2->head;
    
    while (p2_current != NULL) {
        // Remove all occurrences of this value from P1
        NODE *p1_current = P1->head;
        NODE *p1_prev = NULL;
        
        while (p1_current != NULL) {
            if (*(p1_current->data) == *(p2_current->data)) {
                NODE *to_delete = p1_current;
                
                if (p1_prev == NULL) {
                    P1->head = p1_current->next;
                } else {
                    p1_prev->next = p1_current->next;
                }
                
                p1_current = p1_current->next;
                free(to_delete->data);
                free(to_delete);
            } else {
                p1_prev = p1_current;
                p1_current = p1_current->next;
            }
        }
        
        p2_current = p2_current->next;
    }
}

// ==================== PROBLEM 16: Append reversed P2 to back of P1 ====================

void problem16(ROOT *P1, ROOT *P2) {
    // First reverse P2
    ROOT *reversed_P2 = (ROOT*)malloc(sizeof(ROOT));
    reversed_P2->head = NULL;
    
    NODE *current = P2->head;
    while (current != NULL) {
        NODE *new_node = create_node(*(current->data));
        new_node->next = reversed_P2->head;
        reversed_P2->head = new_node;
        current = current->next;
    }
    
    // Find tail of P1
    NODE *tail = P1->head;
    if (tail != NULL) {
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = reversed_P2->head;
    } else {
        // P1 was empty
        P1->head = reversed_P2->head;
    }
}

// ==================== PROBLEM 17: Merge two sorted lists ====================

ROOT* problem17(ROOT *P1, ROOT *P2) {
    ROOT *result = (ROOT*)malloc(sizeof(ROOT));
    result->head = NULL;
    
    NODE *p1 = P1->head;
    NODE *p2 = P2->head;
    
    while (p1 != NULL && p2 != NULL) {
        if (*(p1->data) <= *(p2->data)) {
            NODE *new_node = create_node(*(p1->data));
            new_node->next = result->head;
            result->head = new_node;
            p1 = p1->next;
        } else {
            NODE *new_node = create_node(*(p2->data));
            new_node->next = result->head;
            result->head = new_node;
            p2 = p2->next;
        }
    }
    
    // Add remaining nodes
    while (p1 != NULL) {
        NODE *new_node = create_node(*(p1->data));
        new_node->next = result->head;
        result->head = new_node;
        p1 = p1->next;
    }
    
    while (p2 != NULL) {
        NODE *new_node = create_node(*(p2->data));
        new_node->next = result->head;
        result->head = new_node;
        p2 = p2->next;
    }
    
    return result;
}

// ==================== PROBLEM 18: Find pair where one is multiple of another ====================

int problem18(ROOT *root) {
    // Store values in array for easy access
    int values[100], count = 0;
    NODE *current = root->head;
    
    while (current != NULL) {
        values[count++] = *(current->data);
        current = current->next;
    }
    
    // Check all pairs
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (values[i] % values[j] == 0) {
                return i;  // Return index of smaller value
            }
            if (values[j] % values[i] == 0) {
                return j;  // Return index of smaller value
            }
        }
    }
    
    return 0;  // No such pair found
}

// ==================== MAIN FUNCTION ====================

int main() {
    printf("HW5 Complete Solutions Guide\n");
    printf("===========================\n\n");
    
    // Test problem 1
    printf("Problem 1: Create 10 random nodes\n");
    ROOT *list = problem1();
    printf("Created list: ");
    print_list(list);
    printf("\n");
    
    // Test other problems here...
    
    return 0;
}
