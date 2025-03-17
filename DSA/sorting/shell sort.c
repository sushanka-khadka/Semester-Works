// Program to implement shell sort


#include<stdio.h>

void shell_sort(int arr[],int n){
	printf("\nArray before sorting: \n");
	for(int i=0;i<n;i++)
		printf("%d \t",arr[i]);
	
	int j=0;
	for(int inc=n/2;inc>0;inc/=2){
		for(int i =inc;i<n;i++){
			int temp=arr[i];
			for(j=i;j>=inc;j-=inc){
				if(temp <arr[j-inc]){
					arr[j]=arr[j-inc];						
				}
				else{
					break;
				}
			}
			arr[j]=temp;
		}
	}
	printf("\nsorted array\n");
	for(int i=0;i<n;i++)
		printf("%d \t",arr[i]);
}


int main(){
	int A[]={15, 55, 2, 75,15, 44, 64};		
	int n= sizeof(A)/sizeof(A[0]);
	shell_sort(A,n);
	return 0;
}
