
#include <stdio.h>
#include <math.h>

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return y - x; // Example ODE: dy/dx = y - x
}

// Picard's iterative method
double picard(double x0, double y0, double h, int n) {
    double y = y0;
    double x = x0;
    int i;

    for (i = 0; i < n; i++) {
        y = y0 + h * f(x0, y); // Picard's iteration formula
        x0 += h;
        y0 = y;
    }

    return y;
}

int main() {
    double x0, y0, h;
    int n;

    // User input
    printf("ODE by Using Picard’s method.\n\n");
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter number of iterations: ");
    scanf("%d", &n);

    // Computing and printing the result
    double result = picard(x0, y0, h, n);
    printf("Value of y at x = %.2lf is %.6lf\n", x0 + n * h, result);

    return 0;
}
