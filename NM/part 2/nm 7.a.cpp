//7. WAP to compute the numerical integration using 
//a. Trapezoidal Rule 
//b. Composite Trapezoidal Rule 
//c. Simpson's 1/3 Rule 
//d. Composite Simpson's 1/3 Rule 
//e. Simpson's 3/8 Rule 
//f. Composite Simpson's 3/8 Rule 
//g. Gauss Legendre two point and three point  formula   
//h. Romberg integration formula


#include<iostream>
#include<math.h>
using namespace std;

//integrate f(x) =(x^3+2) for limit x=2 to 8

float func(float x){
	return pow(x,3)+2;
}
int main(){
	float a=2,b=8;
	float n=1;
	float h=(b-a)/n;
	
	float trapezodial =(func(a)+func(b))*h/2;
	cout<<"\tTrapezodial rule\n";
	cout<<"Interpolation of f(x) =(x^3+2) at[2,4] is: "<<trapezodial;
	
	cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 7a"<<endl;
	
	return 0;
}