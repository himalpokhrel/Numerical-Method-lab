#include <stdio.h>

// Function to calculate the derivative of y with respect to x
double derivative(double x, double y) {
    return y - x; // Example ODE: dy/dx = y - x
}

// Function to calculate factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to compute Taylor series
double taylorSeries(double x0, double y0, double h, int n) {
    double y = y0;
    double x = x0;
    int i;

    for (i = 1; i <= n; i++) {
        y += (h / factorial(i)) * derivative(x, y); // Taylor series approximation
        x += h;
    }

    return y;
}

int main() {
    double x0, y0, h;
    int n;

    // User input
    printf("Ode Using Tylor series\n\n");
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter number of iterations: ");
    scanf("%d", &n);

    // Computing and printing the result
    double result = taylorSeries(x0, y0, h, n);
    printf("Value of y at x = %.2lf is %.6lf\n", x0 + n * h, result);

    return 0;
}
