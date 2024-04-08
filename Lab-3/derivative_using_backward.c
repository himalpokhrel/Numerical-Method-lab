#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("derivative using backward difference formula\n\n");
    // Arrays to store input data
    float x[20], y[20][20], xp, h, sum = 0.0, first_derivative, term;
    int i, j, n, index, flag = 0;

    // Prompt for number of data points
    printf("Enter number of data: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // Prompt for calculation point
    printf("Enter at what value of x you want to calculate derivative: ");
    scanf("%f", &xp);

    // Check if calculation point is valid
    for (i = 0; i < n; i++)
    {
        if (fabs(xp - x[i]) < 0.0001)
        {
            index = i;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Invalid calculation point. Program exiting...");
        exit(0);
    }

    // Generating Backward Difference Table
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j > i - 1; j--)
        {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // Calculate finite difference
    h = x[1] - x[0];

    // Calculating derivative using backward difference formula without pow
    term = 1;
    for (i = 1; i <= index; i++)
    {
        term *= y[index][i];
        term /= i;
        sum += term;
    }

    // Dividing by h to get the derivative
    first_derivative = sum / h;

    // Displaying result
    printf("First derivative at x = %0.2f is %0.2f\n", xp, first_derivative);

    return 0;
}

