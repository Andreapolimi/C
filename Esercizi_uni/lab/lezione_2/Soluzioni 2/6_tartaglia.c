#include<stdio.h>

int main(){
	int h,ii,jj;	
	int matrix[10][10]={0};
	do{
		printf("Inserire un valore strettamente positivo e non superiore a 10: ");
		scanf("%d",&h);
	}while(h <= 0 || h > 10);
	
	matrix[0][0]=1;
	for(ii=1;ii<h;ii++){
		matrix[ii][0]=1;
		for(jj=1;jj<h;jj++)
			matrix[ii][jj]=matrix[ii-1][jj-1]+matrix[ii-1][jj];
	}
	for(ii=0;ii<h;ii++){
		for(jj=0;jj<h;jj++)
			printf("%d ",matrix[ii][jj]);
		printf("\n");
	}


	return 0;
}
