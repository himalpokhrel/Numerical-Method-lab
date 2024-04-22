#include <stdio.h>
#define MAX_COLS 4
void printmatrix(double matrix[][MAX_COLS],int rows,int cols){
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		printf("%f\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void gauss_jordan(double matrix[][MAX_COLS],int rows,int cols){
	for (int i=0;i<rows;i++){
		double pivot=matrix[i][i];
		for (int j=0;j<cols;j++){
			matrix[i][j]/=pivot;
		}
		for(int k=0;k<rows;k++){
			if(k!=i){
				double factor=matrix[k][i];
				for (int j=0;j<cols;j++){
					matrix[k][j]-=factor*matrix[i][j];
				}
			}
		}
	}
}
int main(){
	int rows=3;
	int cols=4;
	double matrix[3][4]={{9,-2,-1,26},{-8,-1,-4,-5},{-5,-1,-2,-3}};
		printf("gauss jordan method\n\n");
	printf("Original matrix:\n");
	printmatrix(matrix,rows,cols);
	gauss_jordan(matrix,rows,cols);
	for(int i=0;i<rows;i++){
		printf("x%d=%f\n",i+1,matrix[i][cols-1]);
	}
	return 0;
}
