#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
HOW DOES IT KNOW THE ENTRY IS NON-ZERO?
==============================================================================

The short answer: It doesn't automatically know - it's a DESIGN DECISION!

In a sparse matrix implementation:
1. We ONLY create ENTRY nodes for non-zero values
2. Zero values are NEVER stored in the linked list
3. If a matrix position has value 0, there's no ENTRY node for it

This is the whole point of "sparse" - we save memory by not storing zeros!
==============================================================================
*/

typedef struct entry
{
    int val;                     // We ONLY store non-zero values here
    int row, col;                // Position in matrix
    struct entry *next;          // Next non-zero entry
    void *info;
} ENTRY;

typedef struct root
{
    ENTRY *head;                 // First non-zero entry
    long num;                    // Count of non-zero entries
    void *info;
} ROOT;

// Function to create a new entry - ONLY for non-zero values
ENTRY * make_node(int r, int c, int v)
{
    ENTRY *temp;
    
    // KEY CHECK: We only create nodes for NON-ZERO values
    if (v == 0)  // If value is zero, don't create a node!
    {
        printf("Value %d is zero - NOT creating node at (%d,%d)\n", v, r, c);
        return NULL;
    }
    
    // Only create node if value is non-zero
    temp = (ENTRY*)malloc(sizeof(ENTRY));
    if (temp != NULL)
    { 
        temp->val = v;           // Store the non-zero value
        temp->row = r;
        temp->col = c;
        temp->next = NULL;
        temp->info = NULL;
        printf("Created node: value %d at (%d,%d)\n", v, r, c);
    }
    return temp;
}

// Function to demonstrate the sparse matrix concept
void demonstrate_sparse_concept()
{
    printf("=== SPARSE MATRIX CONCEPT DEMONSTRATION ===\n\n");
    
    printf("FULL MATRIX (3x3):\n");
    printf("[ 5  0  3 ]\n");
    printf("[ 0  7  0 ]\n");
    printf("[ 2  0  0 ]\n\n");
    
    printf("What we STORE in sparse matrix (only non-zeros):\n");
    printf("- 5 at (1,1)\n");
    printf("- 3 at (1,3)\n");
    printf("- 7 at (2,2)\n");
    printf("- 2 at (3,1)\n\n");
    
    printf("What we DON'T store (all the zeros):\n");
    printf("- 0 at (1,2) - NO NODE CREATED\n");
    printf("- 0 at (2,1) - NO NODE CREATED\n");
    printf("- 0 at (2,3) - NO NODE CREATED\n");
    printf("- 0 at (3,2) - NO NODE CREATED\n");
    printf("- 0 at (3,3) - NO NODE CREATED\n\n");
    
    ROOT *sparse_matrix = (ROOT*)malloc(sizeof(ROOT));
    sparse_matrix->head = NULL;
    sparse_matrix->num = 0;
    
    printf("=== CREATING NODES ===\n");
    
    // Try to create nodes for ALL matrix positions
    printf("Attempting to create nodes...\n");
    
    // Row 1: [5, 0, 3]
    ENTRY *n1 = make_node(1, 1, 5);  // Non-zero - will be created
    ENTRY *n2 = make_node(1, 2, 0);  // Zero - will NOT be created
    ENTRY *n3 = make_node(1, 3, 3);  // Non-zero - will be created
    
    // Row 2: [0, 7, 0]  
    ENTRY *n4 = make_node(2, 1, 0);  // Zero - will NOT be created
    ENTRY *n5 = make_node(2, 2, 7);  // Non-zero - will be created
    ENTRY *n6 = make_node(2, 3, 0);  // Zero - will NOT be created
    
    // Row 3: [2, 0, 0]
    ENTRY *n7 = make_node(3, 1, 2);  // Non-zero - will be created
    ENTRY *n8 = make_node(3, 2, 0);  // Zero - will NOT be created
    ENTRY *n9 = make_node(3, 3, 0);  // Zero - will NOT be created
    
    printf("\n=== BUILDING THE LINKED LIST ===\n");
    
    // Link only the successfully created (non-zero) nodes
    ENTRY *nodes[] = {n1, n3, n5, n7};  // Only non-zero nodes
    int node_count = 0;
    
    for (int i = 0; i < 4; i++)
    {
        if (nodes[i] != NULL)  // Only add if node was created (value was non-zero)
        {
            if (sparse_matrix->head == NULL)
            {
                sparse_matrix->head = nodes[i];  // First node
            }
            else
            {
                // Find the last node and link the new one
                ENTRY *current = sparse_matrix->head;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = nodes[i];
            }
            sparse_matrix->num++;
            node_count++;
        }
    }
    
    printf("\n=== RESULTING SPARSE MATRIX ===\n");
    printf("Total nodes stored: %ld\n", sparse_matrix->num);
    printf("Nodes in linked list:\n");
    
    ENTRY *current = sparse_matrix->head;
    int position = 1;
    while (current != NULL)
    {
        printf("Node %d: value %d at (%d,%d)\n", 
               position, current->val, current->row, current->col);
        current = current->next;
        position++;
    }
    
    printf("\n=== KEY INSIGHTS ===\n");
    printf("1. We ONLY create ENTRY nodes for non-zero values\n");
    printf("2. Zero values are completely absent from the data structure\n");
    printf("3. The 'sparse' nature comes from NOT storing zeros\n");
    printf("4. When we access a matrix position:\n");
    printf("   - If there's an ENTRY node: value is non-zero\n");
    printf("   - If there's no ENTRY node: value is assumed to be zero\n");
    printf("5. This saves massive memory for matrices with many zeros!\n");
}

// Function to show how to check if a position is non-zero
int is_nonzero(ROOT *matrix, int row, int col)
{
    if (matrix == NULL) return 0;
    
    ENTRY *current = matrix->head;
    while (current != NULL)
    {
        if (current->row == row && current->col == col)
        {
            return 1;  // Found a node - value is non-zero
        }
        current = current->next;
    }
    return 0;  // No node found - value is zero
}

int main()
{
    demonstrate_sparse_concept();
    
    printf("\n\n=== HOW TO CHECK IF A POSITION IS NON-ZERO ===\n");
    printf("To check if matrix position (2,2) is non-zero:\n");
    printf("1. Search the linked list for a node with row=2, col=2\n");
    printf("2. If found: value is non-zero\n");
    printf("3. If not found: value is zero\n");
    
    return 0;
}
