#include<stdio.h>

//const int myArray[5] = {1,2,3,4,5};		// const means no chane in data so it don't store in RAM

int A[7]={2,45,21,0,3,56,2};
int B[7]={2,45,21,0,3,56,2};
const int n=sizeof(A)/sizeof(A[0]);
int temp=0;

void bubble_front(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(A[i]>A[j]){
				temp=A[j];
				A[j]=A[i];
				A[i]=temp;
			}
		}
		for(int i=0;i<n;i++){
			printf("%d \t",A[i]);
		}
		printf("\n");
	}
		printf("\n Sorted Array\n");		
		for(int i=0;i<n;i++){
			printf("%d \t",A[i]);
		}
		printf("\n\n");
}

void bubble_back(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
//			for(int j=0;j<n;j++){
			if(B[j]>B[j+1]){
				temp=B[j+1];
				B[j+1]=B[j];
				B[j]=temp;
			}
		}
		for(int i=0;i<n;i++){
			printf("%d \t",B[i]);
		}
		printf("\n");
	}
	
	printf("\n Sorted Array\n");
	for(int i=0;i<n;i++){
		printf("%d \t",B[i]);
	}
	printf("\n\n");
}


int main(){		
	printf("Element is reduced from front : sorted from front \n");
	bubble_front();
	printf("Element is reduced from back : sorted from baack \n");
	bubble_back();
	
	
	return 0;
}
