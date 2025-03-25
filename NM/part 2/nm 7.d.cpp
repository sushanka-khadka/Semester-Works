//7. WAP to compute the numerical integration using 
//d. Composite Simpson's 1/3 Rule 
//

#include<iostream>
#include<math.h>
using namespace std;


float func(float x){
//	x = 3.14159*x/180;
	if(x==0)
		return 1;
	else
		return sin(3.14159*x/180)/x;	
}

int main(){
	float a=0,b=1;
	int n=4;
	cout<<"\tComposite Simpson's 1/3 rule\n";
	cout<<"lower and upper limits:  ";
	cin>>a>>b;
	cout<<"no. of segments:  ";
	cin>>n;
	
	float h=(b-a)/n;
	float x[10];
	for(int i=0;i<=n;i++){
		x[i]= a+i*h;
	}
	
	float com_simpson =0;
	com_simpson =func(a) + func(b);	
	
	for(int i=1;i<n;i++){
		if(i%2==0)	
			com_simpson += 2*func(x[i]);
		else
			com_simpson += 4*func(x[i]);
	}
	com_simpson *= h/3;
	
	
	cout<<"\nInterpolation of f(x)=sin(x)/x: "<<com_simpson<<endl;
	
	return 0;
}