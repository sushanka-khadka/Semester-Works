// binary search

#include<iostream>
using namespace std;

int BinSearch(int arr[20], int low, int high, int key){
	if (low == high){	// only one item left
		if (key == arr[low]) return low;	// start form 0
		else return -1;
	}	
	int mid= (low+high)/2;	// integer division
		
	if (key == arr[mid]) return mid;
	else if (key < arr[mid] )return BinSearch(arr, low, mid-1, key);
	else return BinSearch(arr, mid+1, high, key);	
}

int main(){
	int n, arr[20], item;	
	cout<<"---------Binary Search---------"<<endl;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter sorted array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter item to search: ";
	cin>>item;
	int index= BinSearch(arr,0, n-1, item);	// list must be sorted
	if (index >= 0) cout <<"Element found at: "<<index <<"th position";
	else cout<<"Element not found";
	return 0;
}