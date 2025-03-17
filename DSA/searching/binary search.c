// Binary Search
#include<stdio.h>

int key;

int bin_search(int arr[],int l,int r) {
//	if(l<r)	
	int flag;
	int m=(l+r)/2;
	if(key==arr[m]) {
//		printf("Element found at : %d",m);
		flag= m;
		return flag;
//			return m;
	} else if(key<arr[m]) {
		printf("Element at left sub-tree:\n");
		bin_search(arr,l,m-1);
	}
	else {	
		bin_search(arr,m+1,r);
	}
//	printf("Returnedsf fkag:  %d \n\n",flag);
//	return flag;
}


int main() {
//	int arr[20]= {0,1,2,3,4,5,6,7,8,9,10,11};
	int arr[20]= {10,20,30,40,50,60,70,75,80,90};
	int i,n,flag=0;
	n=sizeof(arr)/sizeof(arr[0]);
	printf("Enter element to search:");
	scanf("%d",&key);

	flag=bin_search(arr,0,n-1);
	if(flag == -1)
		printf("Search Unsuccessful!\n");
	else {
		printf("Element found at :%d\n",flag);
	}

	return 0;
}

/*Drawbacks of Binary Search
	Only for sorted array
	array needs to be sorted already
	divide until one element
*/
