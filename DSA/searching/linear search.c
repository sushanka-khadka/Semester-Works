// Sequential searching (LInear Searching)
#include<stdio.h>


int main(){
	int arr[20]	={1,4,7,3,76,6,32,4356,56,86,34,3,434,5,2,6};
	int i,n,key;
	n=sizeof(arr)/sizeof(arr[0]);	
	printf("Enter element to search:");
	scanf("%d",&key);
	
	for(i=0;i<n;i++){
		if(key == arr[i]){
			printf("Element found at position :%d",i);
			break;
		}
	}
	if(i==n){
		printf("End of list:\n search unsuccessful.");
	}
		
	return 0;
}