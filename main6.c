#include <stdio.h>
#include <math.h>

double f(double x) {
    if (x > -1 && x <= 0) {
        return 2 * sin(x);
    } else if (x > 0 && x < 10) {
        return (x*x + 3*x) / ((x + 1)*(x + 2));
    } else {
        return sqrt(x*x + 5);
    }
}

int main() {
    double a, b, dx, x, y;
    FILE *file;

    printf("Enter a (start): ");
    scanf("%lf", &a);
    printf("Enter b (end): ");
    scanf("%lf", &b);
    printf("Enter dx (step): ");
    scanf("%lf", &dx);

    file = fopen("output.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    for (x = a; x <= b; x += dx) {
        y = f(x);
        fprintf(file, "%lf\t%lf\n", x, y);
    }

    fclose(file);
    printf("Results saved to output.txt\n");
    return 0;
}
