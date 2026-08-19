/* This program shows that when variables of int (or char, or double, and 
	so on) type are passed to a function, it is a copy of the value of
	variable that is passed to the function, the variable itself remains
	unchanges. However, when an array is passed to a function, the real
	array, not a copy of it, will be passed to the function, and whatever
	change you make to the array in the function will stay there.
							Gang Qu
							Sept. 1, 2015
*/


#include <stdio.h>

void swap1 (int, int);
// swap two numbers. WARNING: this will not swap the values of the two
// parameters passed to this function.

void swap2 (int a[], int, int, int );
// swap two elements in the given positions (the last two parameters
// in array a[] of a given size (the second parameter).

void swap3 (int*, int*);
// swap two numbers. WARNING: this will swap the values of the two
// parameters passed to this function.

int main (void)
{ 
  int a[8] = {2,3,5,7,11,13,17,19};
  int pos1, pos2;		// the indices of elements to be swaped
  int i;

  printf("The original array:\n");
  for (i=0; i<8; i++)
    printf("\ta[%d] = %2d\n", i, a[i]);

  printf("Enter the indices of the two numbers that you want to swap: ");
  scanf("%d%d", &pos1, &pos2);

  printf("\nYour have entered:   pos1 = %2d, pos2 = %2d\n", pos1, pos2);
  swap1 (pos1, pos2);
  printf("After calling swap1: pos1 = %2d, pos2 = %2d\n\n", pos1, pos2);

  printf("\nYour have entered:   pos1 = %2d, pos2 = %2d\n", pos1, pos2);
  swap3 (&pos1, &pos2);
  printf("After calling swap3: pos1 = %2d, pos2 = %2d\n\n", pos1, pos2);

  swap2 (a, 8, pos1, pos2);

  printf("After swap:\n");
  for (i=0; i<8; i++)
    if ( i == pos1 || i == pos2)
      printf("\ta[%d] = %2d  <---\n", i, a[i]);
    else
      printf("\ta[%d] = %2d\n", i, a[i]);

  return 0;
}

void swap2 (int a[], int size, int x, int y)
{  int tmp; 

   if ( x >= size || x < 0 || y >= size || y < 0 )
   { printf("Invalid index passed to the array. No swap performed.\n");
     return;
   }

   tmp = a[x];
   a[x] = a[y];
   a[y] = tmp; 
}

void swap3 (int *x, int *y)
{ int tmp;
  printf("Inside swap: x = %d, y = %d\n", *x, *y);
  tmp = *x;
  *x = *y;
  *y = tmp;
  printf("Inside swap: x = %d, y = %d\n", *x, *y);
}

void swap1 (int x, int y)
{ int tmp;
  printf("Inside swap: x = %d, y = %d\n", x, y);
  tmp = x;
  x = y;
  y = tmp;
  printf("Inside swap: x = %d, y = %d\n", x, y);
}
