#include <stdio.h>

/*
        QUESTION 1: RECURSION TO ITERATION

        Rewrite the following function bar to utilize iteration instead of recursion.
        Your rewritten function must not include any recursive function calls.

        Also, in comments, explain what the function does in plain english.
*/


/*
This function computes the sum of the digits of n.
If n is negative it returns 0. We repeatedly take the last
digit, add it to the sum, and divide n by 10 until
n becomes zero or negative
*/
int foo(int n){

        int sum = 0;
        while (n > 0) {
                sum += n % 10;
                n /= 10;
        }
        return sum;
}

//The following main function is to test the functions output

int main(){
        printf("foo(%d) = %d\n", 1234, foo(1234));
        printf("foo(%d) = %d\n", 507, foo(507));
        return 0;
}