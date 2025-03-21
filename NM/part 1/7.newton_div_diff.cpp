// WAP to implement Newton's Divided Difference Interpolation and test for some data.  

//x	1/3	 1/4	 1
//f	2	 -1		-7


#include<iostream>
#include<iomanip>

using namespace std;

float x[5]={1.1,2.0,3.5,5.0,7.1};
float df[5][5]={{0.6981,1.4715,2.1287,2.0521,1.4480}};
//df[0][5]={0.6981,1.4715,2.1287,2.0521,1.4480};

void div_diff(float X){
	int n=5;

	for(int j=0;j<n-1;j++){ 	// loop for difff actualy n-1 th diff
		for(int i=0;i<n-1;i++){	
			df[j+1][i]=(df[j][i+1]-df[j][i])/(x[i+j+1]-x[i]);		
		}
}
//	cout<<endl<<endl;
	cout<<left<<setw(5)<<" "<<setw(5)<<"i"<<setw(10)<<"f(i)"<<setw(15)<<"1st div_diff";
	cout<<setw(15)<<"2nd div_diff"<<setw(15)<<"3rd div_diff"<<setw(15)<<"4th div_diff "<<endl<<endl;
	for(int j=0;j<n;j++){ 	
		cout<<setw(5)<<" "<<j<<"   ";
		for(int i=0;i<n-j;i++){			
		cout<<setw(15)<<df[i][j];
		}
		cout<<endl<<endl;
	}	
		
	float mul=1;
	float p2=0;
	for(int i=0;i<=n;i++){
		mul=1;
		for (int j=0;j<i;j++)	{
			mul *=(X-x[j]);			
		}		
			p2 += df[i][0]*mul;		
	}
	cout<<" From Newton's divided difference equation : "<<p2;
	}
	
	
int main(){
	float x;
	cout<<"Enter the value of x:	";
	cin>>x;
	div_diff(x);
	
	return 0;
}

