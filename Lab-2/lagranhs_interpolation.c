#include<stdio.h>
double func(double c,double x[],double y[],int n){
	int i,j;
	double res2=0;
	for(i=0;i<n;i++){
		double res=1;
		for(j=0;j<n;j++){
			if(i!=j){
		res=res*((c-x[j])/(x[i]-x[j]));
	}
}
	res2=res2+(y[i]*res);
	printf("%lf\n",res2);
}
return res2;
}
int main(){
	int i,n;
	double x, b[50],a[50],result;
	printf("Enter the total no. of data to enter  ;\n");
	scanf("%d", &n);
	printf("Enter the data of x:\n");
	for(i=0;i<n;i++){
	scanf("%lf",&a[i]);
	}//values of x
	printf("Enter the data of f(x)");
	for(i=0;i<n;i++){
	scanf("%lf",&b[i]);//values of y
}
	printf("Enter the value of x at which you want to find the value y: ");
	scanf("%lf",&x);
	result=func(x,a,b,n);
	printf("The value of f(x) at the given value of x=%lf is %lf",x,result);
	return 0;
}
