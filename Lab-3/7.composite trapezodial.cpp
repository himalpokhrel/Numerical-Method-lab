#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
    int x0, xn, h, k, i;
    float value, fx0, fxn, sum = 0;

    //assuming the integrand function ourselves
    printf("let, f(x) = (x^2+2)");
    printf("\nEnter the value of lower limit = ");
    scanf("%d", &x0);
    printf("\nEnter the value of upper limit = ");
    scanf("%d", &xn);
    printf("\nEnter the number of segments = ");
    scanf("%d", &k);
    h = (xn - x0) / k;

    fx0 = (x0 * x0) + 2;
    fxn = (xn * xn) + 2;
    sum = fx0 + fxn;

    float x[k + 1], fx[k + 1];  //do not declare these arrays above;
    for (i = 0; i <= (k - 1); i++) 
	{
        x[i] = (x0 + i * h);
        fx[i] = ((x[i] * x[i]) + 2);
        sum = sum + (2 * fx[i]);
    }
    value = (h / 2.0) * sum;
    printf("Value of integration of given integrand using composite Trapezoidal rule = %f ", value);
    getch();
    return 0;
}
