#include <stdio.h>
#include <stdlib.h>

// Define the structures based on the sparse matrix project
typedef struct entry
{
    int val;                     // value of the entry
    int row, col;                // entry's position in the matrix  
    struct entry *left, *right;  // pointers to left/right entries
    struct entry *up, *down;     // pointers to up/down entries
    struct entry *next;          // pointer to next entry in the list
    void *info;                  // additional information pointer
} ENTRY;

typedef struct root               // root to a list of entries
{
    ENTRY *head;                 // first entry in the list
    long num;                    // number of entries in the list
    void *info;                  // additional information pointer
} ROOT;

// Function to create a new entry node
ENTRY * make_node(int r, int c, int v)
{
    ENTRY *temp;
    if (r < 0 || c < 0 || v == 0)
        return NULL;
    
    temp = (ENTRY*)malloc(sizeof(ENTRY));
    if (temp != NULL)
    { 
        temp->val = v;
        temp->row = r;
        temp->col = c;
        temp->left = NULL;
        temp->right = NULL;
        temp->up = NULL;
        temp->down = NULL;
        temp->info = NULL;
        temp->next = NULL;
    }
    return temp;
}

// Function to create a new root
ROOT * make_root(void)
{
    ROOT *temp;
    temp = (ROOT*)malloc(sizeof(ROOT));
    if (temp != NULL)
    { 
        temp->head = NULL;
        temp->num = 0;
        temp->info = NULL;
    }
    return temp;
}

// Function to insert a node at the end of the list
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

// Function to print the list
void print_list(ROOT *M)
{
    ENTRY *temp;
    int i = 0;

    if (M == NULL || M->head == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("List with %ld entries:\n", M->num);
    temp = M->head;
    while (temp != NULL)
    { 
        printf("%d (%d,%d)", temp->val, temp->row, temp->col);
        temp = temp->next;
        i++;
        
        if (i == 5)
        { 
            printf("\n");
            i = 0;
        }
        else
        {
            printf("    ");
        }
    }
    if (i != 0)
        printf("\n");
}

// Function to swap the first and last nodes in a linked list
void swap_first_last(ROOT *M)
{
    ENTRY *first, *last, *second_last, *temp;
    
    // Handle edge cases
    if (M == NULL || M->head == NULL || M->num <= 1)
        return;
    
    // If there are only 2 nodes, just swap them
    if (M->num == 2)
    {
        first = M->head;
        last = first->next;
        
        // Swap the nodes
        last->next = first;
        first->next = NULL;
        M->head = last;
        return;
    }
    
    // For 3 or more nodes
    first = M->head;
    last = M->head;
    second_last = NULL;
    
    // Find the last and second-to-last nodes
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    
    // Swap first and last nodes
    temp = first->next;  // Store the second node
    
    // Make last the new head
    M->head = last;
    last->next = temp;
    
    // Make first the new last
    second_last->next = first;
    first->next = NULL;
}

// Test function
int main()
{
    ROOT *list;
    ENTRY *node;
    int i;
    
    // Create a new list
    list = make_root();
    
    // Add some test nodes
    printf("Original list:\n");
    for (i = 1; i <= 5; i++)
    {
        node = make_node(i, i, i * 10);
        insert_at_tail(list, node);
    }
    print_list(list);
    
    // Swap first and last
    printf("\nAfter swapping first and last:\n");
    swap_first_last(list);
    print_list(list);
    
    // Test with 2 nodes
    printf("\n\nTesting with 2 nodes:\n");
    ROOT *list2 = make_root();
    insert_at_tail(list2, make_node(1, 1, 10));
    insert_at_tail(list2, make_node(2, 2, 20));
    
    printf("Original list:\n");
    print_list(list2);
    
    printf("\nAfter swapping first and last:\n");
    swap_first_last(list2);
    print_list(list2);
    
    // Test with 1 node
    printf("\n\nTesting with 1 node:\n");
    ROOT *list3 = make_root();
    insert_at_tail(list3, make_node(1, 1, 10));
    
    printf("Original list:\n");
    print_list(list3);
    
    printf("\nAfter swapping first and last:\n");
    swap_first_last(list3);
    print_list(list3);
    
    return 0;
}
