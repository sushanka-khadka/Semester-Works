#include<stdio.h>
#define Row 5
#define Col 5

struct SparseMatrix{
	int row,col,val;
};

void mat(int mat[Row][Col],struct SparseMatrix sparse_mat[],int *count){
	for(int i=0;i<Row;i++){
		for(int j=0;j<Col;j++){
			if(mat[i][j] != 0){
				sparse_mat[*count].row=i;
				sparse_mat[*count].col=j;
				sparse_mat[*count].val=mat[i][j];				
				(*count)++;
			}
		}
	}
}

void print_mat(struct SparseMatrix sparse_mat[],int count){
	printf("Sparse Matrix:\n");
	for(int i=0;i<count;i++){
		printf("(%d,%d)=%d\n",sparse_mat[i].row,sparse_mat[i].col,sparse_mat[i].val);
	}
}

void main(){
	int matrix[Row][Col]={
		{1,1,0,0,0},
		{0,0,0,0,5},
		{00,0,0,0,-6},
		{0,0,0,2,0},
		{66,0,0,0,4}
		};
		
		int count;
		
		struct SparseMatrix sparse_mat[Row*Col];	// why row*col ->> if all the elemetns are non zero
		mat(matrix,sparse_mat,&count);
		print_mat(sparse_mat,count);
		
}
