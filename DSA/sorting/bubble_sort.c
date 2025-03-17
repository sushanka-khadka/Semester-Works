/*bubble sort
quick sort 
merge sort 
heap sort 
radix sort


linked   list
singly list 
doubly linked list
circular linked list
*/

#include<stdio.h>
void bubble_front(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i])	{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;				
			}
		
		}
	}
}


void bubble_back(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j+1]<arr[j]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

		}
	}
}


int main(){
	int arr[]={45,24,67,2,67,4,678,4,4667,24,24,657,32,4};
	printf("Bubble sort algorithm\n");
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Before Sorting\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
	bubble_back(arr,n);
	
	printf("Before Sorting\n");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
//	bubble_front(arr,n);
	
	return 0;
}