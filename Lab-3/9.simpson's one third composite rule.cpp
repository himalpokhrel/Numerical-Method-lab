//program to implement composite simpson's 1/3 rule
#include<stdio.h>
#include<conio.h>
#include<math.h>
//#include<wchar.h>  // to handle international characters like (@ )
int main()
{
	int x0,xn,k;
	float fx0,fxn,h,value;
		printf("let, f(x)=(1-x^2)^(1/2)");
		printf("\nEnter the value of lower limit = x0 = ");
		scanf("%d",&x0);
		printf("\nEnter the value of upper limit = xn = xk = ");
		scanf("%d",&xn);
		printf("\nEnter the number of segments , the interval is divided into = k = ");
		scanf("%d",&k);
		
		//computing functional values
		
		fx0=sqrt(1-(x0*x0));
	    printf("\nfx0 = %f ",fx0);
	
		fxn=sqrt(1-(xn*xn));
	    printf("\nfxn = %f ",fxn);

		h=(xn-x0)/(k*1.00);
		printf("\nh = %f ",h);
		float x[k+1],fx[k+1];
		float sum=fx0+fxn;
		for(int i=1;i<=(k-1);i++) // loop to (k-1) because we need to sum from f(x1) to f(x(n-1));
		{
			x[i]=(x0+i*h);
			fx[i]=(sqrt(1-(x[i]*x[i])));
			if(i%2!=0)
			{
				sum=4*fx[i]+sum;  //if í is odd then multiply f[xi] with 4 and add to sum;
			}
			if(i%2==0)
			{
				sum=2*fx[i]+sum;  //if i is even then multiply f[xi] with 2 and add to sum;
			}
		}
		value=(h/3)*sum;
		printf("\nThe value of integration = %f ", value);
		getch();
		return 0;
}
