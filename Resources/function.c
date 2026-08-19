/* This program shows the basics about function. It reads in two integers
	a and b, and computes "a choose b", the number of different ways 
	to select b objects from a total of a objects. 
   a <= 12 due to the way we implement this.
							Gang Qu
							Sept. 1, 2015
*/

#include <stdio.h>

int fact (int k)
{ int i, temp;
  
  temp = 1;

  for (i=1; i<=k; i++)
	temp *= i;

  return temp;
}

int main (void)
{ int a, b, a_choose_b;

  printf("Enter integers a and b (a >= b and a <= 12, b > 0):");
  scanf("%d%d", &a, &b);

  a_choose_b = fact(a) / fact(b) /fact(a-b);

  printf("%d choose %d is %d\n", fact(a), fact(b), a_choose_b);

  return 0;
}

