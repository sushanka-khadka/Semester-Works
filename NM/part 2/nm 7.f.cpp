//7. WAP to compute the numerical integration using 
//f. Composite Simpson's 3/8 Rule

#include<iostream>
#include<math.h>
using namespace std;


float func(float x){
	return 1/(x+4);	
}
int main(){
	float a=0,b=3;
	int n=9;
	cout<<"\t Composite Simpson's 3/8 rule\n";
	cout<<"lower and upper limits:  ";
	cin>>a>>b;
	cout<<"no. of segments:  ";
	cin>>n;
	
	float h=(b-a)/n;
	float x[10];
	for(int i=0;i<=n;i++){
		x[i]= a+i*h;
	}
	
	float com_simpson =func(a) + func(b);	
	for(int i=1;i<n;i++){
		if(i%3==0)	
			com_simpson += 2*func(x[i]);
		else
			com_simpson += 3*func(x[i]);
	}
	com_simpson *= 3*h/8;
	
	
	cout<<"\nInterpolation of f(x)=1/(x+4): "<<com_simpson<<endl;
	
	cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 7f"<<endl;
	return 0;
}