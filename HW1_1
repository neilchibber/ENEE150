#include <stdio.h>

int main() {
    int num1, num2, num3, largest, smallest, middle;
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3) {
        largest = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        largest = num2;
    } else {
        largest = num3;
    }

    if (num1 <= num2 && num1 <= num3) {
        smallest = num1;
    } else if (num2 <= num1 && num2 <= num3) {
        smallest = num2;
    } else {
        smallest = num3;
    }

    middle = (num1 + num2 + num3) - largest - smallest;

    printf("%d %d %d", smallest, middle, largest);
    
    return 0;
}