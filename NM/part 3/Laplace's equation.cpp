// Partial differentiation method (PDE)
// using finite difference method

#include<iostream>
using namespace std;

int main(){
	int i,j,k,n;
	float sum,error,E[10],a[10][10],b[10],new_x[10],old_x[10],tl,tr,tu,tb;
	cout<<"Enter Dimension of plate\n";
	cin>>n;
	cout<<"Enter temperature at left,right,bottom & top(upper) part of the plate:\n";
	cin>>tl>>tr>>tb>>tu;
	
	
	// construction of Coefficient matrix
	for(i=0;i<=n;i++)
		a[i][i]=-4;
	for(i=0;i<=n;i++)
		a[i][n-i]=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(i!=j && j!= (n-i))
				a[i][j]=1;
		}
	}
	
	// constructon of RHS matrix
	for(i=0;i<=n;i++)
		b[i]=0;
	k=0;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if((i-1)==0)
				b[k]=b[k]-tl;
			if((i+1)==n)
				b[k]=b[k]-tr;
			if((j-1)==0)
				b[k]=b[k]-tb;
			if(j+1==n)
				b[k]=b[k]-tu;
			k++;
		}
	}
	
	cout<<"Enter Accuracy limit:\t";
	cin>>error;
	
	// solving system of linear equations by using Gauss-Seidal method
	for(i=0;i<=n;i++)
		new_x[i]=0;
	while(1){
		for(i=0;i<=n;i++){
			sum=b[i];
			for(j=0;j<=n;j++){
				if(i!=j)
					sum-= a[i][j]*new_x[j];
			}
			old_x[i]=new_x[i];
			new_x[i]=sum/a[i][i];
			E[i]=abs(new_x[i]-old_x[i])/abs(new_x[i]);
		}
		
		for(i=0;i<=n;i++){
			if(E[i]>error)
				break;
		}
			if(i==(n+1))
				break;
			else
				continue;
		}
			
	
	
	cout<<"Solutioin:\n";
	for(i=0;i<=n;i++)
		printf("x%d=%6.2f\n",i+1,new_x[i]);
		
	return 0;
		
			
}