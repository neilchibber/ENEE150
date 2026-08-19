/* This program reads in 9 integers, store them in an array, and then
	sort them in the ascending out. The bubble sort algorithm is
	used here and three implementations are given.
   4 sets of test date to consier
	1 2 3 4 5 6 7 8 9
	9 8 7 6 5 4 3 2 1
	2 10 -3 0 4 9 7 21 -11
	2 10 -3 0 4 9 4 2 2

							Gang Qu
							Feb. 18, 2021
*/


#include <stdio.h>

#define SIZE 9 

int main(void)

{  int i, j, tmp, key, position; 

  int cnt1=0, cnt2=0, cnt3=0;	// count the number of comparisons in the 2 approaches
  int copy1=0, copy2=0, copy3=0; // number of copies in the sorting algorithm

  int a[SIZE], b[SIZE], c[SIZE];

// initialize array
  printf("Please enter %d integers: ", SIZE);
  for (i=0;i<SIZE;i++)
  { scanf("%d", &a[i]);
    b[i] = a[i];
    c[i] = a[i];
  }

  for (i=0;i<SIZE;i++)
   printf("a[%d] = %3d \t b[%d] = %3d \t c[%d] = %3d\n", i, a[i], i, b[i], i, c[i]);

// sorting algorithm from the lecture notes
  for (i=0; i<SIZE; i++)
  { for (j=SIZE-1; j>=i+1; j--)
    { cnt1++;
      if (a[j] < a[j-1])
      { tmp = a[j];
  	a[j] = a[j-1];
	a[j-1] = tmp;
	copy1 += 3;
      }
    }
  }

// straightfoward way to bubble sort
  for(i=0;i<SIZE;i++)
  { // put the i-th largest number as the i-th element in this iteration.
    // 	swap the larger number to the i-th place whenever it is found. 
    for (position=i; position<SIZE; position++)
    { cnt2++;
      if ( b[i] > b[position])
      { key = b[i];
        b[i] = b[position];
        b[position] = key;
        copy2 += 3;
      }
    }
  }

// another way to do it, less swaps of array elements, but you need to
//	declare new variable to remember what is the current largest
//	element (variable "key" below) and its index (variable "position")
  for (i=0;i<SIZE;i++)
  { // find the i-th smallest number in this iteration, (bubble sort)
    key = c[i];
    copy3++;
    position = i;
    for(j=position+1; j<SIZE; j++)
    { cnt3++;
      if (key > c[j])
      { key = c[j];
	copy3++;
        position = j;
      }
    }
    c[position] = c[i];
    c[i] = key;
    copy3 += 2;
  }

  printf("After sorting:\n");
  for (i=0;i<SIZE;i++)
   printf("a[%d]=%4d \t b[%d]=%4d \t c[%d]=%4d\n", i, a[i], i, b[i], i, c[i]);

  printf("counter1 = %d\tcopy1 = %d\n", cnt1, copy1);
  printf("counter2 = %d\tcopy2 = %d\n", cnt2, copy2);
  printf("counter3 = %d\tcopy3 = %d\n", cnt3, copy3);

  return 0;
}
  
