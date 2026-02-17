/* 
  Calculates and prints the area and circumference of a circle. 
  This function takes the radius of a circle as input, computes the area using A = pi*r^2
  and the circumference using C = 2*pi*r, and prints the results. 
  The radius of the circle (must be non-negative).
  */
void areaCircumference(int radius);

/*  
   Performs a linear search on an integer array.
  
   This function searches through the given array for a specified value.
   If the value is found, the index of its first occurrence is returned.
   If the value is not found, the function returns -1.
  
   array is the integer array to search.
   size is the number of elements in the array.
   value is the value to search for.
   Then we return the index of the found value, or -1 if not found.
  */
int linearSearch(int array[], int size, int value);

/*
performs a linear search to find the most frequent element in an integer array.
This function iterates through the given array to count the frequency of each element.
It keeps track of the most frequent element and its count. 
If there are multiple elements with the same highest frequency, it returns the first one encountered.
array is the integer array to search.
size is the number of elements in the array.
Then we return the most frequent element in the array.
*/
char mostFrequent(int array[], int size);

/* 
This function multiplies two arrays based on user inputs of
number of rows in matrix A, number of rows in matrix B, number of columns in B, number of colums in A



*/
void productOfArray(int rowA, int colA, int rowB, int colB, int matrixA[rowA][colA], int matrixB[rowB][colB], int result[rowA][colB]);