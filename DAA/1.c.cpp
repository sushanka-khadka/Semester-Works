// sequential search

#include<iostream>
using namespace std;

int SeqSearch(int n, int arr[20], int key){
	for(int i=0; i<n; i++){
		if (arr[i] == key){
			cout<<key<<" found at "<<i<<"th position";
			return 0;
		}		
	}
	cout<<"Item not found.";
	return 0;	
}

int main(){
	int arr[20], n, item;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter number to search: ";
	cin>>item;
	SeqSearch(n, arr, item);
	
	return 0;
}