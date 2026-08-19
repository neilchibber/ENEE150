#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"

// Create a new entry node
ENTRY * make_node (int r, int c, int v)
{ ENTRY *temp;
  // Check for valid input
  if (r<0 || c<0 || v==0)
    return NULL;
  
  // Allocate memory for the new node
  temp = NEW(ENTRY);
  if (temp != NULL)
  { 
    // Initialize node values
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

// Create a new root node for the matrix
ROOT * make_root (void)
{ ROOT  *temp;
  // Allocate memory for the root
  temp = NEW(ROOT);
  if (temp != NULL)
  { 
    // Initialize root properties
    temp->head = NULL;
    temp->num = 0;
    temp->info = NULL;
  }
  return temp;
}

// Insert a new entry at the end of the matrix list
void insert_at_tail (ROOT *M, ENTRY *e)
{ ENTRY *tmp;

  if (M == NULL || e == NULL) return;
  
  // If list is empty, make this the first node
  if (M->head == NULL)
  { M->head = e;
    M->num = 1;
    return;
  }

  // Find the last node
  tmp = M->head;
  while (tmp->next != NULL)
    tmp = tmp->next;
    
  // Attach the new node
  tmp->next = e;
  e->next = NULL;
  M->num++;
}

// Print the matrix to the console and a file
void show_list (ROOT *M, FILE *F)
{ ENTRY *temp;
  int i=0; // Counter to track items per line

  if (M != NULL)
  {
    printf("matrix at %p ...\n", (void*)M);
    fprintf(F, "matrix at %p ...\n", (void*)M);
    
    temp = M->head;
    // Loop through all entries
    while (temp != NULL)
    { 
      // Print the value and its coordinates
      fprintf(F, "%5d (%d,%d)", temp->val, temp->row, temp->col);
      printf("%5d (%d,%d)", temp->val, temp->row, temp->col);
      temp = temp->next;
      i++;
      
      // Print a newline after 5 entries
      if (i == 5)
      { 
        fprintf(F, "\n");
        printf("\n");
        i = 0;
      }
    }
  }
  
  // Print final newline if needed
  if (i!=0)
  { fprintf(F, "\n");
    printf("\n");
  }
}

// Read matrix data from a file
void read_input(FILE *F, ROOT *M, FILE *G)
{ ENTRY *tmp;
  int r, c, v;

  // Create root if it doesn't exist
  if (M == NULL)
  { M = make_root();
    if (M == NULL)
    { printf("No space left. Fail to store data.\n");
      exit(0);
    }
  }

  printf("Reading entry from %p ... \n", (void*)F);
  fprintf(G, "Reading entry from %p ... \n", (void*)F);
  
  // Read row, col, and value until the end of the file
  while(fscanf(F, "%d %d %d", &r, &c, &v) != EOF)
  { tmp = make_node(r, c, v);
    if (tmp != NULL)
      insert_at_tail (M, tmp); // Add to matrix
  }
  
  printf("%ld entries stored in matrix at %p.\n", M->num, (void*)M);
  fprintf(G, "%ld entries stored in matrix at %p.\n", M->num, (void*)M);
}

// Search for a specific value in the matrix
void search (ROOT *M, int k, FILE *F)
{ ENTRY *curr;

  printf("search %d in matrix at %p\n", k, (void*)M);
  fprintf(F, "search %d in matrix at %p\n", k, (void*)M);

  if (M == NULL || M->head == NULL) return;

  curr = M->head;
  // Look through all nodes
  while (curr != NULL)
  { 
    // If value matches, print its position
    if (curr->val == k)
    { fprintf(F, "%d %d\n", curr->row, curr->col);
       printf("%d %d\n", curr->row, curr->col);
    }
    curr = curr->next;
  }
}

// Find the maximum value in the matrix
void find_max (ROOT *M, FILE *F)
{ ENTRY *curr, *max_e;

  printf("find max in matrix at %p\n", (void*)M);
  fprintf(F, "find max in matrix at %p\n", (void*)M);

  if (M == NULL || M->head == NULL) return;

  max_e = M->head;
  curr = M->head->next;
  
  // Compare each node to the current max
  while (curr != NULL)
  { 
    if (curr->val > max_e->val)
      max_e = curr;
    curr = curr->next;
  }
  
  // Print the max value found
  printf("maximum %d at position (%d,%d)\n", max_e->val, max_e->row, max_e->col);
  fprintf(F, "maximum %d at position (%d,%d)\n", max_e->val, max_e->row, max_e->col);
}

// Add two sparse matrices together
ROOT * addition (ROOT *M1, ROOT *M2, FILE *F)
{ ROOT *sum_root;
  ENTRY *curr, *srch, *prev, *new_e;
  int found;

  sum_root = make_root();
  if (sum_root == NULL) return NULL;

  // Copy the first matrix into the sum matrix
  if (M1 != NULL)
  { curr = M1->head;
    while (curr != NULL)
    { insert_at_tail(sum_root, make_node(curr->row, curr->col, curr->val));
      curr = curr->next;
    }
  }

  // Add the second matrix values
  if (M2 != NULL)
  { curr = M2->head;
    while (curr != NULL)
    { found = 0;
      srch = sum_root->head;
      prev = NULL;
      
      // Look for a matching position in the sum matrix
      while (srch != NULL)
      { 
        if (srch->row == curr->row && srch->col == curr->col)
        { 
          // Add the values together
          srch->val += curr->val;
          found = 1;
          
          // Remove the node if the new value is zero
          if (srch->val == 0)
          { if (prev == NULL) sum_root->head = srch->next;
            else prev->next = srch->next;
            free(srch);
            sum_root->num--;
          }
          break;
        }
        prev = srch;
        srch = srch->next;
      }
      
      // If no matching position, create a new node
      if (!found)
      { new_e = make_node(curr->row, curr->col, curr->val);
        if (new_e != NULL) insert_at_tail(sum_root, new_e);
      }
      curr = curr->next;
    }
  }

  printf("matrix at %p has %ld non-zero entries\n", (void*)sum_root, sum_root->num);
  fprintf(F, "matrix at %p has %ld non-zero entries\n", (void*)sum_root, sum_root->num);

  return sum_root;
}

// Transpose the matrix (swap rows and columns)
ROOT * transpose (ROOT *M, FILE *F)
{
  ROOT *t_root = make_root();
  ENTRY *curr;
  
  if (F) {
      fprintf(F, "transpose of matrix at %p\n", (void*)M);
      printf("transpose of matrix at %p\n", (void*)M);
  }

  if (M == NULL || t_root == NULL) return t_root;

  curr = M->head;
  while (curr != NULL) {
    // Create new node with swapped row and col
    ENTRY *new_e = make_node(curr->col, curr->row, curr->val); 
    if (new_e != NULL) {
        insert_at_tail(t_root, new_e);
    }
    curr = curr->next;
  }
  return t_root;
}

// Multiply two sparse matrices
ROOT * multiplication (ROOT *M1, ROOT *M2, FILE *F)
{
  ROOT *prod_root = make_root();
  ENTRY *e1, *e2, *srch, *prev, *new_e;
  int prod_val, found;
  
  if (F) {
      fprintf(F, "multiplication of matrices %p and %p\n", (void*)M1, (void*)M2);
      printf("multiplication of matrices %p and %p\n", (void*)M1, (void*)M2);
  }

  if (M1 == NULL || M2 == NULL || prod_root == NULL) return prod_root;

  e1 = M1->head;
  while (e1 != NULL) {
    e2 = M2->head;
    while (e2 != NULL) {
      
      // Check if columns of M1 match rows of M2
      if (e1->col == e2->row) {
        prod_val = e1->val * e2->val;
        
        if (prod_val != 0) {
            found = 0;
            srch = prod_root->head;
            prev = NULL;
            
            // Look for existing entry at the target location
            while (srch != NULL) {
              if (srch->row == e1->row && srch->col == e2->col) {
                // Add to existing value
                srch->val += prod_val;
                found = 1;
                
                // Remove node if it sums to zero
                if (srch->val == 0) {
                  if (prev == NULL) prod_root->head = srch->next;
                  else prev->next = srch->next;
                  free(srch);
                  prod_root->num--;
                }
                break;
              }
              prev = srch;
              srch = srch->next;
            }
            
            // Insert new node if location was empty
            if (!found) {
              new_e = make_node(e1->row, e2->col, prod_val);
              if (new_e != NULL) insert_at_tail(prod_root, new_e);
            }
        }
      }
      e2 = e2->next;
    }
    e1 = e1->next;
  }
  return prod_root;
}

// Helper to sort entries by row, then column
int compare_entries(const void *a, const void *b) {
    ENTRY *ea = *(ENTRY **)a;
    ENTRY *eb = *(ENTRY **)b;
    // Compare rows first
    if (ea->row != eb->row) {
        return ea->row - eb->row;
    }
    // If rows match, compare columns
    return ea->col - eb->col;
}

// Reverse the values in the matrix while keeping positions
ROOT * reverse (ROOT *M, FILE *F)
{
  ROOT *r_root = make_root();
  ENTRY *curr;
  ENTRY **arr;
  int i, left, right, temp;

  if (F) {
      fprintf(F, "reverse of matrix at %p\n", (void*)M);
      printf("reverse of matrix at %p\n", (void*)M);
  }

  if (M == NULL || r_root == NULL || M->num == 0) return r_root;

  // Copy matrix layout
  curr = M->head;
  while (curr != NULL) {
    insert_at_tail(r_root, make_node(curr->row, curr->col, curr->val));
    curr = curr->next;
  }

  // Allocate array for sorting pointers
  arr = malloc(r_root->num * sizeof(ENTRY *));
  if (arr == NULL) return r_root;

  // Fill the array
  curr = r_root->head;
  i = 0;
  while (curr != NULL) {
    arr[i++] = curr;
    curr = curr->next;
  }

  // Sort array in row-major order
  qsort(arr, r_root->num, sizeof(ENTRY *), compare_entries);

  // Swap values starting from the outside going in
  left = 0;
  right = r_root->num - 1;
  while (left < right) {
    temp = arr[left]->val;
    arr[left]->val = arr[right]->val;
    arr[right]->val = temp;
    left++;
    right--;
  }

  free(arr);
  return r_root;
}

// Recursive helper for depth-first search pathfinding
int path_dfs(ENTRY *curr, ENTRY *target, ENTRY **all_nodes, int num_nodes,
             ENTRY **visited, int v_count, ENTRY **path, int path_len, FILE *F) 
{
    int i, j, is_visited;
    ENTRY *neighbor;

    // Record the current node
    visited[v_count++] = curr;
    path[path_len++] = curr;

    // Check if we reached the end
    if (curr == target) {
        // Print the path
        for (i = 0; i < path_len; i++) {
            fprintf(F, "(%d,%d) ", path[i]->row, path[i]->col);
            printf("(%d,%d) ", path[i]->row, path[i]->col);
        }
        fprintf(F, "\n");
        printf("\n");
        return 1;
    }

    // Look at all other nodes
    for (i = 0; i < num_nodes; i++) {
        neighbor = all_nodes[i];
        if (neighbor == curr) continue;
        
        // Two nodes are connected if they share a row or column
        if (neighbor->row == curr->row || neighbor->col == curr->col) {
            
            // Check if we've already been here
            is_visited = 0;
            for (j = 0; j < v_count; j++) {
                if (visited[j] == neighbor) { 
                    is_visited = 1; 
                    break; 
                }
            }
            
            // Explore this path if not visited
            if (!is_visited) {
                if (path_dfs(neighbor, target, all_nodes, num_nodes, visited, v_count, path, path_len, F)) {
                    return 1;
                }
            }
        }
    }
    return 0; // Return false if dead end
}

// Find a path between two coordinates
int find_path (ROOT *M, int r1, int c1, int r2, int c2, FILE *F)
{
    ENTRY *start = NULL;
    ENTRY *end = NULL;
    ENTRY *curr;
    ENTRY **all_nodes, **visited, **path;
    int num_entries = 0;
    int result = 0;

    if (F) {
        fprintf(F, "find_path from (%d,%d) to (%d,%d)\n", r1, c1, r2, c2);
        printf("find_path from (%d,%d) to (%d,%d)\n", r1, c1, r2, c2);
    }

    if (M == NULL || M->num == 0) return 0;

    all_nodes = malloc(M->num * sizeof(ENTRY *));
    
    // Find the start and end nodes
    curr = M->head;
    while (curr != NULL) {
        if (curr->row == r1 && curr->col == c1) start = curr;
        if (curr->row == r2 && curr->col == c2) end = curr;
        all_nodes[num_entries++] = curr;
        curr = curr->next;
    }

    // Return if start or end doesn't exist
    if (start == NULL || end == NULL) {
        if (F) {
            fprintf(F, "Start or end entry not found.\n");
            printf("Start or end entry not found.\n");
        }
        free(all_nodes);
        return 0;
    }

    // Allocate memory for tracking arrays
    visited = malloc(M->num * sizeof(ENTRY *));
    path = malloc(M->num * sizeof(ENTRY *));

    // Start the search
    result = path_dfs(start, end, all_nodes, num_entries, visited, 0, path, 0, F);

    if (!result) {
        if (F) {
            fprintf(F, "No path found.\n");
            printf("No path found.\n");
        }
    }

    // Clean up memory
    free(visited);
    free(path);
    free(all_nodes);
    
    return result;
}