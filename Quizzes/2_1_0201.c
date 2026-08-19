#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// complete the following code main function to simulate 
// rolling a die and taking a random sample of the outcomes
int main(){
        // Part 1: fill the following array with 100 
        // random values ranging from 1-6 inclusive.
        // (simulating rolling a 6 sided die 100 times)
        int rolls[100];

        //write code here
        srand(time(NULL));
        for(int i = 0; i < 100; i++){
            rolls[i] = (rand() % 6) + 1;
        }

        // Part 2: take a random sample of the above array 
        // by calculating the mean of SOME of the rolls,
        // where each entry of the array has a 1/4 chance
        // of being included in your calculation of the mean.
        float mean = 0.0;

        //write code here
        int count = 0;
        for(int i = 0; i < 100; i++){
            if((rand() % 4) == 0){
                mean += rolls[i];
                count++;
            }
        }
        if(count>0){
            mean /= count;
        }

        printf("Sampled average: %f\n", mean);
}