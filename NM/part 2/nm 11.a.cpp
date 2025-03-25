//11. WAP  to solve system of linear equations using 
//a. Matrix inversion method. 
//b. Doolittle LU Decomposition Method 
//c. Cholesky Decomposition Method

#include<iostream>
#include<math.h>
using namespace std;

void print_mat(float arr[][3], float ide[3][3],int m){
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<"\t";
		}
		for(int j=0;j<m;j++){
			cout<<ide[i][j]<<"\t";		
		}
		cout<<endl;
	}
	cout<<string(45,'-')<<endl;		
}
		
int main(){
	const int m=3;
	int i,j;
	float pivot=0, term=0;	

	float mat[m][m]={{2,1,1},{3,2,3},{1,4,9}};		// OK
	float cons[m]={10,18,16};	
	float ide[m][m]={{1,0,0},{0,1,0},{0,0,1}};
	float ans[m];
	
	cout<<"  Matrix Inversion (Gauss Jordan)\n";
	cout<<string(45,'-')<<endl;
	cout<<"Coeff. matrix \t\t"<<"Identity"<<endl;
	print_mat(mat,ide,m);
	
	//Forward Elimination
	for(i=0;i<m;i++){
		pivot = mat[i][i];
		if(abs(pivot)<0.000001)
			cout<<"Method Failed! \n";
		else{
			for(j=i+1;j<m;j++){		// 
				term= mat[j][i] /pivot;		// to make 2 elets of col 1 c almosy i is const (only mmakes a10 and a20 -> 0
				for(int k=0;k<m;k++){
					mat[j][k] -= mat[i][k]*term;
					ide[j][k] -= ide[i][k]*term;
				}
			}
		}
	}
	
	// Backward Elimination	
	for(i=m-1;i>=0;i--){	
		pivot =mat[i][i];
		for(j=i-1;j>=0;j--){	
			term= mat[j][i]/pivot;
			for(int k=m-1;k>=0;k--){	
				mat[j][k] -= mat[i][k]*term;
				ide[j][k] -= ide[i][k]*term;
	 		}
		}
		mat[i][i] /=pivot;
		for(int k=0;k<m;k++){
			ide[i][k] /=pivot;
		}
	}	
	
//	Matrix multiplication
	for(i=0;i<m;i++){
		ans[i]=0;
		for(j=0;j<m;j++){			
				ans[i] += ide[i][j] *cons[j];			
		}
	}
	
	cout<<"Identity matrix \t\t"<<"Inverse Matrix"<<endl;
	print_mat(mat,ide,m);
	cout<<"Answer"<<endl;
	for(i=0;i<m;i++){
		cout<<'\t'<<ans[i]<<endl;
	}

	return 0;
}
