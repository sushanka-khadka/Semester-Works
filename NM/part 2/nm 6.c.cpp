//6. WAP to find the derivative of a tabulated function using  
//c. Newton's Backward Difference Formula

#include<iostream>
#include<iomanip>



using namespace std;

float x[5]={5,6,7,8,9};
float df[5][5]={{10,14.5,19.5,25.5,32}};


//float x[5]={10,20,30,40,50	};
//float df[5][5]={{0.1736,0.3420,0.5000,0.6428,0.7660}};
//df[0][5]={0.6981,1.4715,2.1287,2.0521,1.4480};

float fact(int f){
	float fact=1;
	for(int i=1;i<=f;i++){
		fact *= i;
	}
	return fact;
}


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
	for(int i=1;i<=n-1;i++){
		mul=1;
		for (int j=0;j<i;j++)	{
			mul *= (s+j)/(j+1);			
		}		
			p2 += df[i][n-i-1]*mul;		
	}
	
//	cout<<" From Newton's backward divided difference interpolation : "<<p2<<endl;
	
	float first_diff= df[1][n-2], prev_term=1;
	float term_1=0,term_2=0;
	for(int i=2;i<n;i++){
		term_1=1;		
		for(int j=2;j<i;j++){
			term_1 *= (s-j+2);
			}
			term_2 += (s-i+1) *prev_term;
		prev_term =term_1+term_2;
		first_diff += (df[i][n-i-1] *(term_1 +term_2))/fact(i);			
	}
	first_diff /=h;
	
	cout<<"first derivative is :	"<<first_diff<<endl;	
}
	
	
int main(){
	float x;
	cout<<"Enter x: ";
	cin>>x;

//	system("cls");
	cout<<string(10,'*');
	cout<<"Derivative using Newton Backward diff.";
	cout<<string(10,'*')<<endl;
	
	div_diff(x);
	cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 6c"<<endl;
	
	return 0;
}

