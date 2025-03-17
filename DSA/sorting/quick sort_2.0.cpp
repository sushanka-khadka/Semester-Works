#include<iostream>
using namespace std;

	void sort(int p,int n,int (&un)[10]){		// array as reference 

		int pivot=un[p+0];
		int start=un[p+1];
		int end=un[n-1];
		int s=p+1,e=n-1;
		int check=0;


	while (true){
		int check=0;
	if(s>e){
		swap(un[e],un[p+0]);				
		check++;
		if (e>1 && n-e>1){		
			sort(0,e,un);		
			sort(e+1,n,un);		
		}
		if (check==2){
			exit(1);
		}
		break;
	}
	if(start>end){
		swap(un[s],un[e]);
		start=un[s];
		end=un[e];
	}
	for (int i=s;i<n;i++){		
		while(un[p+i]<pivot){		 // i++ until it finds element > pivot
			i++;			
		}			
		if(un[p+i]>pivot){
			start=un[p+i];
			s=p+i;			
			break;
		}
	}
	for (int j=e;j>p;j--){
		while(pivot<un[j]){
			j--;
		}		
		if(pivot>un[j]){
			end=un[j];
			e=j;			
			break;
		}		
	}		
	
	bool res=false;
	for (int i=0;i<n;i++){
		if(un[i]>un[i+1]){
			break;
		}
		else{
			res=true;
			continue;
		}
	}
	if(res ==true){
		break;
	}		
	}
	
}
	
	
int main(){
	int arr[10]={11,3,52,4,0,2,23,8,9,25};
	cout<<endl<<endl<<"*********Unsorted array***************"<<endl;	
	for (int i=0;i<10;i++){
		cout<<arr[i]<<"\t";
	}
	sort(0,10,arr);
	cout<<endl<<endl<<"*********sorted array***************"<<endl;	
	for (int i=0;i<10;i++){
		cout<<arr[i]<<"\t";
	}
	return 0;
}

