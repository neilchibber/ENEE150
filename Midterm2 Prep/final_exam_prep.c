#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
==============================================================================
FINAL EXAM PREP - ENEE150
Based on Finals Announcement Topics

Topics Covered:
1. Graph algorithms and representations
2. Doubly linked lists  
3. Singly linked lists (Homework 5 style)
4. Pointers and dynamic memory
5. Project 2 (sparse matrices)

Focus: Coding problems and code analysis
==============================================================================
*/

// ==================== GRAPH ALGORITHMS ====================

/*
QUESTION 1: Graph Representation Analysis

Consider the following graph:
A -- B -- C
|    |    |
D -- E -- F

Directed edges: A→B, B→C, B→E, C→F, A→D, D→E, E→F

Analyze this code:
typedef struct {
    int vertex;
    struct edge *edges;
} VERTEX;

typedef struct edge {
    int to_vertex;
    int weight;
    struct edge *next;
} EDGE;

PART A: What type of graph representation is this?
PART B: How would you add edge A→D with weight 3?
PART C: What's the time complexity of finding all outgoing edges from vertex B?
PART D: Draw the adjacency matrix representation
*/

/*
YOUR ANSWERS:
PART A: DAG
PART B: 
PART C:
PART D:
*/

/*
QUESTION 2: BFS/DFS Code Analysis

void traverse_graph(VERTEX *graph, int start, int n) {
    int visited[100] = {0};
    int queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        EDGE *e = graph[current].edges;
        while (e != NULL) {
            if (!visited[e->to_vertex]) {
                queue[rear++] = e->to_vertex;
                visited[e->to_vertex] = 1;
            }
            e = e->next;
        }
    }
}

PART A: Is this BFS or DFS? How can you tell?
PART B: What's the purpose of the visited array?
PART C: What happens if you remove the visited check?
PART D: What's the time complexity of this algorithm?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
QUESTION 3: Dijkstra's Algorithm Analysis

Consider this Dijkstra implementation:

int dijkstra(int start, int end, int n) {
    int dist[100];
    int visited[100];
    int prev[100];
    
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = 999999;
        visited[i] = 0;
        prev[i] = -1;
    }
    dist[start] = 0;
    
    // Main loop
    for (int i = 0; i < n; i++) {
        int u = find_min_unvisited(dist, visited, n);
        visited[u] = 1;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && edge_exists(u, v)) {
                int new_dist = dist[u] + edge_weight(u, v);
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    prev[v] = u;
                }
            }
        }
    }
    
    return dist[end];
}

PART A: What's the purpose of the prev array?
PART B: Why is dist initialized to 999999?
PART C: What type of graph does this work for?
PART D: What would happen if there's a negative weight edge?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

// ==================== DOUBLY LINKED LISTS ====================

/*
QUESTION 4: Doubly Linked List Code Analysis

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} NODE;

typedef struct {
    NODE *head;
    NODE *tail;
} DLLIST;

void delete_node(DLLIST *list, NODE *target) {
    if (target == NULL) return;
    
    if (target->prev != NULL) {
        target->prev->next = target->next;
    } else {
        list->head = target->next;
    }
    
    if (target->next != NULL) {
        target->next->prev = target->prev;
    } else {
        list->tail = target->prev;
    }
    
    free(target);
}

PART A: What are the three key cases handled in this delete operation?
PART B: Why do we check target->prev == NULL separately from target->next == NULL?
PART C: What happens if target is the only node in the list?
PART D: What's the time complexity of this delete operation?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
QUESTION 5: Fix the Doubly Linked List Insert

This insert function has bugs. Find and fix them:

void insert_at_head(DLLIST *list, int data) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;
    
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    
    list->head = new_node;
    // BUG: Missing something here!
}

PART A: What's the bug?
PART B: How would you fix it?
PART C: What happens if you don't fix this bug?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
*/

// ==================== SINGLY LINKED LISTS ====================

/*
QUESTION 6: Singly Linked List (Homework 5 Style)

typedef struct node {
    int val;
    int row, col;
    struct node *next;
    void *info;
} NODE;

typedef struct {
    NODE *head;
    long num;
    void *info;
} ROOT;

// Write a function to find the maximum value in the matrix
int find_max(ROOT *matrix) {
    // YOUR CODE HERE
    // Requirements:
    // 1. Handle empty matrix
    // 2. Return the maximum val found
    // 3. Use proper traversal
}

PART A: Write the complete function
PART B: What's the time complexity?
PART C: How would this differ if you had left/right/up/down pointers?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
*/

/*
QUESTION 7: Code Analysis - Sparse Matrix Operations

ROOT *add_matrices(ROOT *A, ROOT *B) {
    ROOT *result = make_root();
    NODE *current_a = A->head;
    
    while (current_a != NULL) {
        NODE *current_b = B->head;
        int found = 0;
        
        while (current_b != NULL) {
            if (current_a->row == current_b->row && 
                current_a->col == current_b->col) {
                // Add values together
                NODE *new_node = make_node(current_a->row, current_a->col, 
                                       current_a->val + current_b->val);
                insert_at_tail(result, new_node);
                found = 1;
                break;
            }
            current_b = current_b->next;
        }
        
        if (!found) {
            // Copy the node from A
            NODE *new_node = make_node(current_a->row, current_a->col, current_a->val);
            insert_at_tail(result, new_node);
        }
        
        current_a = current_a->next;
    }
    
    return result;
}

PART A: What's the time complexity of this addition algorithm?
PART B: Why do we need to check if (!found)?
PART C: What would happen if matrices A and B are the same matrix?
PART D: How could you optimize this for sparse matrices?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

// ==================== POINTERS AND MEMORY ====================

/*
QUESTION 8: Pointer Analysis

Consider this code:
void mystery_function() {
    int x = 5;
    int *p1 = &x;
    int *p2 = NULL;
    int **p3 = &p1;
    int *p4 = (int*)malloc(sizeof(int));
    
    *p4 = 10;
    p2 = p4;
    
    printf("%d %d %d %d\n", *p1, *p2, **p3);
}

PART A: What does each pointer point to?
PART B: What's the difference between p1 and p4?
PART C: What's a memory leak in this code?
PART D: How would you fix the memory leak?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
QUESTION 9: Dynamic Memory Analysis

void create_nodes(int n) {
    NODE *nodes[100];
    
    for (int i = 0; i < n; i++) {
        nodes[i] = (NODE*)malloc(sizeof(NODE));
        nodes[i]->val = i;
        nodes[i]->next = NULL;
    }
    
    // Function ends here
}

PART A: What's wrong with this code?
PART B: What happens to the allocated memory?
PART C: How would you fix this?
PART D: What's the difference between stack and heap allocation here?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

// ==================== PROJECT 2 FOCUS ====================

/*
QUESTION 10: Sparse Matrix Project Analysis

Consider the ENTRY and ROOT structures from Project 2:

typedef struct entry {
    int val;
    int row, col;
    struct entry *left, *right, *up, *down, *next;
    void *info;
} ENTRY;

typedef struct root {
    ENTRY *head;
    long num;
    void *info;
} ROOT;

PART A: Why have both next AND left/right/up/down pointers?
PART B: When would you use next vs left/right?
PART C: What's the memory advantage of this representation?
PART D: How would you implement matrix multiplication using these pointers?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
PART D:
*/

/*
QUESTION 11: Coding Challenge - Sparse Matrix Operation

Write a function to transpose a sparse matrix:

ROOT *transpose(ROOT *matrix) {
    // YOUR CODE HERE
    // Requirements:
    // 1. Create a new ROOT
    // 2. For each entry (r,c,v) in matrix, create entry (c,r,v) in result
    // 3. Return the transposed matrix
    // 4. Handle edge cases properly
}

PART A: Write the complete function
PART B: What's the time complexity?
PART C: How does this compare to dense matrix transpose?
*/

/*
YOUR ANSWERS:
PART A:
PART B:
PART C:
*/

// ==================== COMPREHENSIVE CODING CHALLENGE ====================

/*
QUESTION 12: Final Challenge - Sparse Matrix Path Finding

Using the sparse matrix structures, implement a function to check if there's a path
from (start_row, start_col) to (end_row, end_col) where you can move:
- Right (same row, larger column)
- Down (same column, larger row)

int find_path(ROOT *matrix, int start_row, int start_col, int end_row, int end_col) {
    // YOUR CODE HERE
    // Requirements:
    // 1. Return 1 if path exists, 0 otherwise
    // 2. Use the sparse matrix structure efficiently
    // 3. Handle edge cases
    // 4. Don't modify the original matrix
}

HINT: Think about how you can use the right and down pointers!
*/

/*
YOUR CODE:
*/

// ==================== STUDY TIPS ====================

void study_tips() {
    printf("=== FINAL EXAM STUDY TIPS ===\n\n");
    
    printf("GRAPHS:\n");
    printf("- Know BFS vs DFS differences\n");
    printf("- Understand adjacency list vs matrix trade-offs\n");
    printf("- Practice Dijkstra's algorithm by hand\n");
    printf("- Remember topological sort conditions\n\n");
    
    printf("LINKED LISTS:\n");
    printf("- Master insert/delete operations\n");
    printf("- Understand pointer manipulation\n");
    printf("- Practice edge cases (empty, single node)\n");
    printf("- Know time complexities\n\n");
    
    printf("POINTERS:\n");
    printf("- * vs & operators\n");
    printf("- NULL pointer checks\n");
    printf("- Memory allocation/deallocation\n");
    printf("- Double vs single pointers\n\n");
    
    printf("PROJECT 2:\n");
    printf("- Sparse matrix advantages\n");
    printf("- ENTRY and ROOT structure usage\n");
    printf("- Efficient traversal methods\n");
    printf("- Matrix operations\n\n");
    
    printf("EXAM STRATEGY:\n");
    printf("- Read questions carefully\n");
    printf("- Write clean, commented code\n");
    printf("- Check edge cases\n");
    printf("- Manage time wisely\n");
}

int main() {
    study_tips();
    printf("\nGood luck on your final exam!\n");
    return 0;
}
