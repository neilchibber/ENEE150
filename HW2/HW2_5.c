/* Rewrite function foo() without recursion and explain what it does in
plain English as comment at the start of your code.

                            Gang Qu
*/

#include <stdio.h>

/* This function converts and prints the binary representation
   of the perfect squares. It repeatedly divides n by 2, storing each
   remainder (0 or 1), then prints all digits to display the binary form. */

void foo(int n)
{
    if (n == 0) {
        return;
    }
    
    int binary[32];
    int i = 0;
    
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main()
{ int i=0;

    for (; i<10; i++)
    { printf("%d: ", i*i);
        foo(i*i);
        printf("\n");
    }

    return 0;
}

