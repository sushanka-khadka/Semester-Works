// insertion sort

#include<iostream>
using namespace std;

int InsertionSort(int n, int arr[20]){
	int i=0,j=0;
	int temp=0;	
	for (i=1;i<n;i++){
		temp=arr[i];
		for(j=i-1; j>=0 && temp < arr[j]; j--){
			arr[j+1]= arr[j];						
		}				
		arr[j+1] = temp;
		for(int k=0; k<n; k++){
			cout<<arr[k]<<" ";
		}
		cout<<endl;
	}	
	return 0;
} 

int main(){
	int n, arr[20];
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}
	InsertionSort(n, arr);
	return 0;             
}