//8. Solutions of system of linear equations using some direct methods 
//a) WAP to implement Naive Gauss Elimination Method to solve the system of linear 

//Forward Elimination
//Backward Substition

#include<iostream>
#include<math.h>
using namespace std;

void print_mat(float arr[][3], float cons[3],int m){
	cout<<"Coeff. matrix \t\t"<<"constant"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<"\t";
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
	
//	float mat[m][m]={{20,15,10},{-3,2.249,7},{5,1,3}};		// Division by zero; round off error -> cannot solve by Naive gauss 
//	float cons[m]={45,1.751,9};		// Drawbacks
	
	float mat[m][m]={{2,1,1},{3,2,3},{1,4,9}};		// OK
	float cons[m]={10,18,16};
	

//	cout<<string(35,'-')<<endl;
//	print_mat(mat,cons,m);
	
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
		
	cout<<"\tNaive Gauss Elimination\n";
	cout<<string(45,'-')<<endl;
	cout<<"Coeff. matrix \t\t"<<"constant"<<"  Ans"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<cons[i]<<"\t"<<ans[i]<<endl;
	}
	
	cout<<endl<<string(35,'_')<<endl;
	return 0;
}

/*
Drawbacks
	Division by zero 
	Round off error

Naive ns Parial vs complete 
Naive->> Forward elimination and backward substition
Partial ->. similar to naive except on each remaining rows elemets get compared purpose is to get largest element in the column as pivot
						(rows may gets swapped )
						largest element within the column as pivot

Partial ->. rows and columns  elemets get compared -> purpose is to get largest element in the row as well in column as pivot
						(either rows and columns may gets swapped )
						largest element within the whole matrix as pivot

*/