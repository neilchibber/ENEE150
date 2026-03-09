#include <stdio.h>

struct CAR
    {
        char make[20];
        char model[20];
        int year;
        float price;
    };

int main() {
    struct CAR car1 = {"Toyota", "Prius", 2020, 25000.0};
    
    return 0;
}