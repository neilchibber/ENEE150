#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
==============================================================================
HOW DOES THE `void *info` POINTER WORK?
==============================================================================

The `void *info` pointer is a "generic pointer" that can point to ANY type of data.
It's like a universal storage slot for extra information.

KEY CONCEPTS:
1. void* can point to any data type (int, float, struct, array, etc.)
2. You must cast it back to the correct type when using it
3. It's commonly used for storing additional metadata or custom data

COMMON USES:
- Store extra matrix information
- Add custom metadata to nodes
- Keep track of algorithm-specific data
- Store strings, arrays, or other complex data
==============================================================================
*/

typedef struct entry
{
    int val;
    int row, col;
    struct entry *next;
    void *info;  // The mysterious info pointer!
} ENTRY;

typedef struct root
{
    ENTRY *head;
    long num;
    void *info;  // ROOT also has an info pointer
} ROOT;

// Example 1: Store a simple string in info
void demo_string_info()
{
    printf("=== DEMO 1: Storing String in info ===\n");
    
    ENTRY *node = (ENTRY*)malloc(sizeof(ENTRY));
    node->val = 42;
    node->row = 1;
    node->col = 1;
    node->next = NULL;
    
    // Store a string in the info pointer
    char *description = "This is important data";
    node->info = description;  // Store string pointer
    
    printf("Node value: %d\n", node->val);
    printf("Info contains: %s\n", (char*)node->info);  // Cast back to char*
    
    free(node);
}

// Example 2: Store an integer in info
void demo_integer_info()
{
    printf("\n=== DEMO 2: Storing Integer in info ===\n");
    
    ENTRY *node = (ENTRY*)malloc(sizeof(ENTRY));
    node->val = 100;
    node->row = 2;
    node->col = 2;
    node->next = NULL;
    
    // Store an integer in info (need to allocate memory for it)
    int *priority = (int*)malloc(sizeof(int));
    *priority = 5;  // Priority level 5
    node->info = priority;
    
    printf("Node value: %d\n", node->val);
    printf("Priority: %d\n", *((int*)node->info));  // Cast to int* and dereference
    
    free(node->info);  // Don't forget to free the allocated memory!
    free(node);
}

// Example 3: Store a custom structure in info
typedef struct {
    char creator[50];
    time_t created;
    int access_count;
} NodeMetadata;

void demo_struct_info()
{
    printf("\n=== DEMO 3: Storing Custom Struct in info ===\n");
    
    ENTRY *node = (ENTRY*)malloc(sizeof(ENTRY));
    node->val = 999;
    node->row = 3;
    node->col = 3;
    node->next = NULL;
    
    // Create and store custom metadata
    NodeMetadata *metadata = (NodeMetadata*)malloc(sizeof(NodeMetadata));
    strcpy(metadata->creator, "Student");
    metadata->created = time(NULL);
    metadata->access_count = 0;
    node->info = metadata;
    
    printf("Node value: %d\n", node->val);
    
    // Access the metadata
    NodeMetadata *meta = (NodeMetadata*)node->info;
    printf("Creator: %s\n", meta->creator);
    printf("Access count: %d\n", meta->access_count);
    
    free(node->info);
    free(node);
}

// Example 4: Store an array in info
void demo_array_info()
{
    printf("\n=== DEMO 4: Storing Array in info ===\n");
    
    ENTRY *node = (ENTRY*)malloc(sizeof(ENTRY));
    node->val = 777;
    node->row = 4;
    node->col = 4;
    node->next = NULL;
    
    // Store an array of related values
    int *related_values = (int*)malloc(3 * sizeof(int));
    related_values[0] = 10;
    related_values[1] = 20;
    related_values[2] = 30;
    node->info = related_values;
    
    printf("Node value: %d\n", node->val);
    printf("Related values: ");
    int *values = (int*)node->info;
    for (int i = 0; i < 3; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    
    free(node->info);
    free(node);
}

// Example 5: Matrix-wide information using ROOT->info
typedef struct {
    char matrix_name[100];
    int total_rows;
    int total_cols;
    double sparsity_ratio;  // percentage of zeros
} MatrixInfo;

void demo_root_info()
{
    printf("\n=== DEMO 5: Matrix-wide Info using ROOT->info ===\n");
    
    ROOT *matrix = (ROOT*)malloc(sizeof(ROOT));
    matrix->head = NULL;
    matrix->num = 0;
    
    // Store matrix-wide metadata in ROOT->info
    MatrixInfo *matrix_info = (MatrixInfo*)malloc(sizeof(MatrixInfo));
    strcpy(matrix_info->matrix_name, "Test Matrix");
    matrix_info->total_rows = 5;
    matrix_info->total_cols = 5;
    matrix_info->sparsity_ratio = 0.8;  // 80% zeros
    matrix->info = matrix_info;
    
    // Access matrix info
    MatrixInfo *info = (MatrixInfo*)matrix->info;
    printf("Matrix name: %s\n", info->matrix_name);
    printf("Dimensions: %dx%d\n", info->total_rows, info->total_cols);
    printf("Sparsity: %.1f%% zeros\n", info->sparsity_ratio * 100);
    
    free(matrix->info);
    free(matrix);
}

// Example 6: Algorithm-specific data
typedef struct {
    int visited;
    int distance;
    ENTRY *parent;
} BFSData;

void demo_algorithm_info()
{
    printf("\n=== DEMO 6: Algorithm-specific Data ===\n");
    
    ENTRY *node = (ENTRY*)malloc(sizeof(ENTRY));
    node->val = 123;
    node->row = 1;
    node->col = 1;
    node->next = NULL;
    
    // Store BFS algorithm data
    BFSData *bfs_data = (BFSData*)malloc(sizeof(BFSData));
    bfs_data->visited = 0;
    bfs_data->distance = -1;  // Infinity
    bfs_data->parent = NULL;
    node->info = bfs_data;
    
    printf("Node value: %d\n", node->val);
    
    // Simulate algorithm processing
    BFSData *data = (BFSData*)node->info;
    data->visited = 1;
    data->distance = 0;
    
    printf("After processing:\n");
    printf("Visited: %s\n", data->visited ? "Yes" : "No");
    printf("Distance: %d\n", data->distance);
    
    free(node->info);
    free(node);
}

int main()
{
    printf("=== THE POWER OF void *info POINTER ===\n\n");
    
    printf("The void *info pointer is incredibly flexible!\n");
    printf("It can store ANY type of data you need.\n\n");
    
    demo_string_info();
    demo_integer_info();
    demo_struct_info();
    demo_array_info();
    demo_root_info();
    demo_algorithm_info();
    
    printf("\n=== KEY TAKEAWAYS ===\n");
    printf("1. void* can point to ANY data type\n");
    printf("2. Always cast back to the correct type when using\n");
    printf("3. Remember to malloc/free memory for complex data\n");
    printf("4. Use it for metadata, custom data, algorithm info\n");
    printf("5. Both ENTRY and ROOT have info pointers\n");
    printf("6. It's your 'universal storage slot'!\n");
    
    return 0;
}
