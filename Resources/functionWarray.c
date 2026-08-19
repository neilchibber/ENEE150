/* This program shows how to pass array to functions and "return" array 
	from a function, including multi-dimensional arrays. 
							Gang Qu
							Sept. 1, 2015
*/

#include <stdio.h>

#define SIZE 10

int arraySize (char A[]);
// returns the real size of an array

int arrayCompare(char A[], int n, char B[], int m);
// compare two character arrays (strings)  A[] and B[].
// return 1 if A[] is in front of B[] in dictionary order
// return -1 if B[] is in front of A[]
// return 0 if they are identical

void printArrays(char A[], char B[], int k);
// if k = 1, print A[] first; otherwise B[] first

void transpose(char A[], int n, char B[], int m, char T[][2], int k);
// T[0][0] = A[0], T[0][1] = B[0]
// T[1][0] = A[1], T[1][1] = B[1]
// ...
// k = max (n,m)

void printT(char [][2], int);

int main (void)
{ int compare, size1, size2, row;
  char s1[SIZE], s2[SIZE], s3[SIZE][2];

  printf("Enter two strings of 10 characters or less:");
  scanf("%s%s", s1, s2);

  size1 = arraySize (s1);
  size2 = arraySize (s2);

  compare = arrayCompare(s1, size1, s2, size2);

  printArrays(s1, s2, compare);

  row = (size1 < size2)? size2: size1;

  printf("Now we transpose arrays A[] and B[].\n");

  transpose (s1, size1, s2, size2, s3, row);

  printT(s3, row);

  return 0;
}

void printArrays(char A[], char B[], int k)
{ if (k == 1)
    printf("%s\n%s\n", A, B);
  else 
    printf("%s\n%s\n", B, A);
}

int arraySize (char A[])
{ int size=0;
  
  for (; A[size] !='\0'; size++);

  return size;
}

int arrayCompare(char A[], int n, char B[], int m)
{ int i;
  
  for (i=0; i<n && i <m; i++)
  { if (A[i] < B[i]) return 1;
    if (A[i] > B[i]) return -1;
  }

  if ((i == n) && (i == m)) return 0;
  else if (i == n) return 1;
       else return -1;
}

void transpose (char A[], int size1, char B[], int size2, char T[][2], int k)
{ int i;

  for (i=0; i<k; i++)
  { if (i < size1) T[i][0] = A[i];
    else T[i][0] = '-';
    if (i < size2) T[i][1] = B[i];
    else T[i][1] = '-';
  }
}

void printT(char T[][2], int k)
{ int i;
  for (i=0; i < k; i++)
    printf("%c%c\n", T[i][0], T[i][1]);
}

