//7. WAP to compute the numerical integration using 
//c. Simpson's 1/3 Rule 

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
	int n=2;
	cout<<"\tComposite Trapezodial rule\n";
	cout<<"lower and upper limits:  ";
	cin>>a>>b;
	
	float h=(b-a)/n;
	float  x[3]={a,a+h,b};
	float simpson =(func(x[0]) + 4*func(x[1])+func(x[2]))*h/3;
	
	
	cout<<"Interpolation of f(x)=sqrt(1-x*x): "<<simpson;
	
	return 0;
}