#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
DOUBLY LINKED LIST TUTORIAL
Based on Finals Announcement: "basic concepts, three key operations: search, insert, delete"

This will teach you step-by-step, then provide practice problems like the exam!
==============================================================================
*/

// Doubly linked list node structure (from your exam)
typedef struct node {
    int data;
    struct node *prev;  // Points to previous node
    struct node *next;  // Points to next node
} NODE;

// Doubly linked list structure
typedef struct {
    NODE *head;  // First node in list
    NODE *tail;  // Last node in list (helpful for some operations)
} DLLIST;

// ==================== LESSON 1: BASIC CONCEPTS ====================

void lesson_basic_concepts() {
    printf("=== LESSON 1: BASIC CONCEPTS ===\n\n");
    
    printf("DOUBLY LINKED LIST STRUCTURE:\n");
    printf("Each node has THREE parts:\n");
    printf("1. DATA: The value stored (int, char, etc.)\n");
    printf("2. PREV: Pointer to previous node\n");
    printf("3. NEXT: Pointer to next node\n\n");
    
    printf("VISUAL REPRESENTATION:\n");
    printf("NULL ↔ A ↔ B ↔ C ↔ D ↔ NULL\n");
    printf("      ^    ^    ^    ^    ^\n");
    printf("      |    |    |    |\n");
    printf("    prev  next  prev  next  prev  next\n\n");
    
    printf("KEY INSIGHTS:\n");
    printf("- Can traverse FORWARD using next pointers\n");
    printf("- Can traverse BACKWARD using prev pointers\n");
    printf("- More memory than singly linked list\n");
    printf("- More flexible for operations\n\n");
}

// ==================== LESSON 2: SEARCH OPERATION ====================

void lesson_search() {
    printf("=== LESSON 2: SEARCH OPERATION ===\n\n");
    
    printf("SEARCH: Find a node with specific data value\n");
    printf("Two approaches: Forward search or backward search\n\n");
    
    printf("FORWARD SEARCH ALGORITHM:\n");
    printf("1. Start at head\n");
    printf("2. Use next pointer to move forward\n");
    printf("3. Check each node's data\n");
    printf("4. Stop when found or reach NULL\n\n");
    
    printf("BACKWARD SEARCH ALGORITHM:\n");
    printf("1. Start at tail (if available)\n");
    printf("2. Use prev pointer to move backward\n");
    printf("3. Check each node's data\n");
    printf("4. Stop when found or reach NULL\n\n");
}

// Implementation of search
NODE* search_forward(DLLIST *list, int target) {
    NODE *current = list->head;
    
    while (current != NULL) {
        if (current->data == target) {
            printf("Found %d in forward search\n", target);
            return current;
        }
        current = current->next;
    }
    
    printf("%d not found in forward search\n", target);
    return NULL;
}

NODE* search_backward(DLLIST *list, int target) {
    NODE *current = list->tail;
    
    while (current != NULL) {
        if (current->data == target) {
            printf("Found %d in backward search\n", target);
            return current;
        }
        current = current->prev;
    }
    
    printf("%d not found in backward search\n", target);
    return NULL;
}

// ==================== LESSON 3: INSERT OPERATION ====================

void lesson_insert() {
    printf("=== LESSON 3: INSERT OPERATION ===\n\n");
    
    printf("INSERT: Add a new node to the list\n");
    printf("Three common positions: Head, Middle, Tail\n\n");
    
    printf("INSERT AT HEAD:\n");
    printf("1. Create new node\n");
    printf("2. Set new->next = current head\n");
    printf("3. Set new->prev = NULL\n");
    printf("4. If old head exists: old->prev = new node\n");
    printf("5. Update head pointer\n\n");
    
    printf("INSERT IN MIDDLE:\n");
    printf("1. Find insertion point\n");
    printf("2. Create new node\n");
    printf("3. Set new->next = current->next\n");
    printf("4. Set new->prev = current\n");
    printf("5. Update surrounding nodes\n\n");
    
    printf("INSERT AT TAIL:\n");
    printf("1. Create new node\n");
    printf("2. Set new->prev = current tail\n");
    printf("3. Set new->next = NULL\n");
    printf("4. If tail exists: tail->next = new node\n");
    printf("5. Update tail pointer\n\n");
}

// Implementation of insert at head
void insert_at_head(DLLIST *list, int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = dtat;
    new_node->next = list->head;
    new_node->prev = NULL;
}

// Implementation of insert after a specific node
void insert_after_node(DLLIST *list, NODE *after_node, int data) {
    NODE* new  = (NODE*)malloc(sizeof((NODE)));
    new->data = data;
    new->next = after_node->next;
    new->prev = after_node;
    after_node->next = new;
    printf("Inserted %d after node with data %d\n", data, after_node->data);
}

// ==================== LESSON 4: DELETE OPERATION ====================

void lesson_delete() {
    printf("=== LESSON 4: DELETE OPERATION ===\n\n");
    
    printf("DELETE: Remove a node from the list\n");
    printf("Three cases to handle: Head, Middle, Tail\n\n");
    
    printf("DELETE HEAD:\n");
    printf("1. Update head to head->next\n");
    printf("2. Set new head->prev = NULL\n");
    printf("3. Free old head\n\n");
    
    printf("DELETE MIDDLE:\n");
    printf("1. Connect prev->next = current->next\n");
    printf("2. Connect next->prev = current->prev\n");
    printf("3. Free current node\n\n");
    
    printf("DELETE TAIL:\n");
    printf("1. Update tail to tail->prev\n");
    printf("2. Set new tail->next = NULL\n");
    printf("3. Free old tail\n\n");
    
    printf("KEY ADVANTAGE:\n");
    printf("Doubly lists make deletion O(1) if you have node pointer!\n");
    printf("(Singly lists need O(n) to find previous node)\n\n");
}

// Implementation of delete
void delete_node(DLLIST *list, NODE *target) {
    if (target == NULL) return;
    
    printf("Deleting node with data %d\n", target->data);
    
    // Case 1: Deleting head
    if (target == list->head) {
        list->head = target->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        } else {
            list->tail = NULL;
        }
    }
    // Case 2: Deleting tail
    else if (target == list->tail) {
        list->tail = target->prev;
        list->tail->next = NULL;
    }
    // Case 3: Deleting middle node
    else {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    
    free(target);
    printf("Delete operation completed\n");
}

// ==================== PRACTICE PROBLEMS ====================

void practice_problems() {
    printf("=== PRACTICE PROBLEMS ===\n\n");
    
    printf("PROBLEM 1: Search Analysis\n");
    printf("Given: DLLIST with nodes [10, 20, 30, 40, 50]\n");
    printf("Question: What does search_forward(list, 30) return?\n");
    printf("Answer: Pointer to node with data 30\n\n");
    
    printf("PROBLEM 2: Insert Analysis\n");
    printf("Given: Empty list, insert_at_head(list, 15)\n");
    printf("Question: What are the head and tail pointers after?\n");
    printf("Answer: head points to node(15), tail points to node(15)\n\n");
    
    printf("PROBLEM 3: Delete Analysis\n");
    printf("Given: List [5 ↔ 10 ↔ 15], delete node with data 10\n");
    printf("Question: What does the list look like after?\n");
    printf("Answer: [5 ↔ 15]\n\n");
    
    printf("PROBLEM 4: Edge Cases\n");
    printf("Question 1: What happens if you delete from empty list?\n");
    printf("Answer 1: Function should return without crashing\n\n");
    printf("Question 2: What happens if you delete NULL pointer?\n");
    printf("Answer 2: Function should check and return early\n\n");
    
    printf("PROBLEM 5: Time Complexity\n");
    printf("Question: What's the time complexity of search in doubly list?\n");
    printf("Answer: O(n) - same as singly, but deletion is O(1) with node pointer\n\n");
}

// ==================== EXAM-STYLE QUESTIONS ====================

void exam_style_questions() {
    printf("=== EXAM-STYLE QUESTIONS ===\n\n");
    
    printf("QUESTION: Analyze this delete operation\n");
    printf("CODE:\n");
    printf("void delete_middle(DLLIST *list, NODE *target) {\n");
    printf("    target->prev->next = target->next;\n");
    printf("    target->next->prev = target->prev;\n");
    printf("    free(target);\n");
    printf("}\n\n");
    
    printf("ISSUES TO IDENTIFY:\n");
    printf("1. What edge case is missing?\n");
    printf("2. What happens if target is head?\n");
    printf("3. What happens if target is tail?\n\n");
    
    printf("ANSWERS:\n");
    printf("1. No NULL check for target\n");
    printf("2. Head pointer not updated\n");
    printf("3. Tail pointer not updated\n\n");
}

// ==================== MAIN FUNCTION ====================

int main() {
    printf("DOUBLY LINKED LIST COMPLETE TUTORIAL\n");
    printf("=====================================\n\n");
    
    // Teach the concepts
    lesson_basic_concepts();
    lesson_search();
    lesson_insert();
    lesson_delete();
    
    printf("\n");
    practice_problems();
    exam_style_questions();
    
    printf("\n=== EXAM PREPARATION COMPLETE ===\n");
    printf("You now understand:\n");
    printf("- Doubly linked list structure\n");
    printf("- Three key operations: search, insert, delete\n");
    printf("- Edge cases and error handling\n");
    printf("- Time complexity analysis\n");
    printf("- Ready for exam questions!\n\n");
    
    return 0;
}
