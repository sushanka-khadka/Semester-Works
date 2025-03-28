// Min max finding using divide and conquer approach

# include<iostream>
using namespace std;


int MinMax(int arr[20], int low, int high, int min, int max){	
	if (low == high){
		min= max= arr[low];
		return min, max;
	}
	else{
		int mid= (low+high)/2;
		lmin, lmax= MinMax(arr, low, mid, min, max );
		MinMax(arr, mid+1, high, min1, max1);	
				
	}
	
}

int main(){
	int n, arr[20], item;	
	cout<<"---------Min Max Search(Divide and Conquer)---------"<<endl;		
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter array: ";
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}
	
	MinMax(arr,0, n-1);	// list must be sorted
	
	return 0;
}