#include <stdio.h>
#include <math.h>

#define N 5 // Number of grid points (excluding boundaries)
#define L 1 // Length of the domain

double f(double x, double y) {
    // Source term function, f(x, y)
    return 2 * (x - x * x + y - y * y);
}

int main() {
    double h = L / (N + 1.0); // Grid spacing
    double u[N+2][N+2]; // Solution array (including boundary)
    double u_new[N+2][N+2]; // Temporary solution array (including boundary)
    int i, j;

    // Initialize solution array
    for (i = 0; i < N+2; i++) {
        for (j = 0; j < N+2; j++) {
            u[i][j] = 0.0;
        }
    }

    // Set boundary conditions
    for (i = 0; i < N+2; i++) {
        u[i][0] = 0.0; // Left boundary
        u[i][N+1] = 0.0; // Right boundary
        u[0][i] = 0.0; // Top boundary
        u[N+1][i] = 0.0; // Bottom boundary
    }

    // Iterate using Jacobi method to solve the Poisson equation
    int max_iter = 1000; // Maximum number of iterations
    double tol = 1e-6; // Tolerance for convergence
    double diff, sum;
    int iter = 0;

    do {
        // Compute new solution using Jacobi iteration
        for (i = 1; i < N+1; i++) {
            for (j = 1; j < N+1; j++) {
                u_new[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - h * h * f(i * h, j * h));
            }
        }

        // Compute maximum difference between old and new solution
        diff = 0.0;
        for (i = 1; i < N+1; i++) {
            for (j = 1; j < N+1; j++) {
                diff = fmax(diff, fabs(u_new[i][j] - u[i][j]));
            }
        }

        // Update solution
        for (i = 1; i < N+1; i++) {
            for (j = 1; j < N+1; j++) {
                u[i][j] = u_new[i][j];
            }
        }

        // Check convergence
        iter++;
    } while (diff > tol && iter < max_iter);

    // Print the solution
    printf("Solution:\n");
    for (i = 1; i < N+1; i++) {
        for (j = 1; j < N+1; j++) {
            printf("%.6f\t", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}
