#include<stdio.h>
#include<math.h>
int main()
{
	float x0,x1,f0,ff0,E=0.0000;
	printf("Enter the value of initial point x0 = ");
    scanf("%f",&x0);
    
    printf("\n");
    printf("The equation is : cosx = 2x\n");
    printf("Let ,   f(x) = cosx-2x\n");
    
    for(int i=0;i<=15;i++)
    {
    
   printf("\n");
	printf("\nThe %d th approximation is : ",i);
		
    f0=cos(x0)-2*x0;
    ff0=-sin(x0)-2;
    printf("\nx = %f",x0);
    printf("\nf0  = %f",f0);
    printf("\nff0 = %f",ff0);
    
	x1=x0-(f0/ff0);
	printf("\n");
//	printf("\nx1 = %f",x1);
	if((abs((x1-x0)/x0))<=E)
	{
		printf("\n");
		printf("\nThe required root = %f",x1);
		break;
	}
	else
	{
		x0=x1;
	}
}
    return 0;
}