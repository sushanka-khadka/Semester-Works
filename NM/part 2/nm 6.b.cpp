//6. WAP to find the derivative of a tabulated function using  
//b. Newton's Forward Difference Formula 

#include<iostream>
#include<iomanip>
using namespace std;

//float x[5]={10,20,30,40,50};
//float df[5][5]={{0.1736,0.3420,0.5000,0.6428,0.7660}};

//float x[5]={1,1.1,1.2,1.3,1.4};
//float df[5][5]={{7.989,8.403,8.781,9.129,9.451}};
//df[0][5]={0.6981,1.4715,2.1287,2.0521,1.4480};

float x[5]={1,1.2,1.4,1.6,1.8};
float df[5][5]={{0,0.128,0.544,1.296,2.432}};

float fact(int f){
	float fact=1;
	for(int i=1;i<=f;i++){
		fact *= i;
	}
	return fact;
}

void div_diff(float X){
	int n=5;
	float h=x[1]-x[0];
	float s=(X-x[0])/h;
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
			
	float mul=1;
	float p2=df[0][0];
	for(int i=1;i<=n-1;i++){
		mul=1;
		for (int j=0;j<i;j++)	{
			mul *= (s-j)/(j+1);			
		}		
			p2 += df[i][0]*mul;		
	}

	cout<<"h : "<<h<<endl;
	cout<<"s : "<<s<<endl;
	
//	cout<<" From Newton's forward divided difference interpolation : "<<p2<<endl;

	float first_diff= df[1][0], prev_term=1;
	float term_1=0,term_2=0;
	for(int i=2;i<n;i++){
		term_1=1;		
		for(int j=2;j<=i;j++){
			term_1 *= (s-j+2);
			}
			term_2 += (s-i+1) *prev_term;
		prev_term =term_1+term_2;
		first_diff += (df[i][0] *(term_1 +term_2))/fact(i);			
	}
	first_diff /=h;
	
	cout<<"\nfirst derivative is :	"<<first_diff<<endl;	
	
	
}
	
int main(){
	float x;
	cout<<"Enter x: ";
	cin>>x;
	cout<<string(10,'*');
	cout<<"Derivative using Newton Forward diff.";
	cout<<string(10,'*')<<endl;
	div_diff(x);

	cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 6b"<<endl;
	
	return 0;
}
