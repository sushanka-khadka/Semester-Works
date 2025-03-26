//11. WAP  to solve system of linear equations using 
//c. Cholesky Decomposition Method


#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	const int m=3;
	int i,j,k;
//	float A[m][m]={{1,4,7},{4,80,44},{7,44,89}};
	float A[m][m]={{4,10,8},{10,26,26},{8,26,61}};
	float B[m]={44,128,214};
	float L[m][m],U[m][m],X[m],Y[m];
//	U=Lt
	cout<<"\tSystem of Linear Eqn :Cholesky Decomposition"<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			L[i][j]=0;
			U[i][j]=0;
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			if(i>=1 && j==0){
				L[i][0]= A[i][0]/L[0][0];
			}
			else if(i==j){
				L[i][j] = A[i][j];
				for(k=0;k<i;k++){
					L[i][j] -=L[i][k]*L[i][k];
				}
				L[i][j]=sqrt(L[i][j]);
			}
			else if(i>j){	// j>i
				L[i][j] =A[i][j];
				for(k=0;k<j;k++){
					L[i][j] -= L[i][k]*L[j][k];
				}
				L[i][j] /= L[j][j];
			}
		}
	}
	// transpose
	for(i=0;i<m;i++){
		for(j=0;j<m;j++)
		U[i][j]=L[j][i];
	}
	
	
	float sum=0;
	Y[0] =B[0] /L[0][0];
	for(i=1;i<m;i++){
		sum=0;
		for(j=0;j<i;j++){
			sum += L[i][j]* Y[j];
		}
//		Y[i] =(B[i] -sum)/L[i][i];
		Y[i] =(B[i] -sum);  // no need to divide cuz 1
	}
		
			

	// Backward Substitution
	X[m-1] = Y[m-1]/U[m-1][m-1];	// last elem z from w,x,y,z		
	for(i=m-2;i>=0;i--){	
		sum=0;
		for(j=i+1;j<m;j++){
			sum += U[i][j] *X[j];
		}
		X[i] =(Y[i] - sum)/U[i][i];	// by pivot				
	}
	
	
	// 0nly backward elimination for UX =Y	
	
	
	cout<<setw(20)<<right;
	cout<<"A=";
	cout<<setw(20)<<right;
	cout<<"L=\t\t";
	cout<<setw(20)<<right;
	cout<<"U=\n";
	for(i=0;i<m;i++){
		for(j=0;j<m;j++)
			cout<<"\t"<<A[i][j];
		cout<<" |";
		for(j=0;j<m;j++)
			cout<<"\t"<<L[i][j];
		cout<<" |";
		for(j=0;j<m;j++)
			cout<<"\t"<<U[i][j];		
		cout<<" |"<<endl;
	}
	cout<<"\n Answer is :\t"; 
	for(j=0;j<m;j++)
		cout<<"\t"<<X[j];  

	return 0;
}

