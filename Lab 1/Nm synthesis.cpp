#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,ak;
	printf("Enter the order of the polynomial ,n = ");
	scanf("%d",&n);
	int a[n];
	int b[n];
	printf("\nEnter the values of coefficients : ");
	for(i=0;i<=n;i++)
	{
		printf("\nEnter the value of a%d  = ",i);
		scanf("%d",&a[i]);		
	}
	for(i=0;i<=n;i++)
	{
		printf("\n a%d  = %d",i,a[i]);
				
	}
	printf("\nP(x)= %dx^%d+%dx^%d+%dx^%d+%d",a[n-1],n-1,a[n-2],n-2,a[n-3],n-3,a[0]);
    printf("\nEnter the value where to calculate root = ");
    scanf("%d",&ak);
    
    b[n-1]=0;
	while((n-1)>0)
	{
		
		b[n-2]=a[n-1]+ak*b[n-1];	
		printf("\n b = %d",b[n-2]);
		n--;
		
}
printf("  \nRemainder = %d",b[0]);
printf("  \nQuotient  = %dx^%d+%dx^%d+%d = 0",b[n-3],a[n-2],b[n-4],a[n-3],b[0]);
return 0;
}