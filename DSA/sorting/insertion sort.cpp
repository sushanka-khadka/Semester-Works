#include<iostream>
//#include<math.h>
using namespace std;

int main(){
	int arr[10]={15,0,12,19,4};
	cout<<"UNsorted array"<<endl;
	for (int i =0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int temp=0;
	for (int i=0;i<5;i++){
		temp=arr[i];
		int j=i-1;
		cout<<"i  "<<i<<"  j "<<j<<"  temp 	"<<temp<<endl;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;			
			cout<<"During sorting "<<endl;
			for (int i =0;i<5;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		arr[j+1]=temp;
	}
	
	
	cout<<"sorted array"<<endl;
	for (int i =0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	
	
	
}