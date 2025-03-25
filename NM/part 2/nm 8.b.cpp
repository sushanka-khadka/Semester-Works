//8. Solutions of system of linear equations using some direct methods 
//b) WAP to implement Gauss Elimination with Pivoting Method to solve the system of 
//linear equations and test it. 

//Partial Pivoting
//Complete Pivoting


#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void print_mat(float arr[][3], float cons[3],int m){
	cout<<"Coeff. matrix \t\t"<<"constant"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<setw(10);
		}
		cout<<cons[i]<<endl;		
	}
	cout<<string(35,'-')<<endl;		
}
		
int main(){
	const int m=3;
	int i,j;
	float pivot=0, term=0,sum=0;
	float ans[m];
	
//	float mat[m][m]= {{2,1,1},{4,-6,0},{-2,7,2}};		// OK
//	float cons[m]={5,-2,0};

//	float mat[m][m]={{1,-3,1},{2,-8,8},{-6,3,-15}};		//OK
//	float cons[m]={4,-2,9};
	float swap_mat[m],swap_cons;
	
//	float mat[m][m]={{20,15,10},{-3,2.249,7},{5,1,3}};		// Division by zero; round off error -> cannot solve by Naive gauss 
//	float cons[m]={45,1.751,9};		// Drawbacks
	
	float mat[m][m]={{2,1,1},{3,2,3},{1,4,9}};		// OK
	float cons[m]={10,18,16};
	
//	print_mat(mat,cons,m);
	
	//Forward Elimination
	float larger=0;
	int l=0;
	for(i=0;i<m;i++){
		pivot = mat[i][i];				
		if(abs(pivot)<0.000001)
			cout<<"Method Failed! \n";
		else{
			for(j=i+1;j<m;j++){		// comparison
				if(abs(pivot)<abs(mat[j][i])){														
					larger=mat[j][i];
					l=j;		// row
					pivot=mat[l][i];
				}
			}			
			
			if(abs(pivot) >abs(mat[i][i])){
				for(int q=0;q<m;q++){
					swap_mat[q] =mat[i][q];
					mat[i][q]=mat[l][q];
					mat[l][q]=swap_mat[q];
					
					swap_cons=cons[l];
					cons[l]=cons[i];
					cons[i]=swap_cons;
				}
			}	
			for(j=i+1;j<m;j++){							
				term= mat[j][i] /pivot;		// to make 2 elets of col 1 c almosy i is const (only mmakes a10 and a20 -> 0
				for(int k=0;k<m;k++){
					mat[j][k] -= mat[i][k]*term;
				}
				cons[j] -= cons[i] *term;
			}			
			}	
	}
	ans[m-1] = cons[m-1]/mat[m-1][m-1];	// last elem z from w,x,y,z
		
	// Backward Elimination
	for(i=m-2;i>=0;i--){	
		sum=0;
		for(j=i+1;j<m;j++){
			sum += mat[i][j] *ans[j];
		}
		ans[i] =(cons[i] - sum)/mat[i][i];	// by pivot						
	}	
	
//	cout<<"\nFinal \n";
	cout<<"Gauss Elimination with Partial Pivoting\n";
	cout<<string(45,'=')<<endl;
	cout<<"Coeff. matrix \t\t"<<"constant"<<"  Ans"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<setw(10);
		}
		cout<<cons[i]<<setw(10)<<ans[i]<<endl;
	}
	
	
	return 0;
}
