#include <stdio.h>

/*
        QUESTION 2: ITERATION TO RECURSION

        Rewrite the following function bar to utilize recursion instead of iteration.
        Your rewritten function must not include any loops.

        Also, in comments, explain what the function does in plain english.
*/

int foo(int A[], int n, int x, int y){

    /*
    This function counts how many elements in the array A between indices x and y
    are divisible by n. If the starting index has passed the end index,
    there are no more elements to examine, so return 0. Otherwise,
    check the current element and add 1 if it divides evenly by n,
    Then recurse with x+1 (the next index).
    */

        if (x > y) {
                return 0;
        }
        int count = (A[x] % n == 0) ? 1 : 0;
        return count + foo(A, n, x + 1, y);
}

//The following main function is to test the functions output

int main(){
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        printf("%d\n", foo(arr, 2, 0, 8));
        printf("%d\n", foo(arr, 3, 0, 8));
        printf("%d\n", foo(arr, 2, 0, 1));
        printf("%d\n", foo(arr, 3, 0, 1));
        return 0;
}