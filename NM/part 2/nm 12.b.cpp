#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
	int n,i,j,k;
	float sum,error,E[10],a[10][10],b[10],new_x[10],old_x[10];
	cout<<"Enter dimensions of system of equations:\n";
	cin>>n;
	cout<<"Enter coefficient row-wise:\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	
	cout<<"Enter B vector:\n";
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	cout<<"Enter accuracy limit:\n";
	cin>>error;
	
	for(i=0;i<n;i++)
		new_x[i]=0;
	while(1){
		for(i=0;i<n;i++){
			sum=b[i];
			for(j=0;j<n;j++){
				if(i!=j)
				sum=sum-a[i][j]*new_x[j];
			}
			old_x[i]=new_x[i];
			new_x[i]=sum/a[i][i];
			E[i]=fabs(new_x[i]-old_x[i])/fabs(new_x[i]);
		}
		for(i=0;i<n;i++){
			if(E[i]>error){
			
				break;
			}
		}
		if(i==n)
		break;
		else
		continue;
	}
	cout<<"\nSolution:\n";
	for(i=0;i<n;i++)
		cout<<setprecision(2)<<new_x[i]<<"\t";
	
	return 0;
}
