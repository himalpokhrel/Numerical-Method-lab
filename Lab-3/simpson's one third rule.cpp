//program to implement simpson's 1/3 rule
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int x0,x2;
	float fx0,fx1,fx2,value,h,x1;//x1 is float because it may consits of decimal points
	
	printf("let, f(x)=(1-x^2)^(1/2)");
	printf("\nEnter the value of lower limit = ");
	scanf("%d",&x0);
	printf("\nEnter the value of upper limit = ");
	scanf("%d",&x2);
	fx0=sqrt(1-(x0*x0));
	printf("\nfx0 = %f ",fx0);
	
	fx2=sqrt(1-(x2*x2));
	printf("\nfx2 = %f ",fx2);
	
	h=((x2-x0)/2.0);  //because simpson's 1/3 assumes n=2(2 segments)
	printf("\n h = %f",h);
	
	x1=(x0+h);
	printf("\nx1= %f ",x1);
	fx1=sqrt(1-(x1*x1));
	printf("\nfx1= %f ",fx1);
	value=(h/3)*(fx0+(4*fx1)+fx2);
	printf("\n");
	printf("\nThe value of integration from a = %d to b = % d in a function f(x) = ((1-x^2)^(1/2) = %f",x0,x2,value);
	getch();
	return 0;
	
}