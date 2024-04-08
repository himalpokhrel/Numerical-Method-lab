#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int k;
	float x0,xn,fx0,fxn,h;
		//assuming the function ourself
	printf("let, f(x)=(x^3)+1");
	
	//taking initial and final end points
		printf("\nEnter the value of lower limit = a = x0 = ");
		scanf("%f",&x0);
		printf("\nEnter the value of upper limit = b = xn  = ");
		scanf("%f",&xn);
		
		//taking the number of segments into the interval[a , b] is divided into
		printf("\nEnter the number of segments into which divided  interval is divided , k = ");
		scanf("%d",&k);
		
		//calculating functional values
		fx0=((x0*x0*x0)+1);
	    printf("\nfx0 = %f ",fx0);
	
		fxn=((xn*xn*xn)+1);
	    printf("\nfxn = %f ",fxn);
	    
	    
	    //computing widht of each interval i.e h;
	    h=((xn-x0)/k);
	    printf("\nh = %f ",h);
	    
	    
	    //computing for f(x1) to f(xn-1) using the logic
	    float sum=fx0+fxn;
	    float x[k+1],fx[k+1]; //array size is one more than intervals 
	    for(int i=1;i<=(k-1);i++) //for goes from f(x1) to f(xn-1) because we already calculated f(x0)+f(xn) 
	    {
	    	x[i]=(x0+i*h);
	    	fx[i]=((x[i]*x[i]*x[i])+1);
	    	if(i%k!=0)
	    	{
	    		sum=(3*fx[i])+sum;
			}
			if(i%k==0)
			{
				sum=(2*fx[i])+sum;
			}
	    	
	    	//arranging according to the formula
	    	float value= ((3.0/8.0)*sum);
	    	printf("\nThe value of integration using composite simpson's 3/8 = %f ",value);
	    	getch();
	    	return 0;
	    	
		}
	    
	    
}