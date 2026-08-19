/*
==============================================================================
HW5 CONCEPTS & TRICKS - Learn the Patterns, Not Just Solutions

This guide teaches you the fundamental concepts and tricks needed for all 18 problems
==============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// ==================== FUNDAMENTAL CONCEPTS ====================

void fundamental_concepts() {
    printf("=== FUNDAMENTAL CONCEPTS ====================\n\n");
    
    printf("1. MEMORY MANAGEMENT:\n");
    printf("   - Every malloc needs a free\n");
    printf("   - Check for NULL after malloc\n");
    printf("   - Free data pointer first, then node\n\n");
    
    printf("2. POINTER BASICS:\n");
    printf("   - *data = value, data = address\n");
    printf("   - current->next moves to next node\n");
    printf("   - prev pointer needed for deletions\n\n");
    
    printf("3. TRAVERSAL PATTERNS:\n");
    printf("   - Single pointer: basic traversal\n");
    printf("   - Two pointers: advanced operations\n");
    printf("   - Three pointers: reversals\n\n");
}

// ==================== CORE TRICKS ====================

void core_tricks() {
    printf("=== CORE TRICKS ====================\n\n");
    
    printf("TRICK 1: TWO-POINTER TECHNIQUE\n");
    printf("   - Use for: k-th from end, middle node\n");
    printf("   - Pattern: fast moves 2x, slow moves 1x\n");
    printf("   - When fast reaches end, slow is at target\n\n");
    
    printf("TRICK 2: PREV POINTER TRACKING\n");
    printf("   - Use for: deletions, insertions\n");
    printf("   - Pattern: always know previous node\n");
    printf("   - Essential for modifying list structure\n\n");
    
    printf("TRICK 3: DUMMY HEAD NODE\n");
    printf("   - Use for: simplifying edge cases\n");
    printf("   - Pattern: dummy->next = real head\n");
    printf("   - Eliminates head deletion special case\n\n");
    
    printf("TRICK 4: COUNTER-BASED INDEXING\n");
    printf("   - Use for: k-th node, position operations\n");
    printf("   - Pattern: count while traversing\n");
    printf("   - Stop when count reaches target\n\n");
}

// ==================== PROBLEM PATTERNS ====================

void problem_patterns() {
    printf("=== PROBLEM PATTERNS ====================\n\n");
    
    printf("PATTERN A: BASIC TRAVERSAL (Problems 2,3,4)\n");
    printf("   - Initialize: current = root->head\n");
    printf("   - Loop: while (current != NULL)\n");
    printf("   - Process: *(current->data)\n");
    printf("   - Advance: current = current->next\n\n");
    
    printf("PATTERN B: POSITION-BASED ACCESS (Problems 5,7)\n");
    printf("   - Use counter starting from 1\n");
    printf("   - Stop when counter == target position\n");
    printf("   - Handle edge cases (k <= 0, k > length)\n\n");
    
    printf("PATTERN C: DELETION WITH PREV (Problems 8,9)\n");
    printf("   - Track both current and prev\n");
    printf("   - When deleting: prev->next = current->next\n");
    printf("   - Free memory properly\n\n");
    
    printf("PATTERN D: LIST REVERSAL (Problems 12,16)\n");
    printf("   - Use three pointers: prev, current, next\n");
    printf("   - Pattern: prev = current; current = next\n");
    printf("   - Final: root->head = prev\n\n");
    
    printf("PATTERN E: LIST SPLITTING (Problems 11,13)\n");
    printf("   - Create separate lists\n");
    printf("   - Use multiple heads/tails\n");
    printf("   - Join at the end\n\n");
}

// ==================== ADVANCED TECHNIQUES ====================

void advanced_techniques() {
    printf("=== ADVANCED TECHNIQUES ====================\n\n");
    
    printf("TECHNIQUE 1: NESTED LOOPS FOR COMPARISONS\n");
    printf("   - Use for: duplicates, sub-lists, multiples\n");
    printf("   - Outer: current node\n");
    printf("   - Inner: compare with remaining nodes\n");
    printf("   - Time: O(n²) but simple\n\n");
    
    printf("TECHNIQUE 2: MERGE PATTERN\n");
    printf("   - Use for: merging sorted lists\n");
    printf("   - Pattern: compare heads, take smaller\n");
    printf("   - Advance the chosen list\n\n");
    
    printf("TECHNIQUE 3: IN-PLACE SWAPPING\n");
    printf("   - Use for: sorting, rearranging\n");
    printf("   - Swap data values, not pointers\n");
    printf("   - Simpler than pointer manipulation\n\n");
    
    printf("TECHNIQUE 4: ARRAY CONVERSION\n");
    printf("   - Use for: complex comparisons\n");
    printf("   - Copy list to array for easy access\n");
    printf("   - Convert back to list if needed\n\n");
}

// ==================== COMMON MISTAKES TO AVOID ====================

void common_mistakes() {
    printf("=== COMMON MISTAKES TO AVOID ====================\n\n");
    
    printf("MISTAKE 1: WRONG LOOP CONDITIONS\n");
    printf("   - Wrong: while (list->head != NULL)\n");
    printf("   - Right: while (current != NULL)\n");
    printf("   - Why: list->head doesn't change during traversal\n\n");
    
    printf("MISTAKE 2: INCORRECT POINTER SYNTAX\n");
    printf("   - Wrong: NODE* (new_node->data)\n");
    printf("   - Right: new_node->data = (int*)malloc\n");
    printf("   - Why: data is already a pointer\n\n");
    
    printf("MISTAKE 3: MISSING RANDOM SEED\n");
    printf("   - Wrong: rand() without srand()\n");
    printf("   - Right: srand(time(NULL)) first\n");
    printf("   - Why: ensures different random numbers\n\n");
    
    printf("MISTAKE 4: MEMORY LEAKS\n");
    printf("   - Wrong: malloc without free\n");
    printf("   - Right: free(data), then free(node)\n");
    printf("   - Why: prevent memory leaks\n\n");
    
    printf("MISTAKE 5: WRONG DATA ACCESS\n");
    printf("   - Wrong: new_node->val\n");
    printf("   - Right: *(new_node->data)\n");
    printf("   - Why: data is pointer to int\n\n");
}

// ==================== PROBLEM-SPECIFIC TRICKS ====================

void problem_specific_tricks() {
    printf("=== PROBLEM-SPECIFIC TRICKS ====================\n\n");
    
    printf("PROBLEM 6 (k-th from end):\n");
    printf("   - Move fast k steps ahead first\n");
    printf("   - Then move both until fast hits end\n");
    printf("   - Slow will be at k-th from end\n\n");
    
    printf("PROBLEM 9 (remove duplicates):\n");
    printf("   - Keep track of first occurrence\n");
    printf("   - Remove all subsequent matches\n");
    printf("   - Use prev pointer for deletions\n\n");
    
    printf("PROBLEM 10 (sort list):\n");
    printf("   - Use bubble sort: compare adjacent\n");
    printf("   - Swap data values, not pointers\n");
    printf("   - Repeat until no swaps needed\n\n");
    
    printf("PROBLEM 14 (sub-list check):\n");
    printf("   - Try every starting position in P1\n");
    printf("   - Compare sequence with P2\n");
    printf("   - Return 1 if full match found\n\n");
    
    printf("PROBLEM 18 (find multiples):\n");
    printf("   - Check all pairs (i,j) where i < j\n");
    printf("   - Test both: values[i] % values[j] == 0\n");
    printf("   - Return index of smaller value\n\n");
}

// ==================== DEBUGGING STRATEGIES ====================

void debugging_strategies() {
    printf("=== DEBUGGING STRATEGIES ====================\n\n");
    
    printf("STRATEGY 1: PRINT INTERMEDIATE RESULTS\n");
    printf("   - Print list after each operation\n");
    printf("   - Verify structure is correct\n");
    printf("   - Use print_list() frequently\n\n");
    
    printf("STRATEGY 2: TEST EDGE CASES\n");
    printf("   - Empty list\n");
    printf("   - Single node\n");
    printf("   - k = 1, k = length\n");
    printf("   - All same values\n\n");
    
    printf("STRATEGY 3: MEMORY TRACKING\n");
    printf("   - Count malloc vs free calls\n");
    printf("   - Use valgrind if available\n");
    printf("   - Check for NULL pointers\n\n");
    
    printf("STRATEGY 4: STEP-BY-STEP EXECUTION\n");
    printf("   - Walk through algorithm manually\n");
    printf("   - Use small test lists\n");
    printf("   - Verify each step works\n\n");
}

// ==================== TIME COMPLEXITY INSIGHTS ====================

void time_complexity_insights() {
    printf("=== TIME COMPLEXITY INSIGHTS ====================\n\n");
    
    printf("TRAVERSAL OPERATIONS: O(n)\n");
    printf("   - Single pass through list\n");
    printf("   - Examples: print, find max, count\n\n");
    
    printf("TWO-POINTER OPERATIONS: O(n)\n");
    printf("   - Still single pass, just with two pointers\n");
    printf("   - Examples: middle, k-th from end\n\n");
    
    printf("NESTED LOOP OPERATIONS: O(n²)\n");
    printf("   - Compare each pair of nodes\n");
    printf("   - Examples: duplicates, sub-list, multiples\n\n");
    
    printf("SORTING OPERATIONS: O(n²)\n");
    printf("   - Bubble sort on linked list\n");
    printf("   - Can be optimized but basic is O(n²)\n\n");
    
    printf("MERGE OPERATIONS: O(n+m)\n");
    printf("   - Single pass through both lists\n");
    printf("   - Examples: merge sorted, alternate merge\n\n");
}

// ==================== MENTAL MODELS ====================

void mental_models() {
    printf("=== MENTAL MODELS ====================\n\n");
    
    printf("MODEL 1: TRAIN CARS\n");
    printf("   - Nodes = train cars\n");
    printf("   - next = connection to next car\n");
    printf("   - head = locomotive\n");
    printf("   - Traversal = walking through train\n\n");
    
    printf("MODEL 2: CHAIN OF PEOPLE\n");
    printf("   - Nodes = people holding hands\n");
    printf("   - next = person to the right\n");
    printf("   - prev = person to the left\n");
    printf("   - Deletion = someone letting go\n\n");
    
    printf("MODEL 3: DIRECTIONS\n");
    printf("   - Head = starting point\n");
    printf("   - Next = forward direction\n");
    printf("   - Prev = backward direction\n");
    printf("   - Traversal = following path\n\n");
    
    printf("MODEL 4: BOOK PAGES\n");
    printf("   - Nodes = pages\n");
    printf("   - next = next page\n");
    printf("   - Data = page number\n");
    printf("   - Insertion = adding new page\n\n");
}

// ==================== QUICK REFERENCE ====================

void quick_reference() {
    printf("=== QUICK REFERENCE ====================\n\n");
    
    printf("BASIC TRAVERSAL:\n");
    printf("   NODE *current = root->head;\n");
    printf("   while (current != NULL) {\n");
    printf("       // process *(current->data)\n");
    printf("       current = current->next;\n");
    printf("   }\n\n");
    
    printf("DELETION WITH PREV:\n");
    printf("   NODE *current = root->head, *prev = NULL;\n");
    printf("   while (current != NULL) {\n");
    printf("       if (should_delete) {\n");
    printf("           if (prev == NULL) root->head = current->next;\n");
    printf("           else prev->next = current->next;\n");
    printf("           free(current->data); free(current);\n");
    printf("       } else {\n");
    printf("           prev = current; current = current->next;\n");
    printf("       }\n");
    printf("   }\n\n");
    
    printf("TWO-POINTER TECHNIQUE:\n");
    printf("   NODE *slow = root->head, *fast = root->head;\n");
    printf("   for (int i = 0; i < k; i++) fast = fast->next;\n");
    printf("   while (fast != NULL) {\n");
    printf("       fast = fast->next;\n");
    printf("       slow = slow->next;\n");
    printf("   }\n");
    printf("   // slow is at target position\n\n");
}

// ==================== MAIN FUNCTION ====================

int main() {
    printf("HW5 CONCEPTS & TRICKS - Complete Learning Guide\n");
    printf("===============================================\n\n");
    
    fundamental_concepts();
    core_tricks();
    problem_patterns();
    advanced_techniques();
    common_mistakes();
    problem_specific_tricks();
    debugging_strategies();
    time_complexity_insights();
    mental_models();
    quick_reference();
    
    printf("\n=== LEARNING COMPLETE ===\n");
    printf("You now understand:\n");
    printf("- Core concepts and patterns\n");
    printf("- Essential tricks and techniques\n");
    printf("- Common mistakes to avoid\n");
    printf("- Debugging strategies\n");
    printf("- Time complexity insights\n");
    printf("- Mental models for understanding\n");
    printf("- Quick reference patterns\n\n");
    
    printf("Ready to tackle any HW5 problem! 🎯\n");
    
    return 0;
}
