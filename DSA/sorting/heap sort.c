// Program to implement heap sort

#include<stdio.h>

int largest(int arr[],int n){
	int larger=arr[0];
	for (int i=0;i<n;i++){
		if(arr[i]>larger){
			larger=arr[i];
		}
	}
	return larger;
}
void print_array(int arr[],int n){	
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
}

void heapify(int arr[],int n, int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest != i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
//		swap(arr[i],arr[largest]);
	// recusively heapify
		heapify(arr,n,largest);	
	}
}

void heap_sort(int arr[],int n){		 // n-> no of elements ; i-> root 
	int temp=0;

	for(int i=n/2-1;i>=0;i--)	// i-> root
		heapify(arr,n,i);
	
	for(int i=n-1;i>=0;i--){
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
//		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}	
	printf("\nArray after sorting \n");
	print_array(arr,n);
}


int main(){
	int A[]={23,11,4,0,2,12,43,2,4,23};
	int n=sizeof(A)/sizeof(A[0]);
	printf("Array before sorting \n");
	print_array(A,n);
	heap_sort(A,n);
//	printf("\nArray after sorting \n");
//	print_array(A,n);
	return 0;
}