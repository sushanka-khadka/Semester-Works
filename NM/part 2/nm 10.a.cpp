   //10. WAP to implement following for matrix factorization methods  
//a. Doolittle's methods 
//b. Cholesky Decomposition. 

// Doolittle LU Decomposition

#include<iostream>
using namespace std;
		
/*
A=lU
AX=B
LUX=B
LY=B	->>Y=UX
first find Y   */


int main(){
	const int m=3;
	int i,j,k;
//	float mat[m][m]={{3,2,1},{2,3,2},{1,2,3}};
	float mat[m][m]={{25,5,1},{64,8,1},{144,12,1}};
	float L[m][m],U[m][m];

//	float mat[m][m]={{2,-1,-1},{-4,6,1},{-4,-2,6}};
	
	
	// lower triangular 
	
	for(i=0;i<m;i++){		
		for(j=0;j<m;j++){		
			if(i==j)
				L[i][j]=1;
			else if(i<j)
				L[i][j]=0;	
			else
				U[i][j]=0;
		}
	}			
			
	// Upper triangular 
	for(i=0;i<m;i++){		
		for(j=0;j<m;j++){			
			
			if(i<=j){
				U[i][j] =mat[i][j];
				for(k=0;k<=i-1;k++)
					U[i][j] -= L[i][k] *U[k][j];				
			}
			
			else if(i>j){
				L[i][j] =mat[i][j];
				for(k=0;k<=j-1;k++)
					L[i][j] -= L[i][k] *U[k][j];
				L[i][j] /= U[j][j];
			}
			
		}
	}
	
	cout<<"\tDoolittle LU Decomposition\n";
	cout<<"\tA \t\t\t L\t\t U\n";
	cout<<string(80,'-')<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<"||";
		for(int j=0;j<m;j++){
			cout<<L[i][j]<<"\t";
		}
		cout<<"||";
		for(int j=0;j<m;j++){
			cout<<U[i][j]<<"\t";
		}
		cout<<endl;
	}

	return 0;
}