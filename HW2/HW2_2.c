/* this is a ssample main program to test your recursion version of foo().

Gang Qu
*/

#include <stdio.h>

int foo (int A[], int n)
{
    if (n == 0) {
        return 0;
    }
    return A[n-1] + foo(A, n-1);
}

int main()
{ int A[10] = {1, 2, 3, -4, -5, -6, 7, 8, 9, 10};
    int i=1;

    for (; i<=10;)
        printf("sum of the first %d numbers: %d\n", i++, foo(A, i));

    return 0;
}

