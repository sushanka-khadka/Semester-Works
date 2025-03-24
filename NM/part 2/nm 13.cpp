//13. WAP to find the eigenvalue and eigenvector of a matrix using Power Method.

#include<iostream>
using namespace std;


int main(){
	int m=3,n=15;
	
	float A[m][m]={{2,3,2},{4,3,5},{3,2,9}};
	float X_old[m]={1,1,1}; 	// eigen vector initial approximation
	
//	float A[m][m]={{1,2,0},{2,1,0},{0,0,-1}};
//	float X_old[m]={0,1,0}; 
	
	float E=0.001,E_cal=1,X_eig[m],Y[m];
	float k=0; // eigen value 
	cout<<"Enter max no of iteration: ";
	cin>>n;
	cout<<"Enter error tolorence: ";
	cin>>E;
	
	
//	Y=AX		matrix multiplication
//	x_eig-x_old <= error 0r iter >max ->>  return eigen value(k) and eigen_vector(x)
	
	int iter=1;
	while(iter<=n && E_cal>E){
		for(int i=0;i<m;i++){		
			Y[i] =0;
			for(int j=0;j<m;j++){
				Y[i] += A[i][j]*X_old[j];
			}
		}
		k=abs(Y[0]);		// largest(in magnitude) ->> eigen value
		for(int i=1;i<m;i++){
			if(k<abs(Y[i]))
				k=abs(Y[i]);
		}
		for(int i=0;i<m;i++)
			X_eig[i] =Y[i] /k;		
		E_cal =abs(X_eig[0] -X_old[0])/X_eig[0];		
		for(int i=0 ;i<m;i++)
			X_old[i] =X_eig[i];		
		iter ++;
	}
		
	cout<<"Eigen value: "<<k<<endl<<"Eigen vector\n";
	for(int i=0;i<m;i++){
		cout<<"\t"<<X_old[i]<<endl;
	}
	cout<<endl;
	
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 13(Power Method)"<<endl;
	return 0;
}


//determinant of 3*1 or 1*3 matrix is the first element of the matrix 



//A=[a1,a2,a3]T
//The determinant of a 1D matrix is simply the value of the single element in the matrix. Therefore, the determinant of matrix (A) is:
//Determinant(A)=a1

/*
	cout<<"A\n";
	print_mat(A,3);
	cout<<"X_old\n";
	print_eig(X_old,3);
	cout<<"Eigen value: "<<k<<endl;
	cout<<"X_eig\n";
	print_eig(X_eig,3);


void print_eig(float X[3],int m){
	for(int i=0;i<m;i++){
		cout<<X[i]<<endl;
	}
}
void print_mat(float mat[3][3],int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}
	
*/
