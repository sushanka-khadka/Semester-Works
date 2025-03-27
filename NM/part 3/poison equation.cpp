// Poison's Equaton 

#include<iostream>
#include<math.h>
using namespace std;

#define g(x,y) 2*x*x*y*y

int main(){
	int n,i,j,k;
	float sum,error,E[10],a[10][10],b[10],new_x[10],old_x[10],tl,tr,tu,tb,h;
	cout<<"Enter dimension of plate\t";
	cin>>n;
	cout<<"Enter dimension of grid:\t";
	cin>>h;
	cout<<"Enter temperature at left,right,bottom and top(upper) part of plate\n ";
	cin>>tl>>tr>>tb>>tu;
	
	// construction of LHS matrix
	for(i=0;i<=n;i++)
		a[i][i]=-4;
	for(i=0;i<=n;i++)
		a[i][n-i]=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(i!=j && j!= n-i){
				a[i][j]=1;
			}
			
		}
	}
	
	// construction of RHS matrix
	k=0;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++)
			b[k++]=h*h*g(i,j);
	}
	k=0;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(i-1==0)
				b[k]=b[k]-tl;
			if(i+1==n)
				b[k]-=tr;
			if(j-1==0)
				b[k]-=tb;
			if(j+1==n)
				b[k]-=tu;
			k++;				
		}
	}
	
	cout<<"Enter Accuracy limit:\t";
	cin>>error;
	
	// solving System of linear equatoins by Gauss-Seidal Method
	for(i=0;i<=n;i++)
		new_x[i]=0;
	
	while(1){
		for(i=0;i<=n;i++){
			sum=b[i];
			for(j=0;j<=n;j++){
				if(i!=j)
					sum-=a[i][j] *new_x[j];
			}
			old_x[i]=new_x[i];
			new_x[i]=sum/a[i][i];
			E[i]=abs(new_x[i]-old_x[i])/abs(new_x[i]);
		}
		for(i=0;i<=n;i++){
			if(E[i]>error)
				break;
		}
		if(i==n+1)
			break;
		else
			continue;
	}
	
	cout<<"Solution:\n";
	for(i=0;i<=n;i++)
		printf("\tx%d=%7.2f\n",i+1,new_x[i]);
		

	return 0;
}
