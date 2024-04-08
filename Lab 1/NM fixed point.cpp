#include<stdio.h>
#include<math.h>
int main()
{
	float x0,x1,E=0.000;
	printf("The given equation is : ");
	printf("\n    cosx = 3x - 1");
	printf("\nor, x = (cosx + 1)/3\n");
	printf("\nEnter the initial guess value = ");
	scanf("%f",&x0);
	for(int i=0;i<=15;i++)
	{
		printf("\n");
		printf("\nThe %dth approximation is : ",i);
		printf(" \nx =%f ",x0);
		x1=((cos(x1)+1)/3);
		if((abs((x1-x0)/x0))<=E)
		{
			printf("\n");
			printf("The required Root = %f ",x1);
			break;
		}
		else
		{
			x0=x1;
		}
	}
	return 0;
}