#include <stdio.h>
#include <stdlib.h>

/*
==============================================================================
POINTERS AND DYNAMIC MEMORY ALLOCATION TUTORIAL
Based on finals announcement: "basic concepts, special pointers and constants"

This covers short answer questions about pointers and memory management
==============================================================================
*/

// ==================== LESSON 1: BASIC POINTER CONCEPTS ====================

void lesson_basic_pointers() {
    printf("=== LESSON 1: BASIC POINTER CONCEPTS ===\n\n");
    
    printf("WHAT IS A POINTER?\n");
    printf("A pointer is a variable that stores the memory address of another variable.\n\n");
    
    printf("KEY CONCEPTS:\n");
    printf("- &: Address operator - gets memory address\n");
    printf("- *: Dereference operator - gets value at address\n");
    printf("- NULL: Special pointer value meaning 'points to nothing'\n\n");
    
    printf("EXAMPLE:\n");
    printf("int x = 10;\n");
    printf("int *p = &x;  // p stores address of x\n");
    printf("*p = 20;     // Changes x to 20 through pointer\n\n");
}

// ==================== LESSON 2: SPECIAL POINTERS AND CONSTANTS ====================

void lesson_special_pointers() {
    printf("=== LESSON 2: SPECIAL POINTERS AND CONSTANTS ====================\n\n");
    
    printf("SPECIAL POINTER VALUES:\n");
    printf("1. NULL: Points to nothing, used for initialization\n");
    printf("2. void*: Generic pointer, can point to any data type\n");
    printf("3. const: Read-only pointer, cannot modify pointed value\n\n");
    
    printf("POINTER CONSTANTS:\n");
    printf("1. const int *p: Cannot change value through p\n");
    printf("2. int * const p: Cannot change p itself\n");
    printf("3. const int * const p: Cannot change p or value\n\n");
    
    printf("EXAMPLES:\n");
    printf("int x = 5;\n");
    printf("const int *p1 = &x;  // *p1 = 10 is ERROR\n");
    printf("int * const p2 = &x;  // p2 = &y is ERROR\n");
    printf("const int * const p3 = &x;  // Both operations are ERROR\n\n");
}

// ==================== LESSON 3: DYNAMIC MEMORY ALLOCATION ====================

void lesson_dynamic_memory() {
    printf("=== LESSON 3: DYNAMIC MEMORY ALLOCATION ====================\n\n");
    
    printf("DYNAMIC MEMORY FUNCTIONS:\n");
    printf("1. malloc(size): Allocate memory, not initialized\n");
    printf("2. calloc(num, size): Allocate memory, initialized to 0\n");
    printf("3. realloc(ptr, size): Resize allocated memory\n");
    printf("4. free(ptr): Deallocate memory\n\n");
    
    printf("STACK vs HEAP:\n");
    printf("- Stack: Automatic, function scope, limited size\n");
    printf("- Heap: Dynamic, manual control, larger size\n\n");
    
    printf("MEMORY MANAGEMENT RULES:\n");
    printf("1. Every malloc needs a free\n");
    printf("2. Free memory only once\n");
    printf("3. Don't use freed memory\n");
    printf("4. Check for NULL after malloc\n\n");
}

// ==================== PRACTICE PROBLEMS ====================

void practice_problems() {
    printf("=== PRACTICE PROBLEMS - Short Answer Questions ===\n\n");
    
    printf("PROBLEM 1: Pointer Basics\n");
    printf("int x = 10;\n");
    printf("int *p = &x;\n");
    printf("int **pp = &p;\n\n");
    
    printf("QUESTIONS:\n");
    printf("A. What does *p equal?\n");
    printf("B. What does **pp equal?\n");
    printf("C. What does pp equal?\n");
    printf("D. What does &pp equal?\n\n");
    
    printf("ANSWERS:\n");
    printf("A. 10 (value of x)\n");
    printf("B. 10 (value of x through double pointer)\n");
    printf("C. Address of p\n");
    printf("D. Address of pp\n\n");
    
    printf("PROBLEM 2: Pointer Arithmetic\n");
    printf("int arr[] = {10, 20, 30, 40};\n");
    printf("int *p = arr;\n\n");
    
    printf("QUESTIONS:\n");
    printf("A. What does p[0] equal?\n");
    printf("B. What does *(p+1) equal?\n");
    printf("C. What does p[2] equal?\n");
    printf("D. What does *(p+3) equal?\n\n");
    
    printf("ANSWERS:\n");
    printf("A. 10\n");
    printf("B. 20\n");
    printf("C. 30\n");
    printf("D. 40\n\n");
    
    printf("PROBLEM 3: Memory Allocation\n");
    printf("int *p = (int*)malloc(5 * sizeof(int));\n");
    printf("for (int i = 0; i < 5; i++) p[i] = i * 10;\n\n");
    
    printf("QUESTIONS:\n");
    printf("A. How many bytes are allocated?\n");
    printf("B. What is p[2] after the loop?\n");
    printf("C. What happens if you don't free(p)?\n");
    printf("D. What's the difference between malloc and calloc?\n\n");
    
    printf("ANSWERS:\n");
    printf("A. 20 bytes (5 * 4 bytes)\n");
    printf("B. 20\n");
    printf("C. Memory leak\n");
    printf("D. calloc initializes to 0, malloc doesn't\n\n");
}

// ==================== CODE ANALYSIS PROBLEMS ====================

void code_analysis_problems() {
    printf("=== CODE ANALYSIS PROBLEMS ====================\n\n");
    
    printf("PROBLEM 4: Find the Bug\n");
    printf("void function() {\n");
    printf("    int *p = (int*)malloc(sizeof(int));\n");
    printf("    *p = 10;\n");
    printf("    p = (int*)malloc(sizeof(int));\n");
    printf("    *p = 20;\n");
    printf("    free(p);\n");
    printf("}\n\n");
    
    printf("QUESTIONS:\n");
    printf("A. What's the bug?\n");
    printf("B. How many bytes are leaked?\n");
    printf("C. How would you fix it?\n\n");
    
    printf("ANSWERS:\n");
    printf("A. Memory leak - first malloc is never freed\n");
    printf("B. 4 bytes leaked\n");
    printf("C. Store first pointer or free before reallocating\n\n");
    
    printf("PROBLEM 5: Pointer Constants\n");
    printf("const int x = 10;\n");
    printf("int *p = &x;\n");
    printf("*p = 20;\n\n");
    
    printf("QUESTIONS:\n");
    printf("A. Is this valid code?\n");
    printf("B. What happens if you try to modify x through p?\n");
    printf("C. What's the proper declaration?\n\n");
    
    printf("ANSWERS:\n");
    printf("A. No - compiler warning\n");
    printf("B. Undefined behavior\n");
    printf("C. const int *p = &x;\n\n");
    
    printf("PROBLEM 6: Double Pointers\n");
    printf("void swap(int **a, int **b) {\n");
    printf("    int *temp = *a;\n");
    printf("    *a = *b;\n");
    printf("    *b = temp;\n");
    printf("}\n\n");
    
    printf("QUESTIONS:\n");
    printf("A. What does this function do?\n");
    printf("B. Why use double pointers?\n");
    printf("C. How would you call this function?\n\n");
    
    printf("ANSWERS:\n");
    printf("A. Swaps two pointers\n");
    printf("B. To modify the pointers themselves\n");
    printf("C. swap(&p1, &p2);\n\n");
}

// ==================== EXAM-STYLE QUESTIONS ====================

void exam_style_questions() {
    printf("=== EXAM-STYLE QUESTIONS ====================\n\n");
    
    printf("QUESTION 1: What's the difference between:\n");
    printf("int *p[10]; vs int (*p)[10];\n\n");
    
    printf("ANSWER:\n");
    printf("int *p[10]: Array of 10 pointers\n");
    printf("int (*p)[10]: Pointer to array of 10 integers\n\n");
    
    printf("QUESTION 2: What does this code print?\n");
    printf("int x = 5;\n");
    printf("int *p = &x;\n");
    printf("int **pp = &p;\n");
    printf("printf(\"%d %d %d\\n\", x, *p, **pp);\n\n");
    
    printf("ANSWER:\n");
    printf("5 5 5\n\n");
    
    printf("QUESTION 3: What's wrong with this?\n");
    printf("char *str = \"Hello\";\n");
    printf("str[0] = 'J';\n\n");
    
    printf("ANSWER:\n");
    printf("String literals are read-only - causes segmentation fault\n\n");
    
    printf("QUESTION 4: What's the output?\n");
    printf("int arr[] = {1, 2, 3};\n");
    printf("int *p = arr;\n");
    printf("printf(\"%d %d\\n\", *p++, *(p+1));\n\n");
    
    printf("ANSWER:\n");
    printf("1 3 (p is incremented after value is taken)\n\n");
}

// ==================== MEMORY MANAGEMENT EXAMPLES ====================

void memory_management_examples() {
    printf("=== MEMORY MANAGEMENT EXAMPLES ====================\n\n");
    
    printf("EXAMPLE 1: Proper Memory Management\n");
    printf("int *create_array(int size) {\n");
    printf("    int *arr = (int*)malloc(size * sizeof(int));\n");
    printf("    if (arr == NULL) return NULL;\n");
    printf("    for (int i = 0; i < size; i++) arr[i] = i;\n");
    printf("    return arr;\n");
    printf("}\n\n");
    
    printf("void cleanup_array(int *arr) {\n");
    printf("    free(arr);  // Always free what you malloc\n");
    printf("}\n\n");
    
    printf("EXAMPLE 2: Common Memory Errors\n");
    printf("1. Double free: free(p); free(p);\n");
    printf("2. Use after free: free(p); *p = 10;\n");
    printf("3. Memory leak: malloc but no free\n");
    printf("4. NULL dereference: p = NULL; *p = 10;\n\n");
    
    printf("EXAMPLE 3: Safe Memory Usage\n");
    printf("int *p = (int*)malloc(sizeof(int));\n");
    printf("if (p == NULL) return;  // Always check malloc result\n");
    printf("*p = 10;\n");
    printf("free(p);\n");
    printf("p = NULL;  // Avoid use after free\n\n");
}

// ==================== MAIN FUNCTION ====================

int main() {
    printf("POINTERS AND DYNAMIC MEMORY ALLOCATION - COMPLETE GUIDE\n");
    printf("=====================================================\n\n");
    
    lesson_basic_pointers();
    lesson_special_pointers();
    lesson_dynamic_memory();
    
    printf("\n");
    practice_problems();
    code_analysis_problems();
    exam_style_questions();
    memory_management_examples();
    
    printf("\n=== EXAM PREPARATION COMPLETE ===\n");
    printf("You now understand:\n");
    printf("- Basic pointer concepts and operations\n");
    printf("- Special pointers and constants\n");
    printf("- Dynamic memory allocation\n");
    printf("- Memory management and common errors\n");
    printf("- Ready for short answer questions!\n\n");
    
    return 0;
}
