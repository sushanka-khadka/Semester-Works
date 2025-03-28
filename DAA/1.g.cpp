//Min and Max finding in a list(minmax algorithm)
#include<iostream>
using namespace std;

int MinMax(int n, int arr[20]){
	int min=arr[0], max=arr[0];
	for (int i=1; i<n; i++){
		if (min > arr[i])
			min= arr[i];
		else if (max < arr[i])
			max= arr[i];
	}
	cout<<"Min no: "<<min<<endl<<"Max no: "<<max;
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
	MinMax(n, arr);	
	
	return 0;
}