#include <stdio.h>

int main() {

    char *digits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    void printDigits(int num) {
        if (num == 0) {
            return;
        }

        printDigits(num / 10);
        printf("%s ", digits[num % 10]);
    }

    printDigits(num);

return 0;
}