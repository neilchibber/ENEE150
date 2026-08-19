#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <a> <num_samples>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int n = atoi(argv[2]);

    if (a <= 1) {
        printf("Error: a must be greater than 1\n");
        return 1;
    }

 
    double x_min = 1.0;
    double x_max = (double)a;
    double y_min = 1.0;
    double y_max = (double)(a * a * a);  

    double box_area = (x_max - x_min) * (y_max - y_min);

    int count = 0;

    srand(42); 

    for (int i = 0; i < n; i++) {
        double x = x_min + (double)rand() / RAND_MAX * (x_max - x_min);
        double y = y_min + (double)rand() / RAND_MAX * (y_max - y_min);

        // Point is inside if x^2 <= y <= x^3
        double x2 = x * x;
        double x3 = x2 * x;

        if (y >= x2 && y <= x3) {
            count++;
        }
    }

    double area = box_area * ((double)count / n);
    printf("Estimated area: %f\n", area);

    double exact = ((double)(a*a*a*a)/4.0 - (double)(a*a*a)/3.0)
                 - (1.0/4.0 - 1.0/3.0);
    printf("Exact area:      %f\n", exact);

    return 0;
}