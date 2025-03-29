// randomized quick sort

#include<iostream>
#include<algorithm>	// for swap()
//#include<cstdlib>
#include<ctime>
using namespace std;

int partition(int arr[20], int l, int r){
	int x= l, y=r, pivot= arr[l], temp;
	while(x<y){
		while(arr[x] <= pivot && x<=r)
			x++;
		while (arr[y] > pivot)
			y--;		
		if(x< y){
			swap(arr[x], arr[y]);
		}		
	}
	// swap pivot and partition the arrray
	swap(arr[l], arr[y]);
	// divided from
	return y;
}

int RandomPartition(int A[], int l, int r){	
	srand(time(0));	// set random seed according to current time	
	int i= l + rand() % (r - l + 1);	// random value with specific range
	
	swap(A[l],A[i]);	
 	// partition with randomized array
	return partition(A, l, r);		
}

void RandomQuickSort(int arr[20], int l, int r){
	if (l < r){		
		int q = RandomPartition(arr, l, r);
		RandomQuickSort(arr, l, q-1);
		RandomQuickSort(arr, q+1, r);
	}
}


int main(){
	int n, arr[20], item;	
	cout<<"---------Randomized Quick Sort---------"<<endl;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}	
	RandomQuickSort(arr, 0, n-1);
	
	cout<<"sorted array: ";
	for(int i=0; i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}