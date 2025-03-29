//merge sort

#include<iostream>
using namespace std;

void Merge(int A[20], int low, int mid, int high){	
	int B[20], i= low, j= mid+1;
	for(int k=low; k<=high; k++){
		if(j > high)
			B[k]= A[i++];
		else if(i > mid)
			B[k]= A[j++];
		else if(A[i] < A[j])	
			B[k]= A[i++];
		else B[k] = A[j++];		
	}
	for(i=low; i<=high; i++){
		A[i]= B[i];
	}
}

void MergeSort(int arr[20], int low, int high){
	if (low < high){
		int mid= (low+high)/2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		Merge(arr, low, mid, high);			
	}
}



int main(){
	int n, arr[20];
	cout<<"---------Merge Sort---------"<<endl;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}	

//	n= 5;
//	arr= [38, 27, 43, 3, 9, 82, 10];
	MergeSort(arr, 0, n-1);
	// Print sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}