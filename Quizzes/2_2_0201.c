#include <stdio.h>
#include <stdlib.h>

//helper function to print arrays, do not modify.
void print_array(int *array, int size){
        int i;
        for(i = 0; i < size; i++){
                printf("%d, ", array[i]);
        }
        printf("\n");
}

// complete the following main function to read in integers 
// from user input with dynamic memory allocation.
void main(){
        // Part 1: Read in integers from user input one by 
        // one until you receive a -1. Store these integers 
        // (not including the -1) as an array with the given 
        // pointer using dynamic memory allocation
        // (malloc, realloc or calloc)

        int *arr;
        int size; //store the number of entries in arr here

        printf("Enter integer input, -1 to stop.\n");
        //write code here
        arr = (int *)malloc(sizeof(int));
        size = 0;
        int capacity = 1;
        int input;
        
        while(scanf("%d", &input) == 1 && input != -1){
            if(size == capacity){
                capacity *= 2;
                arr = (int *)realloc(arr, capacity * sizeof(int));
            }
            arr[size] = input;
            size++;
        }

        print_array(arr, size);

        // Part 2: Copy entries from arr with odd indices 
        // (i.e., arr[1], arr[3], ...) to a new array. 
        // The new array should be created using the new_arr 
        // pointer defined below. 
        //                              example: 
        //                              arr = {9 8 7 6 5 4 3} (size 7)
        //                              new_arr = {8 6 4} (size 3)

        int *new_arr;
        int new_size; //store the number of entries in new_arr here

        //write code here
        new_size = 0;
        for(int i = 1; i < size; i += 2){
            new_size++;
        }
        
        if(new_size > 0){
            new_arr = (int *)malloc(new_size * sizeof(int));
            int idx = 0;
            for(int i = 1; i < size; i += 2){
                new_arr[idx] = arr[i];
                idx++;
            }
        } else {
            new_arr = NULL;
        }
        
        free(arr);
        if(new_arr != NULL){
            free(new_arr);
        }

        print_array(new_arr, new_size);
}