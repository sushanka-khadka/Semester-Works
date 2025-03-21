/* WAP in C to find the roots of following equation using Newton Raphson Method. 
(Take the values of initial guess  and error tolerance from user)   
cos(x)-x.e^x  = 0   */

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float f(float x){
	return cos(x/180) -x*exp(x);
//	return pow(x,2) +4*x -9;
}
float df(float x){
	return -sin(x/180) - exp(x)*(x-1); 	 // derivative of fx
//	return 2*x+4;
}

void Raphson(float x1,float E){
	int iter=1;
	float f1=f(x1);
	float df1=df(x1);			
	float x2= x1- f1 / df1;
	float Er= abs((x2-x1) / x2);	
	
	cout<<left<<setw(5)<<" "<<setw(5)<<"S.N."<<setw(10)<<"x1"<<setw(15)<<"f(x)"<<setw(15)<<"f'(x)"<<setw(15)<<"X(n+1)"<<setw(15)<<"Er"<<endl;
	cout<<left<<setw(4)<<" ";
	for (int i=0;i<85;i++){	
		cout<<"-";
	}
	cout<<endl;
		
	while (Er > E) {
		cout<<left<<setw(5)<<" "<<setw(5)<<iter<<setw(10)<<x1<<setw(15)<<f1<<setw(15)<<df1<<setw(15)<<x2<<setw(15)<<Er<<endl;		
		x1=x2;
		f1=f(x1);
		df1=df(x1);			
		x2= x1- f1 / df1;
		Er= abs((x2-x1) / x2);
		Er= int(Er*10/E) *E/10;
		iter++; // to count the iteratioin no
	}
	cout<<endl<<"Root of eqn is " <<x2<<endl;	
	
}


int main(){
	float x=5;
	float E =0.0009;
	cout<<"enter the x: ";
	cin>>x;
	cout<<"Enter Error Tolorence  ";
	cin>>E;
	
	Raphson(x,E);
	return 0;	
}