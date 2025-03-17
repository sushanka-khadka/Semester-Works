// Program to implement radix sort
#include<stdio.h>

void print_array(int arr[],int n){	
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
}

void radix_sort(int arr[], int n){
	int rem,NOP=0;
	int largest=arr[0];
	for(int i=1;i<n;i++){		
		if(largest<arr[i])
			largest=arr[i];
	}

	
	while(largest >0){		// no of digits in largest no
		largest /=10;
		NOP++;
	}
	
	int bucket_count[10];
	int bucket[10][10];
	int div=1;
	
	for(int pass=0;pass<NOP;pass++){
		for(int i=0;i<10;i++)
			bucket_count[i] =0;
		
		rem=0;
		for(int i=0;i<n;i++){
			rem= (arr[i]/div) %10;
			
			bucket[rem][bucket_count[rem]]=arr[i];
			bucket_count[rem] +=1;
//			bucket_count[rem]++;
		}
		int k=0;
		for(int i=0;i<10;i++){
			for(int j=0;j<bucket_count[i];j++){
				arr[k]=bucket[i][j];
				k++;
			}
		}
	div *=10;
	}
	printf("\n\nArray after sorting \n");
	print_array(arr,n);
	
}


int main(){
	int A[]={15, 55, 2, 75,15, 44, 64};
	int n=sizeof(A)/sizeof(A[0]);
	printf("Array before sorting \n");
	print_array(A,n);
	radix_sort(A,n);
//	printf("\n\nArray After sorting \n");
//	print_array(A,n);
}