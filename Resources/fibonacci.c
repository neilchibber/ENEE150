/* It shows how the recursive function fib() is called when we 
	compute fib(3).
							Gang Qu
							Nov. 4, 2004
*/

#include <stdio.h>

#define N 6

int fib(int n)
{ int total;

  printf("%*sEnter with n = %d \t Copmuting fib(%d)\n", N-n, "", n, n);

  if ( n <= 1 ) total = 1;
  else total = fib(n-1) + fib(n-2);

  printf("%*sExit with fib(%d) = %d\n", N-n, "", n, total);
  return total;
}

int main (void)
{

  int A =5;
  printf("%d",A);
  printf("fib(%d) = %d\n", N, fib(N));
  return 0;
}
