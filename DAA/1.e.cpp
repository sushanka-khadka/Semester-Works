// selection sort
#include<iostream>
using namespace std;

int SelectionSort(int n, int arr[20]){
	int min=0, temp=0;	
	for (int i=0; i<n-1;i++){
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min]){
				min= j;
			}
		}
		temp= arr[i];
		arr[i]= arr[min];
		arr[min]= temp;
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
	SelectionSort(n, arr);
	return 0;             
}