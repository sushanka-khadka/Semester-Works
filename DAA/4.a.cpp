// heap sort
/*max heapify
build max heap
heap sort                                                                                                                                                                                                                             
*/

#include<iostream>

using namespace std;

void MaxHeapify(int A[], int i, int n){
	int l, r, max;	
	l= 2*i +1, r= 2*i +2 , max= i;	// binary tree 2*i 
	
	if (l< n && A[l] > A[max])	// left child is greater
		max= l;
	if (r< n && A[r] > A[max])	// right child is greater
		max= r;
	if (max != i){	// node is not the largest (could be left or right child above oprn performed)
		swap(A[i], A[max]);
		MaxHeapify(A, max, n);		// continue heapifying till root node
	}

	for(int z=0; z<n;z++){
			cout<<A[z]<<" ";
	}
	cout<<endl;
}

void BuildMaxHeap(int A[], int n){
	for(int i= n/2 - 1; i>=0; i--){
		MaxHeapify(A, i, n);
		for(int z=0; z<n;z++){
			cout<<A[z]<<" ";
		}	
		cout<<endl;
	}	
}


void HeapSort(int A[], int n){
	BuildMaxHeap(A, n);	// heapify the list initially
	for(int i=n-1; i>=1; i--){	// sort from last leaf (swap last element with root node/ largest )
		swap(A[0], A[i]);
//		n= n-1; 	// last element is sorted(largest)
		
		for(int z=0; z<n;z++){
			cout<<A[z]<<" ";
		}	
		cout<<endl;
		MaxHeapify(A, 0, i);	// needs to be heapifyed after sorting each element (here max=0 root node)
	}
}

int main(){	
//	int n, A[10];
//	cout<<"---------Heap Sort---------"<<endl;
//	cout<<"Enter size of Aay : ";
//	cin>>n;
//	cout<<"Enter Aay: ";
//	for(int i=0; i<n;i++){
//		cin>>A[i];
//	}	
//	cout<<endl;
	int n=10, A[10]= {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

	HeapSort(A, n);
	
	cout<<"sorted Array: ";
	for(int i=0; i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}