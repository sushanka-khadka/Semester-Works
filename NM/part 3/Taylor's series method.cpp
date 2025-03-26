#include<iostream>
using namespace std;

int fact(int n){
	if(n==1)
		return 1;
	else
		return (n*fact(n-1));
}

int main(){
	float x,x0,yx0,yx,fdy,sdy,tdy;
	cout<<"Enter initial values of x & y\t";
	cin>>x0>>yx0;
	cout<<"Enter x to which function to be evaluated at:\t";
	cin>>x;
	
	fdy=x0-yx0*yx0;	 // 1st derivative (given function)
	sdy=1-2*yx0*fdy;	// 2nd derivative
//	tdy=fxx+2ffxy+f2fyy+fxfy+ff2y
	tdy=-2*fdy*fdy-2*yx0*sdy;	// 3rd derivative
	
	yx=yx0+(x-x0)*fdy +(x-x0)*(x-x0)*sdy/fact(2) +(x-x0)*(x-x0)*(x-x0)*tdy/fact(3);
	
	printf("Function value at x=%.2f is: %6f\n\n",x,yx);
		
	return 0;	
}
