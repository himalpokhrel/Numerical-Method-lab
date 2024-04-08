//program to implement simpson's 3/8 rule
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int x0,x3;
	float x1,x2,fx0,fx1,fx2,fx3,h;
	
	//assuming the function ourself
	printf("let, f(x)=(x^3)+1");
		printf("\nEnter the value of lower limit = a = x0 = ");
		scanf("%d",&x0);
		printf("\nEnter the value of upper limit = b = x3  = ");
		scanf("%d",&x3);
		fx0=((x0*x0*x0)+1);
	    printf("\nfx0 = %f ",fx0);
	
		fx3=((x3*x3*x3)+1);
	    printf("\nfx3 = %f ",fx3);
	    
	    //computing interval width 'h'
	    h=(x3-x0)/3.0;  //instead of 3 , we write 3.0 so that h will give us floating point value instead of integer
	    printf("\nh= %f ",h);
	    //computing for x1 and x2
	    x1=(x0+1*h);
	    fx1=(((x1*x1*x1)+1));
	    printf("\nfx1 = %f ",fx1);
	    
	    x2=(x0+2*h);
	    fx2=((x2*x2*x2)+1);
	    printf("\nfx2 = %f ",fx2);
	    
	    //calculating the value of integration
	    float value=((3.0/8.0)*h)*(fx0+((3*fx1)+(3*fx2))+fx3); //3.0 and 8.0 to ensure that division is done in floating point arithmetic
	    
	    
	    //Displaying the final integration value
	    printf("\nThe integration value using simpson's 3/8 rule = %f ",value);
	    
	    getch();
	    return 0;
	 	    
}