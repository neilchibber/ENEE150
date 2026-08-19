/* This code implement the insertion sorting algorithm. 
   We assume that the array will be sorted in the ascending order.
   a[0]
   compare a[0] and a[1], and insert a[1] in its correct postion 
   compare a[k] with the sorted list a[0], ..., a[k-1], and 
	insert it in the correct position 
						Gang Qu
						Feb. 18, 2021
*/


#include <stdio.h>

#define SIZE 10

void printArray(int a[], int n)
{ int i;
  for(i=0; i<n; i++)
  { printf("%3d", a[i]);
    if(i<n-1)
      printf(", ");
  }
  printf("\n");

  return;
}

int main(void)
{
	int a[] = {20,5,11,-3,0,34,-12,9,100,4};
	int i, j, key, tmp, pos;

	//print initial sorting
	printf("Initial order: ");
        printArray(a, SIZE);

	//sort the array
	for(i=1; i<SIZE; i++) 	
	// insert a[i] to its correct position
	// to hide the details, comment all the printing except the first two
	// after line 	j = i -1;
	{ key = a[i];
 	  j = i - 1;
	printf("i=%d insert %3d to: ", i, key);
	printArray (a, i);
	  while (j>=0 && key < a[j])
	  { a[j+1] = a[j];
	printf("\t      j=%d: ", j);
	    j--;
	printArray(a, i+1);
 	  }
	  a[j+1] = key;
	printf("after  insert %3d: ", key);
 	printArray(a, i+1);
	printf("\n");
	}

	printf("After sorting: ");
  	printArray(a, SIZE);

	return 0;
}
