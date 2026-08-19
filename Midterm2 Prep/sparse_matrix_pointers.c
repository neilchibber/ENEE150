#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
SPARSE MATRIX POINTER EXPLANATION
==============================================================================

In a sparse matrix, we only store non-zero entries. Each ENTRY node has
multiple pointers that serve different purposes:

1. next:    Traverses ALL non-zero entries in some order (usually insertion order)
2. left:    Goes to the next non-zero entry to the LEFT (smaller column) in SAME ROW
3. right:   Goes to the next non-zero entry to the RIGHT (larger column) in SAME ROW  
4. up:      Goes to the next non-zero entry ABOVE (smaller row) in SAME COLUMN
5. down:    Goes to the next non-zero entry BELOW (larger row) in SAME COLUMN

EXAMPLE MATRIX (5x5):
[ 0  5  0  0  3 ]
[ 0  0  7  0  0 ]
[ 2  0  0  0  0 ]
[ 0  0  0  4  0 ]
[ 0  1  0  0  0 ]

Non-zero entries:
- 5 at (1,2)
- 3 at (1,5)  
- 7 at (2,3)
- 2 at (3,1)
- 4 at (4,4)
- 1 at (5,2)

Let's see how the pointers work...
==============================================================================
*/

typedef struct entry
{
    int val;                     // non-zero value
    int row, col;                // position in matrix
    struct entry *left, *right;  // same row navigation
    struct entry *up, *down;     // same column navigation
    struct entry *next;          // list traversal (all entries)
    void *info;
} ENTRY;

typedef struct root
{
    ENTRY *head;                 // first non-zero entry
    long num;                    // total non-zero entries
    void *info;
} ROOT;

// Create a demonstration showing how each pointer works
void demonstrate_pointer_movement()
{
    printf("=== SPARSE MATRIX POINTER DEMONSTRATION ===\n\n");
    
    printf("EXAMPLE MATRIX (5x5):\n");
    printf("[ 0  5  0  0  3 ]\n");
    printf("[ 0  0  7  0  0 ]\n");
    printf("[ 2  0  0  0  0 ]\n");
    printf("[ 0  0  0  4  0 ]\n");
    printf("[ 0  1  0  0  0 ]\n\n");
    
    printf("Non-zero entries:\n");
    printf("- 5 at (1,2)\n");
    printf("- 3 at (1,5)\n");
    printf("- 7 at (2,3)\n");
    printf("- 2 at (3,1)\n");
    printf("- 4 at (4,4)\n");
    printf("- 1 at (5,2)\n\n");
    
    printf("=== POINTER MOVEMENT EXPLANATIONS ===\n\n");
    
    printf("1. ENTRY->next:\n");
    printf("   - Moves to the NEXT non-zero entry in the overall list\n");
    printf("   - Usually follows insertion order or some traversal order\n");
    printf("   - Example: 5(1,2) -> 3(1,5) -> 7(2,3) -> 2(3,1) -> 4(4,4) -> 1(5,2) -> NULL\n");
    printf("   - Purpose: Access ALL non-zero entries\n\n");
    
    printf("2. ENTRY->left:\n");
    printf("   - Moves to the next non-zero entry to the LEFT in the SAME ROW\n");
    printf("   - Smaller column number\n");
    printf("   - Example: From 3(1,5), left goes to 5(1,2)\n");
    printf("   - From 5(1,2), left is NULL (nothing to the left)\n");
    printf("   - Purpose: Navigate horizontally within a row\n\n");
    
    printf("3. ENTRY->right:\n");
    printf("   - Moves to the next non-zero entry to the RIGHT in the SAME ROW\n");
    printf("   - Larger column number\n");
    printf("   - Example: From 5(1,2), right goes to 3(1,5)\n");
    printf("   - From 3(1,5), right is NULL (nothing to the right)\n");
    printf("   - Purpose: Navigate horizontally within a row\n\n");
    
    printf("4. ENTRY->up:\n");
    printf("   - Moves to the next non-zero entry ABOVE in the SAME COLUMN\n");
    printf("   - Smaller row number\n");
    printf("   - Example: From 1(5,2), up goes to 5(1,2)\n");
    printf("   - From 5(1,2), up is NULL (nothing above)\n");
    printf("   - Purpose: Navigate vertically within a column\n\n");
    
    printf("5. ENTRY->down:\n");
    printf("   - Moves to the next non-zero entry BELOW in the SAME COLUMN\n");
    printf("   - Larger row number\n");
    printf("   - Example: From 5(1,2), down goes to 1(5,2)\n");
    printf("   - From 1(5,2), down is NULL (nothing below)\n");
    printf("   - Purpose: Navigate vertically within a column\n\n");
    
    printf("=== KEY DIFFERENCES ===\n\n");
    
    printf("NEXT vs LEFT/RIGHT/UP/DOWN:\n");
    printf("- next:    Traverses ALL non-zero entries (global traversal)\n");
    printf("- left/right: Stay in the SAME ROW, move horizontally\n");
    printf("- up/down:   Stay in the SAME COLUMN, move vertically\n\n");
    
    printf("=== PRACTICAL USES ===\n\n");
    
    printf("When to use each pointer:\n");
    printf("- next:    When you need to process ALL entries (e.g., search, print)\n");
    printf("- left/right: When working within a specific row (e.g., row operations)\n");
    printf("- up/down:   When working within a specific column (e.g., column operations)\n\n");
    
    printf("=== VISUAL EXAMPLE ===\n\n");
    
    printf("For entry 5 at (1,2):\n");
    printf("- next:    -> 3(1,5) [next entry in list]\n");
    printf("- left:    -> NULL [nothing to left in row 1]\n");
    printf("- right:   -> 3(1,5) [next non-zero to right in row 1]\n");
    printf("- up:      -> NULL [nothing above in column 2]\n");
    printf("- down:    -> 1(5,2) [next non-zero below in column 2]\n\n");
    
    printf("For entry 7 at (2,3):\n");
    printf("- next:    -> 2(3,1) [next entry in list]\n");
    printf("- left:    -> NULL [nothing to left in row 2]\n");
    printf("- right:   -> NULL [nothing to right in row 2]\n");
    printf("- up:      -> NULL [nothing above in column 3]\n");
    printf("- down:    -> NULL [nothing below in column 3]\n\n");
}

int main()
{
    demonstrate_pointer_movement();
    return 0;
}
