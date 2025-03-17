// Program to implement SELECTION sort
#include<stdio.h>

int A[]={23,11,4,0,2,12,43,2,4,23};

int main(){
	int n=sizeof(A)/sizeof(A[0]);
	int p=0;
	int min =0;
	
	printf("Un-Sorted Array\n");		
	for(int i=0;i<n;i++)
		printf("%d \t",A[i]);
	printf("\n\n");

	for(int i=0;i<n;i++){
		min = A[i];
		p=i;
		for(int j=i+1;j<n;j++){
			if(min>A[j]){
				min=A[j];
				p=j;
			}
		}
		A[p]=A[i];
		A[i]=min;

		for(int i=0;i<n;i++){
			printf("%d\t",A[i]);
		}
		
		printf("\n");
	}
	
	printf("\n Sorted Array\n");		
		for(int i=0;i<n;i++)
			printf("%d \t",A[i]);
		
		printf("\n\n");
	
	
}