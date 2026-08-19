#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
STRUCT EXPLANATION - Understanding ENTRY and ROOT structs
==============================================================================

1. ENTRY struct (represents one node/data element):
   - This is your "NODE" structure
   - Holds data and pointers to other nodes
   - Used for sparse matrix entries but works for any linked list

2. ROOT struct (represents the entire list):
   - This is your list "container"
   - Points to the first node (head)
   - Keeps track of list size
==============================================================================
*/

// The ENTRY struct - represents one node in the linked list
typedef struct entry
{
    int val;                     // The main data/value stored in this node
    int row, col;                // Position data (for matrix use)
    struct entry *left, *right;  // Pointers to neighboring nodes (matrix-specific)
    struct entry *up, *down;     // More matrix-specific pointers
    struct entry *next;          // KEY: Pointer to the next node in the list
    void *info;                  // Generic pointer for extra data
} ENTRY;

// The ROOT struct - represents the entire linked list
typedef struct root
{
    ENTRY *head;                 // KEY: Pointer to the first node in the list
    long num;                    // Number of nodes in the list
    void *info;                  // Generic pointer for extra data
} ROOT;

/*
==============================================================================
HOW TO WORK WITH THESE STRUCTS:
==============================================================================

1. CREATING NODES:
   - Always use malloc() to allocate memory
   - Initialize all pointers to NULL
   - Set the data values

2. BUILDING LISTS:
   - Create a ROOT first (this is your list container)
   - Add nodes using the ROOT's head pointer
   - Use the 'next' pointer to link nodes together

3. TRAVERSING LISTS:
   - Start at ROOT->head
   - Follow the 'next' pointers
   - Stop when you reach NULL

4. KEY POINTERS:
   - ROOT->head: Points to the first node
   - ENTRY->next: Points to the next node
   - Last node's next is always NULL
==============================================================================
*/

// Example: Creating and working with the structs
void demonstrate_structs()
{
    // 1. Create a ROOT (the list container)
    ROOT *my_list = (ROOT*)malloc(sizeof(ROOT));
    my_list->head = NULL;  // Start with empty list
    my_list->num = 0;
    
    // 2. Create first node
    ENTRY *node1 = (ENTRY*)malloc(sizeof(ENTRY));
    node1->val = 10;
    node1->row = 1;
    node1->col = 1;
    node1->next = NULL;  // This will be the last node (for now)
    
    // 3. Add first node to the list
    my_list->head = node1;
    my_list->num = 1;
    
    // 4. Create second node
    ENTRY *node2 = (ENTRY*)malloc(sizeof(ENTRY));
    node2->val = 20;
    node2->row = 2;
    node2->col = 2;
    node2->next = NULL;  // This will be the new last node
    
    // 5. Link second node to the list
    node1->next = node2;  // First node points to second node
    my_list->num = 2;
    
    // 6. Traverse and print the list
    printf("List traversal:\n");
    ENTRY *current = my_list->head;  // Start at the first node
    int position = 1;
    
    while (current != NULL)  // Continue until we reach the end
    {
        printf("Node %d: value=%d, position=(%d,%d)\n", 
               position, current->val, current->row, current->col);
        current = current->next;  // Move to the next node
        position++;
    }
    
    printf("Total nodes: %ld\n", my_list->num);
    
    // 7. Accessing specific nodes
    printf("\nAccessing specific nodes:\n");
    printf("First node value: %d\n", my_list->head->val);
    printf("Second node value: %d\n", my_list->head->next->val);
    
    // 8. Finding the last node
    ENTRY *last = my_list->head;
    while (last->next != NULL)  // Keep going until next is NULL
    {
        last = last->next;
    }
    printf("Last node value: %d\n", last->val);
}

/*
==============================================================================
COMMON OPERATIONS:
==============================================================================

1. ACCESS FIRST NODE:    ROOT->head
2. ACCESS SECOND NODE:   ROOT->head->next  
3. ACCESS DATA:          ENTRY->val, ENTRY->row, ENTRY->col
4. MOVE TO NEXT NODE:    current = current->next
5. CHECK IF END:         current == NULL
6. LIST SIZE:            ROOT->num
==============================================================================
*/

int main()
{
    printf("=== STRUCT DEMONSTRATION ===\n\n");
    demonstrate_structs();
    
    printf("\n=== KEY CONCEPTS ===\n");
    printf("1. ROOT is the list container\n");
    printf("2. ENTRY is an individual node\n");
    printf("3. ROOT->head points to first ENTRY\n");
    printf("4. ENTRY->next links to next ENTRY\n");
    printf("5. Last ENTRY->next is always NULL\n");
    printf("6. ROOT->num tracks total nodes\n");
    
    return 0;
}
