#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    // Source term function, f(x, y)
    return 2 * (x - x * x + y - y * y);
}

int main() {
    int N; // Number of grid points (excluding boundaries)
    double L; // Length of the domain

    // User input for grid points and domain length
    printf("Enter the number of grid points (excluding boundaries): ");
    scanf("%d", &N);
    printf("Enter the length of the domain: ");
    scanf("%lf", &L);

    double h = L / (N + 1.0); // Grid spacing
    double u[N][N]; // Solution array
    int i, j;

    // Initialize solution array
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            u[i][j] = 0.0;
        }
    }

    // Iterate to solve the Poisson equation using the finite difference method
    int max_iter = 1000; // Maximum number of iterations
    double tol = 1e-6; // Tolerance for convergence
    double diff, sum;
    int iter = 0;

    do {
        diff = 0.0;

        // Update interior points
        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < N - 1; j++) {
                double residual = (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1] - 4 * u[i][j]) / (h * h) - f(i * h, j * h);
                double delta = 0.25 * residual; // Relaxation parameter
                u[i][j] -= delta;
                diff += fabs(delta);
            }
        }

        // Check convergence
        iter++;
    } while (diff > tol && iter < max_iter);

    // Print the solution
    printf("Solution:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.6f\t", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}
