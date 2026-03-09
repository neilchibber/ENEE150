/* Rewrite function foo() without recursion and explain what it does in
plain English as comment at the start of your code.

                                                        Gang Qu
*/

/* This function returns the maximum value in the first n elements of array A. It iterates through all elements
   and keeps track of the largest value found. */
#include <stdio.h>

int foo(int A[], int n)
{
    int res = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > res) {
            res = A[i];
        }
    }
    return res;
}

int main()
{ int A[10] = {1, -2, 3, -4, 5, -6, 7, -8, 9, 10};
    int i=1;

    for (; i<=10;)
        printf("largest in the first %d numbers: %d\n", i++, foo(A, i));

    return 0;
}

