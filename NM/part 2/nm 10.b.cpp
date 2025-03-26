//10. WAP to implement following for matrix factorization methods 
//b. Cholesky Decomposition. 

//A=LU	U=Lt  A=LLt		L=Ut  A=UtU

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	const int m=3;
	int i,j,k;
	float A[m][m]={{1,4,7},{4,80,44},{7,44,89}};
	float L[m][m],U[m][m];
//	U=Lt
	cout<<string(20,'-')<<"Cholesky Decomposition"<<string(20,'-')<<endl;
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
	cout<<"\nNote: valid for only symmetric matrix, i.e transpose of A is A.\n";
	
	return 0;
}

