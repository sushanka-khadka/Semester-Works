//7. WAP to compute the numerical integration using 
//b. Composite Trapezoidal Rule 

#include<iostream>
#include<math.h>
using namespace std;

//integrate f(x) =(x^3+2) for limit x=2 to 8 using composite trapezodial rule

float func(float x){
	//	return exp(-1*pow(x,3));
	return sqrt(1+x*x);
}
int main(){
	float a=1,b=5;
	float n=8;
	cout<<"\tComposite Trapezodial rule\n";
	cout<<"lower and upper limits:  ";
	cin>>a>>b;
	cout<<"no. of segments:  ";
	cin>>n;
	
	float h=(b-a)/n;
	float x[10];
	for(int i=0;i<=n;i++){
		x[i]= a+i*h;
	}
	
	float com_trapezodial =func(a) + func(b);	
	for(int i=1;i<n;i++){
		com_trapezodial += 2*func(x[i]);	
	}
	com_trapezodial *=h/2;
	cout<<"Interpolation of f(x)= sqrt(1+x*x) is: "<<com_trapezodial<<endl;
	return 0;
} 