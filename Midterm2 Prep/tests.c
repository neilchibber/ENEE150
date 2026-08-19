#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
==============================================================================
SPARSE MATRIX PRACTICE PROBLEMS
==============================================================================

This file contains practice problems to test your understanding of:
1. ENTRY and ROOT structs
2. Sparse matrix operations
3. Pointer manipulation
4. Memory management
5. Algorithm implementation

Each problem has a description and a function stub for you to complete.
==============================================================================
*/

// Include the sparse matrix structures (same as proj2)
typedef struct entry
{
    int val;                     // non-zero integer value
    int row, col;                // entry's position in the matrix
    struct entry *left, *right;  // pointers in the same row
    struct entry *up, *down;     // pointers in the same column
    struct entry *next;          // pointer to next entry in the list
    void *info;                  // additional information
} ENTRY;

typedef struct root
{
    ENTRY *head;                 // first entry in the list
    long num;                    // number of non-zero entries
    void *info;                  // additional information
} ROOT;

// Helper functions (you can use these)
ENTRY * make_node(int r, int c, int v)
{
    if (v == 0) return NULL;
    
    ENTRY *temp = (ENTRY*)malloc(sizeof(ENTRY));
    if (temp != NULL)
    { 
        temp->val = v;
        temp->row = r;
        temp->col = c;
        temp->left = NULL;
        temp->right = NULL;
        temp->up = NULL;
        temp->down = NULL;
        temp->next = NULL;
        temp->info = NULL;
    }
    return temp;
}

ROOT * make_root(void)
{
    ROOT *temp = (ROOT*)malloc(sizeof(ROOT));
    if (temp != NULL)
    { 
        temp->head = NULL;
        temp->num = 0;
        temp->info = NULL;
    }
    return temp;
}

void insert_at_tail(ROOT *M, ENTRY *e)
{
    ENTRY *tmp;
    if (M == NULL || e == NULL) return;
    
    if (M->head == NULL)
    { 
        M->head = e;
        M->num = 1;
        return;
    }

    tmp = M->head;
    while (tmp->next != NULL)
        tmp = tmp->next;
        
    tmp->next = e;
    e->next = NULL;
    M->num++;
}

void print_matrix(ROOT *M)
{
    printf("Matrix with %ld non-zero entries:\n", M->num);
    ENTRY *curr = M->head;
    while (curr != NULL)
    {
        printf("%d at (%d,%d) ", curr->val, curr->row, curr->col);
        curr = curr->next;
    }
    printf("\n\n");
}

/*
==============================================================================
PRACTICE PROBLEMS
==============================================================================*/

// PROBLEM 1: Count entries in a specific row
// Write a function that counts how many non-zero entries are in a given row
int count_in_row(ROOT *M, int row)
{
    ENTRY* current = M->head;
    int count = 0;
    while (current->row == row){
        count++;
    }
    current = current->next;
    return count;  // Replace with your implementation
}

// PROBLEM 2: Count entries in a specific column  
// Write a function that counts how many non-zero entries are in a given column
int count_in_col(ROOT *M, int col)
{
    ENTRY* curr = M->head;
    int count = 0;
    while (curr != NULL){
        if (curr->col == col){
            count++;
        }
        curr = curr->next;
    }

    // Hint: Traverse the list and count entries where entry->col == col
    return count;  // Replace with your implementation
}

// PROBLEM 3: Find the maximum value in a specific row
// Return the maximum value in the given row, or 0 if no entries in that row
int max_in_row(ROOT *M, int row)
{
    int max = 0;
    ENTRY* curr = M->head;
    ENTRY* next = M->head->next;
    while(curr != NULL){
        if(curr->val > next->val){
            max = curr->val;
        }
        curr = next;
        next = curr->next;
    }
    // Hint: Track the maximum value while traversing entries in the given row
    return max;  // Replace with your implementation
}

// PROBLEM 4: Find the minimum value in a specific column
// Return the minimum value in the given column, or 0 if no entries in that column
int min_in_col(ROOT *M, int col)
{
    int min = M->head->val;
    ENTRY* curr = M->head;
    ENTRY* next = M->head->next;

    while (curr != NULL){
        if(curr->col == col){
            if(curr->val < next->val){
                min = curr->val;
            }
        }
        curr = next;
        next = curr->next;
    }
    // Hint: Track the minimum value while traversing entries in the given column
    return min;  // Replace with your implementation
}

// PROBLEM 5: Check if a position is non-zero
// Return 1 if there's a non-zero entry at (row, col), 0 otherwise
int is_nonzero_at(ROOT *M, int row, int col)
{
    // YOUR CODE HERE
    // Hint: Search the list for an entry with matching row and col
    return 0;  // Replace with your implementation
}

// PROBLEM 6: Get value at a specific position
// Return the value at (row, col), or 0 if position is zero or doesn't exist
int get_value_at(ROOT *M, int row, int col)
{
    // YOUR CODE HERE
    // Hint: Similar to is_nonzero_at, but return the actual value
    return 0;  // Replace with your implementation
}

// PROBLEM 7: Count total non-zero entries in the matrix
// Return the total number of non-zero entries
// (This should be easy - think about what's stored in ROOT!)
int count_total_entries(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: Look at the ROOT structure - is this information already stored?
    return 0;  // Replace with your implementation
}

// PROBLEM 8: Find the entry with maximum value in the entire matrix
// Return a pointer to the entry with the maximum value, or NULL if matrix is empty
ENTRY * find_max_entry(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: Traverse the list and keep track of the entry with max value
    return NULL;  // Replace with your implementation
}

// PROBLEM 9: Calculate the sum of all values in the matrix
// Return the sum of all non-zero entries
int sum_all_values(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: Traverse the list and accumulate the sum of val fields
    return 0;  // Replace with your implementation
}

// PROBLEM 10: Calculate the average of all non-zero values
// Return the average as a float, or 0.0 if matrix is empty
float average_value(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: Use sum_all_values() and count_total_entries()
    return 0.0f;  // Replace with your implementation
}

// PROBLEM 11: Find all entries with a specific value
// Return a new ROOT containing only entries with the given value
ROOT * find_entries_with_value(ROOT *M, int value)
{
    // YOUR CODE HERE
    // Hint: Create a new ROOT and copy entries that match the value
    return NULL;  // Replace with your implementation
}

// PROBLEM 12: Delete all entries with a specific value
// Remove and free all entries that have the given value
void delete_entries_with_value(ROOT *M, int value)
{
    // YOUR CODE HERE
    // Hint: Be careful with pointer manipulation when removing nodes!
}

// PROBLEM 13: Create a copy of the matrix
// Return a new ROOT that is an exact copy of the input matrix
ROOT * copy_matrix(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: Create new nodes for each entry and link them properly
    return NULL;  // Replace with your implementation
}

// PROBLEM 14: Check if two matrices are equal
// Return 1 if matrices have the same non-zero entries in the same positions, 0 otherwise
int matrices_equal(ROOT *M1, ROOT *M2)
{
    // YOUR CODE HERE
    // Hint: Compare number of entries, then check each entry
    return 0;  // Replace with your implementation
}

// PROBLEM 15: Transpose a matrix (swap rows and columns)
// Return a new ROOT where each entry (r,c,v) becomes (c,r,v)
ROOT * transpose_matrix(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: Create new entries with swapped row and col
    return NULL;  // Replace with your implementation
}

// PROBLEM 16: Add a value to a specific position
// If position exists, add to it. If position is zero, create new entry.
// If result becomes zero, remove the entry.
void add_to_position(ROOT *M, int row, int col, int value)
{
    // YOUR CODE HERE
    // Hint: This is complex - handle all three cases!
}

// PROBLEM 17: Multiply all values by a scalar
// Multiply every non-zero entry by the given scalar
void multiply_by_scalar(ROOT *M, int scalar)
{
    // YOUR CODE HERE
    // Hint: Simple traversal, but handle zero results!
}

// PROBLEM 18: Find entries in a specific row range
// Return a new ROOT containing entries where row is between start_row and end_row (inclusive)
ROOT * find_entries_in_row_range(ROOT *M, int start_row, int end_row)
{
    // YOUR CODE HERE
    // Hint: Filter entries based on row range
    return NULL;  // Replace with your implementation
}

// PROBLEM 19: Find entries in a specific column range
// Return a new ROOT containing entries where col is between start_col and end_col (inclusive)
ROOT * find_entries_in_col_range(ROOT *M, int start_col, int end_col)
{
    // YOUR CODE HERE
    // Hint: Filter entries based on column range
    return NULL;  // Replace with your implementation
}

// PROBLEM 20: Calculate matrix density
// Return the percentage of non-zero entries (as a float between 0.0 and 1.0)
// Assume the matrix dimensions are stored in ROOT->info as an int[2] = {rows, cols}
float calculate_density(ROOT *M)
{
    // YOUR CODE HERE
    // Hint: density = non_zero_entries / (total_rows * total_cols)
    return 0.0f;  // Replace with your implementation
}

/*
==============================================================================
TEST FUNCTIONS
==============================================================================*/

// Function to create a test matrix for practice
ROOT * create_test_matrix()
{
    ROOT *M = make_root();
    
    // Create a test matrix:
    // [ 5  0  3  0 ]
    // [ 0  7  0  2 ]
    // [ 1  0  0  4 ]
    // [ 0  0  6  0 ]
    
    insert_at_tail(M, make_node(1, 1, 5));
    insert_at_tail(M, make_node(1, 3, 3));
    insert_at_tail(M, make_node(2, 2, 7));
    insert_at_tail(M, make_node(2, 4, 2));
    insert_at_tail(M, make_node(3, 1, 1));
    insert_at_tail(M, make_node(3, 4, 4));
    insert_at_tail(M, make_node(4, 3, 6));
    
    return M;
}

// Test function to check your implementations
void run_tests()
{
    printf("=== RUNNING PRACTICE PROBLEM TESTS ===\n\n");
    
    ROOT *M = create_test_matrix();
    printf("Test matrix created:\n");
    print_matrix(M);
    
    printf("=== TESTING YOUR SOLUTIONS ===\n\n");
    
    // Test Problem 1
    printf("Problem 1 - Count entries in row 1: %d (Expected: 2)\n", count_in_row(M, 1));
    printf("Problem 1 - Count entries in row 2: %d (Expected: 2)\n", count_in_row(M, 2));
    printf("Problem 1 - Count entries in row 5: %d (Expected: 0)\n", count_in_row(M, 5));
    
    // Test Problem 2
    printf("Problem 2 - Count entries in col 1: %d (Expected: 2)\n", count_in_col(M, 1));
    printf("Problem 2 - Count entries in col 3: %d (Expected: 2)\n", count_in_col(M, 3));
    printf("Problem 2 - Count entries in col 2: %d (Expected: 1)\n", count_in_col(M, 2));
    
    // Test Problem 3
    printf("Problem 3 - Max in row 1: %d (Expected: 5)\n", max_in_row(M, 1));
    printf("Problem 3 - Max in row 2: %d (Expected: 7)\n", max_in_row(M, 2));
    
    // Test Problem 4
    printf("Problem 4 - Min in col 3: %d (Expected: 3)\n", min_in_col(M, 3));
    printf("Problem 4 - Min in col 4: %d (Expected: 2)\n", min_in_col(M, 4));
    
    // Test Problem 5
    printf("Problem 5 - Is (1,1) non-zero: %d (Expected: 1)\n", is_nonzero_at(M, 1, 1));
    printf("Problem 5 - Is (1,2) non-zero: %d (Expected: 0)\n", is_nonzero_at(M, 1, 2));
    
    // Test Problem 6
    printf("Problem 6 - Value at (2,2): %d (Expected: 7)\n", get_value_at(M, 2, 2));
    printf("Problem 6 - Value at (3,3): %d (Expected: 0)\n", get_value_at(M, 3, 3));
    
    // Test Problem 7
    printf("Problem 7 - Total entries: %d (Expected: 7)\n", count_total_entries(M));
    
    // Test Problem 8
    ENTRY *max_entry = find_max_entry(M);
    if (max_entry)
        printf("Problem 8 - Max entry: %d at (%d,%d) (Expected: 7 at (2,2))\n", 
               max_entry->val, max_entry->row, max_entry->col);
    
    // Test Problem 9
    printf("Problem 9 - Sum of all values: %d (Expected: 28)\n", sum_all_values(M));
    
    // Test Problem 10
    printf("Problem 10 - Average value: %.2f (Expected: 4.00)\n", average_value(M));
    
    printf("\n=== HINTS FOR HARDER PROBLEMS ===\n");
    printf("Problems 11-20 are more challenging and involve:\n");
    printf("- Creating new matrices\n");
    printf("- Memory management\n");
    printf("- Complex pointer manipulation\n");
    printf("- Algorithm design\n");
    printf("\nStart with Problems 1-10, then work on the harder ones!\n");
}

int main()
{
    run_tests();
    return 0;
}