#include <stdio.h>

int main() {

    char *digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

     while (num > 0) {
        printf("%s ", digits[num % 10]);
        num = num / 10;
    }
return 0;
}