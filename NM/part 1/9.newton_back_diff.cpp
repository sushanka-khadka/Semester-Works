//WAP to implement Newton's Backward Difference Interpolation and test for some data.  

	//x	10		20		30		40		50	
	//f	0.1736	0.3420 	0.5000 	0.6428 	0.7600

#include<iostream>
#include<iomanip>

using namespace std;

float x[5]={10,20,30,40,50	};
float df[5][5]={{0.1736,0.3420,0.5000,0.6428,0.7660}};
//df[0][5]={0.6981,1.4715,2.1287,2.0521,1.4480};

void div_diff(float X){
	int n=5;	
for(int j=0;j<n-1;j++){ 	// loop for difff actualy n-1 th diff
	for(int i=0;i<n-1;i++){	
		df[j+1][i]=(df[j][i+1]-df[j][i]);
	}
}
	cout<<left<<setw(5)<<" "<<setw(5)<<"i"<<setw(10)<<"f(i)"<<setw(15)<<"1st diff";
	cout<<setw(15)<<"2nd diff"<<setw(15)<<"3rd diff"<<setw(15)<<"4th diff "<<endl<<endl;
	for(int j=0;j<n;j++){ 	
		cout<<setw(5)<<" "<<j<<"   ";
		for(int i=0;i<n-j;i++){			
		cout<<setw(15)<<df[i][j];
		}
		cout<<endl<<endl;
	}	
			
	float h=x[1]-x[0];		// common difference 
	cout<<"h : "<<h<<endl;
	float s=(X-x[n-1])/h;		// from last element 
	cout<<"s : "<<s<<endl<<endl;
	float mul=1;
	float p2=df[0][n-1];		// accessing last element 
//	cout<<p2<<endl;
	for(int i=1;i<=n-1;i++){
		mul=1;
		for (int j=0;j<i;j++)	{
			mul *= (s+j)/(j+1);			
		}		
			p2 += df[i][n-i-1]*mul;		
	}

	
	cout<<" From Newton's back divided difference interpolation : "<<p2<<endl;
}
	
int main(){
	float x;
	cout<<"Enter x: ";
	cin>>x;
	div_diff(x);
	
	return 0;
}

