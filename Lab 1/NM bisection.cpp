#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    float x1,x2;
    float f1,f2,f0,x0,xk,E=0.000976562;

    printf("Enter the value of x1 : ");
    scanf("%f",&x1);
    printf("Enter the value of x2 : ");
    scanf("%f",&x2);
    printf("\n");
    printf("The equation is : x^2-4x-10=0\n");
    printf("Let ,   f(x) = x^2-4x-10\n");
    f1=x1*x1-4*x1-10;
    f2=x2*x2-4*x2-10;

    if((f1*f2)>0)
    {
        printf("\nThe root is not contained between %f and %f .",x1,x2);
    }
    else
    {
    	//if(f1*f2<0) then root exists between x1 and x2.
    	for(int i=0;i<15;i++)
    	{  
	 
    		printf("\nx1=%f",x1);
    		printf("\nx2=%f",x2);
    		printf("\n");
    		
    	f1=x1*x1-4*x1-10;
        f2=x2*x2-4*x2-10;
        
        
        printf("\nf1 = %f",f1);
        printf("\nf2 = %f",f2);
        printf("\n");
        
      	if((f1*f2)<0)
          {

            float x0=(x1+x2)/2;
            printf("\nx0 = %f",x0);
            float xk=fabs((x1-x2)/2);
           // printf("\nxk = %f",xk);
            if(xk<=E)
            {   
            printf("\n");
                printf("\nRoot = %f",x0);
                break;
            }

            f0=x0*x0-4*x0-10;
            printf("\nf0 = %f",f0);
            printf("\n");
            if((f0*f1)<0)
            {
                x2=x0;
                //f2=f0;
            }
            else
            {
                x1=x0;
                //f1=f0;
            }
         }
       }   
    }
}

