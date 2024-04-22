#include <stdio.h>

// Function to compute the derivative of y with respect to x
double derivative(double x, double y) {
    return y - x; // Example ODE: dy/dx = y - x
}

// Fourth-order Runge-Kutta method for solving ODE
double rungeKutta(double x0, double y0, double h, int n) {
    double y = y0;
    double x = x0;
    int i;

    for (i = 0; i < n; i++) {
        double k1 = h * derivative(x, y);
        double k2 = h * derivative(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * derivative(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * derivative(x + h, y + k3);
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4); // Runge-Kutta formula
        x = x + h;
    }

    return y;
}

int main() {
    double x0, y0, h;
    int n;

    // User input
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    // Computing and printing the result
    double result = rungeKutta(x0, y0, h, n);
    printf("Value of y at x = %.2lf is %.6lf\n", x0 + n * h, result);

    return 0;
}
