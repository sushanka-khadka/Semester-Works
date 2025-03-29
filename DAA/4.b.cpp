//quick sort

#include<iostream>
using namespace std;

int  partition(int arr[20], int l, int r){
	int x= l, y=r, pivot= arr[l], temp;
	while(x<y){
		while(arr[x] <= pivot && x<=r)
			x++;
		while (arr[y] > pivot)
			y--;		
		if(x< y){
			temp= arr[x];
			arr[x]= arr[y];
			arr[y] =temp;
		}		
	}
	// swap pivot and partition the arrray
	arr[l]= arr[y];
	arr[y] = pivot;
	// divided from
	return y;
}

void QuickSort(int arr[20], int l, int r){	
	if (l < r){
		int q = partition(arr, l, r);
		QuickSort(arr, l, q-1);
		QuickSort(arr, q+1, r);
	}	
}

int main(){
	int n, arr[20], item;	
	cout<<"---------Quick Sort---------"<<endl;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}	
	QuickSort(arr, 0, n-1);
	
	// print sorted array
	for(int i=0; i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}