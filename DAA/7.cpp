// matrix chain multiplication

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MatrixChainOrder(vector <int> &p){
	int n= p.size();
	vector <vector <int>> m(n, vector <int>(n,0));
	for (int len=2; len<n; len++){	
		for(int i=1; i<n-len+1; i++){
			int j=i + len -1;
			m[i][j] = INT_MAX;
			for(int k=i; k<j; k++){
				int a= m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if(a < m[i][j])
					m[i][j] = a;				
			}
		}
	}
	return m[1][n-1];
}

int main(){
	vector <int> p= {1,2,3,4,3};	// 1x2 2x3 3x4 4x3 =1x3
	cout<<"----- Matrix Chain Multiplication -----\n";
	cout<<"Minimum no. of scalar multiplications: "<<MatrixChainOrder(p)<<endl;
	
	return 0;
}