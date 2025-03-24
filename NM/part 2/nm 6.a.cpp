//6. WAP to find the derivative of a tabulated function using  
//a. Newton's Divided Difference Formula 
//b. Newton's Forward Difference Formula 
//c. Newton's Backward Difference Formula

#include<iostream>
#include<iomanip>
using namespace std;

float x[5]={5,6,7,8,9};
float df[5][5]={{10,14.5,19.5,25.5,32}};

//float f[5]={}

//Newton Divided difference

//float x[5]={1.1,2.0,3.5,5.0,7.1};
//float df[5][5]={{0.6981,1.4715,2.1287,2.0521,1.4480}};
//df[0][5]={0.6981,1.4715,2.1287,2.0521,1.4480};

void div_diff(float X){
	int n=sizeof(x)/sizeof(x[0]);

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
//	cout<<" From Newton's divided difference equation : "<<p2;
	
	float term=0,factor=1,first_diff= df[1][0];
	
	for(int i=2;i<n;i++){
		term=0;		
		for(int j=0;j<i;j++){
			factor =1;
			for(int k=0;k<i;k++){				
				if(j!=k){
					factor *= (X-x[k]);
				}
			}
			term += factor;
		}
	first_diff +=  df[i][0]*term;
	}	
	
	cout<<"\nfirst derivative is :	"<<first_diff;	
		
}
	
	
int main(){
	float x;
	cout<<"Enter the value of x:	";
	cin>>x;
	cout<<string(10,'*');
	cout<<"Derivative using Newton divided  diff.";
	cout<<string(10,'*')<<endl;
	div_diff(x);
	
		
cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 6a"<<endl;
	
	return 0;
}



//
//int main(){
//	int n=5;
//	for(int i=2;i<n-1;i++){
//		float factor =1;
//		for(int j=0;j<=n-1;j++){
//			for(int k=0;k<=n-1;k++){
//				if(j!=k){
//					factor *= (x-x[k]);
//				}
//				sum +=ddf[0];
//			}			
//		}		
//	}		
//	return 0;
//}