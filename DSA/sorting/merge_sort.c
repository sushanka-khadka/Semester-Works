#include<stdio.h>

void merge(int A[10],int l, int m, int r){
	int x=l,y=m;
	int k=l;
	int B[10];
	while(x<m && y<=r){
		if(A[x] <A[y]){
			B[k] = A[x];
			k++;	x++;		
		}
		else{
			B[k]=A[y];
			k++;	y++;
		}
	}
	
	while(x<m){
		B[k] = A[x];
		k++;	x++;	
	}
	while(y<=r){
		B[k] = A[y];
		k++;	y++;	
	}
	for(int i=l;i<=r;i++){
		A[i]=B[i];
	}	
}

void merge_sort(int A[10],int l,int r){
	if (l<r){
		int m=(l+r)/2;
		merge_sort(A,l,m);
		merge_sort(A,m+1,r);
		merge(A,l,m+1,r);
	}
	printf("\nSorted array: \n\t");
	for(int i=0;i<=r;i++){
		printf("%d \t",A[i]);
	}
}



int main(){
	int arr[]={15, 55, 2, 75, 192, 15, 44, 64};
	int n = sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr,0,n-1);
	return 0;
}
