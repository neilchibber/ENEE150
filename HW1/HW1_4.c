#include <stdio.h>

int firstDay = 3;
int daysInMonth = 31;
int dayCount = 1;

int main() {

int i = 0;
printf("     August 2018\n");
printf("Su Mo Tu We Th Fr Sa\n");
for (i = 0; i < firstDay; i++) {
    printf("   ");
}
for (int day = 1; day <= daysInMonth; day++) {
    printf("%2d ", day);
    if ((dayCount + firstDay) % 7 == 0) {
        printf("\n");
    }
    dayCount++;
}

return 0;
}