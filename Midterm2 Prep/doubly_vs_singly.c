#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
SINGLY vs DOUBLY LINKED LISTS - Key Differences
==============================================================================

SINGLY LINKED LIST (what you know from Homework 5):
- Each node points only to NEXT node
- Can only traverse in one direction (forward)
- Simple structure, less memory

DOUBLY LINKED LIST (new for final exam):
- Each node points to PREVIOUS and NEXT node
- Can traverse in BOTH directions
- More complex, but more flexible
==============================================================================
*/

// Singly linked list node (what you're used to)
typedef struct singly_node {
    int data;
    struct singly_node *next;  // Only points forward
} SINGLY_NODE;

// Doubly linked list node (new concept)
typedef struct doubly_node {
    int data;
    struct doubly_node *prev;  // Points backward
    struct doubly_node *next;  // Points forward
} DOUBLY_NODE;

// ==================== STRUCTURE DIFFERENCES ====================

void show_structure_differences() {
    printf("=== STRUCTURE DIFFERENCES ===\n\n");
    
    printf("SINGLY LINKED LIST:\n");
    printf("struct node {\n");
    printf("    int data;\n");
    printf("    struct node *next;  // Only forward pointer\n");
    printf("};\n\n");
    
    printf("DOUBLY LINKED LIST:\n");
    printf("struct node {\n");
    printf("    int data;\n");
    printf("    struct node *prev;  // Backward pointer\n");
    printf("    struct node *next;  // Forward pointer\n");
    printf("};\n\n");
    
    printf("MEMORY DIFFERENCE:\n");
    printf("- Singly: 1 pointer per node\n");
    printf("- Doubly: 2 pointers per node\n");
    printf("- Doubly uses more memory but more functionality\n\n");
}

// ==================== TRAVERSAL DIFFERENCES ====================

void demonstrate_traversal() {
    printf("=== TRAVERSAL DIFFERENCES ===\n\n");
    
    printf("SINGLY LIST TRAVERSAL:\n");
    printf("- Can only go FORWARD (head → tail)\n");
    printf("- To go backwards: must start from head again\n");
    printf("- Cannot easily go to previous node\n\n");
    
    printf("DOUBLY LIST TRAVERSAL:\n");
    printf("- Can go FORWARD (using next pointer)\n");
    printf("- Can go BACKWARD (using prev pointer)\n");
    printf("- Can start from any node and go both ways\n");
    printf("- Much more flexible for navigation\n\n");
}

// ==================== OPERATION DIFFERENCES ====================

// Singly linked list operations
void singly_insert_after(SINGLY_NODE *node, int data) {
    SINGLY_NODE *new_node = (SINGLY_NODE*)malloc(sizeof(SINGLY_NODE));
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;
    printf("Singly: Inserted %d after %d\n", data, node->data);
}

// Doubly linked list operations
void doubly_insert_after(DOUBLY_NODE *node, int data) {
    DOUBLY_NODE *new_node = (DOUBLY_NODE*)malloc(sizeof(DOUBLY_NODE));
    new_node->data = data;
    new_node->next = node->next;
    new_node->prev = node;
    
    if (node->next != NULL) {
        node->next->prev = new_node;
    }
    
    node->next = new_node;
    printf("Doubly: Inserted %d after %d\n", data, node->data);
}

void demonstrate_operations() {
    printf("=== OPERATION DIFFERENCES ===\n\n");
    
    printf("INSERTION COMPLEXITY:\n");
    printf("- Singly: Need to find node BEFORE insertion point\n");
    printf("- Doubly: Can navigate directly to insertion point\n\n");
    
    printf("DELETION DIFFERENCES:\n");
    printf("- Singly: Need to track PREVIOUS node to delete current\n");
    printf("- Doubly: Can delete directly using prev pointer\n\n");
}

// ==================== DELETE OPERATION EXAMPLES ====================

// Singly list deletion (more complex)
void singly_delete(SINGLY_NODE **head, int target_data) {
    if (*head == NULL) return;
    
    // Special case: deleting head
    if ((*head)->data == target_data) {
        SINGLY_NODE *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Singly: Deleted head %d\n", target_data);
        return;
    }
    
    // General case: need to find PREVIOUS node
    SINGLY_NODE *current = *head;
    SINGLY_NODE *prev = NULL;
    
    while (current != NULL && current->data != target_data) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL) {
        prev->next = current->next;
        free(current);
        printf("Singly: Deleted %d\n", target_data);
    }
}

// Doubly list deletion (simpler)
void doubly_delete(DOUBLY_NODE *target) {
    if (target == NULL) return;
    
    // Connect previous and next nodes directly
    if (target->prev != NULL) {
        target->prev->next = target->next;
    }
    
    if (target->next != NULL) {
        target->next->prev = target->prev;
    }
    
    printf("Doubly: Deleted %d\n", target->data);
    free(target);
}

void demonstrate_deletion() {
    printf("=== DELETION DIFFERENCES ===\n\n");
    
    printf("SINGLY DELETE:\n");
    printf("- Need to track previous node while traversing\n");
    printf("- More complex edge cases (head, middle, tail)\n");
    printf("- O(n) time to find node, then O(1) to delete\n\n");
    
    printf("DOUBLY DELETE:\n");
    printf("- Can delete directly if you have the node pointer\n");
    printf("- Simpler edge case handling\n");
    printf("- O(1) deletion if you have node pointer\n\n");
}

// ==================== VISUAL EXAMPLE ====================

void create_visual_example() {
    printf("=== VISUAL EXAMPLE ===\n\n");
    
    printf("SINGLY LIST: A → B → C → D\n");
    printf("To delete C: Need to track B as previous\n");
    printf("To insert after B: Easy with B->next pointer\n\n");
    
    printf("DOUBLY LIST: A ↔ B ↔ C ↔ D\n");
    printf("To delete C: Just connect B ↔ D directly\n");
    printf("To insert after B: Connect B ↔ NEW ↔ C\n\n");
}

// ==================== WHEN TO USE WHICH ====================

void usage_recommendations() {
    printf("=== WHEN TO USE WHICH ===\n\n");
    
    printf("USE SINGLY WHEN:\n");
    printf("- Only need forward traversal\n");
    printf("- Memory is critical concern\n");
    printf("- Simpler implementation needed\n");
    printf("- Example: Stack, queue, basic list\n\n");
    
    printf("USE DOUBLY WHEN:\n");
    printf("- Need bidirectional traversal\n");
    printf("- Frequent insertions/deletions\n");
    printf("- Browser history (forward/back buttons)\n");
    printf("- Music playlist (next/previous track)\n");
    printf("- Text editor cursor movement\n");
    printf("- Example: Project 2 sparse matrices!\n\n");
}

// ==================== EXAM RELEVANCE ====================

void exam_relevance() {
    printf("=== EXAM RELEVANCE ===\n\n");
    
    printf("FOR YOUR FINAL EXAM:\n");
    printf("1. Understand both structures\n");
    printf("2. Know three key operations:\n");
    printf("   - SEARCH: Find a node\n");
    printf("   - INSERT: Add a node\n");
    printf("   - DELETE: Remove a node\n");
    printf("3. Analyze code for both types\n");
    printf("4. Know trade-offs:\n");
    printf("   - Singly: Less memory, less flexible\n");
    printf("   - Doubly: More memory, more flexible\n\n");
    
    printf("COMMON EXAM QUESTIONS:\n");
    printf("- 'What's the advantage of doubly over singly?'\n");
    printf("- 'Show deletion operation for both types'\n");
    printf("- 'Analyze time complexity of operations'\n");
    printf("- 'Fix bugs in linked list code'\n\n");
}

int main() {
    printf("DOUBLY vs SINGLY LINKED LISTS - Complete Guide\n");
    printf("===============================================\n\n");
    
    show_structure_differences();
    demonstrate_traversal();
    demonstrate_operations();
    demonstrate_deletion();
    create_visual_example();
    usage_recommendations();
    exam_relevance();
    
    printf("=== KEY TAKEAWAY ===\n");
    printf("Singly: One-way street (next only)\n");
    printf("Doubly: Two-way street (prev + next)\n");
    printf("Both have same search/insert logic, but doubly is more flexible!\n\n");
    
    return 0;
}
