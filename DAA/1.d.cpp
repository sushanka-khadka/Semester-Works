// bubble sort
#include<iostream>
using namespace std;

int BubbleSort(int n, int arr[20]){
	int temp=0;
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i;j++){
			if (arr[j] > arr[j+1]){
				temp= arr[j];
				arr[j]= arr[j+1];
				arr[j+1]= temp;				
			}
		}
		for(int k=0; k<n; k++){
			cout<<arr[k]<<" ";
		}
		cout<<endl;
	}
	return 0;
}



int main(){int arr[20], n, item;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}
	BubbleSort(n,arr);
	return 0;
}