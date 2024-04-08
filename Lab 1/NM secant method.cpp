#include<stdio.h>
#include<math.h>
int main()
{
	
	float E=0.000046623454,x1,x2,x3,f1,f2;
	printf("Enter the initial point value x1 = ");
	scanf("%f",&x1);
	printf("Enter the initial point value x2 = ");
	scanf("%f",&x2);
	printf("\nFunction is fx = xe^x-cosx ");
	
	for(int i=0;i<=15;i++)
	{
		printf("\nx1 = %f",x1);
		printf("\nx2 =%f",x2);
	f1=x1*exp(x1)-cos(x1);
	f2=x2*exp(x2)-cos(x2);
	printf("\nf1= %f",f1);
	printf("\nf2= %f",f2);
	
	x3=x2-((f2*(x2-x1))/(f2-f1));
	printf("\nx3 = %f",x3);
	
	if((abs((x3-x2)/x3))>E)
	{
		x1=x2;
		x2=x3;
		
	}
	else
	{
		float root=x3;
		printf("\nRoot is : %f ",root);
		break;
	}
}
return 0;
}