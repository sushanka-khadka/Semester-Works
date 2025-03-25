//7. WAP to compute the numerical integration using 
//e. Simpson's 3/8 Rule 

#include<iostream>
#include<math.h>
using namespace std;

//integrate f(x) =(x^3+2) for limit x=2 to 8

float func(float x){
//	return pow(x,3)+2;
	return sqrt(1-x*x);
}
int main(){
	float a=0,b=1;
	int n=3;
	cout<<"\tSimpson's 3/8 rule\n";
	cout<<"lower and upper limits:  ";
	cin>>a>>b;
	float h=(b-a)/n;
	float  x[4]={a,a+h,a+2*h,b};
	float simpson =(func(x[0]) + 3*func(x[1])+ 3*func(x[2]) + func(x[3])) *3*h/8;
	
	
	
	cout<<"\nInterpolation of f(x)=sqrt(1-x*x): "<<simpson<<endl;
	
	return 0;
}