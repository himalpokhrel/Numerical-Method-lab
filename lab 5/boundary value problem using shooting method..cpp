#include <stdio.h>
#include <math.h>

// Function representing the second-order ODE: y'' = f(x, y, y')
double f(double x, double y, double yp) {
    return -2 * yp / x - y; // Example ODE: x^2 y'' - 2xy' - y = 0
}

// Function implementing the Runge-Kutta method for solving ODEs
void rungeKutta(double x0, double y0, double yp0, double h, double target, double* y_out, double* yp_out) {
    double x = x0;
    double y = y0;
    double yp = yp0;

    while (x < target) {
        double k1 = h * yp;
        double l1 = h * f(x, y, yp);
        double k2 = h * (yp + 0.5 * l1);
        double l2 = h * f(x + 0.5 * h, y + 0.5 * k1, yp + 0.5 * l1);
        double k3 = h * (yp + 0.5 * l2);
        double l3 = h * f(x + 0.5 * h, y + 0.5 * k2, yp + 0.5 * l2);
        double k4 = h * (yp + l3);
        double l4 = h * f(x + h, y + k3, yp + l3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        yp += (l1 + 2 * l2 + 2 * l3 + l4) / 6.0;
        x += h;
    }

    *y_out = y;
    *yp_out = yp;
}

// Function to perform the shooting method
double shooting(double x0, double y0, double yp0_guess, double h, double target, double y_target, double tol) {
    double y, yp;
    double err;
    int max_iter = 1000;
    int iter = 0;

    do {
        rungeKutta(x0, y0, yp0_guess, h, target, &y, &yp); // Solve the IVP

        err = y - y_target; // Calculate error

        // Adjust initial conditions using simple linear interpolation
        yp0_guess -= err / yp;
        iter++;

        if (iter >= max_iter) {
            printf("Shooting method did not converge.\n");
            break;
        }
    } while (fabs(err) > tol);

    return yp0_guess; // Return the initial condition for y'
}

int main() {
    double x0, y0, x1, y1, tol; // Initial and target x, initial and target y, tolerance
    double h = 0.01; // Step size
    double yp0_guess = 1.0; // Initial guess for y'

    // User input for initial and target values, and tolerance
    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);
    printf("Enter the target value of x: ");
    scanf("%lf", &x1);
    printf("Enter the target value of y: ");
    scanf("%lf", &y1);
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tol);

    // Perform shooting method to find the initial condition for y'
    double yp0 = shooting(x0, y0, yp0_guess, h, x1, y1, tol);

    // Solve the ODE using the found initial condition for y'
    double y, yp;
    rungeKutta(x0, y0, yp0, h, x1, &y, &yp);

    // Print the result
    printf("Solution at x = %.2f: y = %.6f, y' = %.6f\n", x1, y, yp);

    return 0;
}
