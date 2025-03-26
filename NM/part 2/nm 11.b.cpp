 //11. WAP  to solve system of linear equations using 
//b. Doolittle LU Decomposition Method 

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
	float A[m][m]={{3,2,1},{2,3,2},{1,2,3}};
	float B[m]={10,14,14};
//	float mat[m][m]={{25,5,1},{64,8,1},{144,12,1}};
	float L[m][m],U[m][m],X[m],Y[m];

//	float A[m][m]={{2,-1,-1},{-4,6,1},{-4,-2,6}};
	
	
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
				U[i][j] =A[i][j];
				for(k=0;k<=i-1;k++)
					U[i][j] -= L[i][k] *U[k][j];				
			}
			
			else if(i>j){
				L[i][j] =A[i][j];
				for(k=0;k<=j-1;k++)
					L[i][j] -= L[i][k] *U[k][j];
				L[i][j] /= U[j][j];
			}
			
		}
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
	
	cout<<"\tOriginal \t\t\t L\t\t U\n";
	cout<<string(80,'-')<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<A[i][j]<<"\t";
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
	cout<<string(80,'-')<<endl;	
	
	cout<<"\tDoolittle LU Decomposition Method\n";
	cout<<endl<<string(40,'-')<<endl;
	cout<<"Y\t";
	for(i=0;i<m;i++){
		cout<<Y[i]<<"\t";
	}
	cout<<endl<<string(40,'-');
	cout<<"\nSolution : X\t";
	for(i=0;i<m;i++){
		cout<<X[i]<<"\t";
	}
	cout<<endl<<string(40,'-');

	return 0;
}
// 0nly Forward substitution for LY =B
// 0nly backward substitution for UX =Y