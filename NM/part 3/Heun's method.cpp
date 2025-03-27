#include<iostream>
using namespace std;

float func(float x, float y){
//	return 2*y/x;
	return 2*x+y;
}
// given y' = 2x+y

int main(){
	cout<<"\tHeun's Method(incomplete)\n";
	cout<<string(35,'-')<<endl;
		
	float x[10],y[10],h=0.25,a=2;
	float m1,m2;

	x[0]=0,y[0]=1;
	h=0.1,a=10.4;
	cout<<"Enter initial approximation(x,y):\t";
	cout<<"\tinitial approx. at and value at that point: ";
	cin>>x>>y;
	cout<<"Enter stepsize: ";
	cin>>h;
	cout<<"Enter point to calculate at: ";
	cin>>a;
	
	int i=0;
	while(x[i]!=a){
		x[i+1]=x[i]+h;
		m1=func(x[i],y[i]);
		m2=func(x[i+1],y[i]+h*m1);
		y[i+1]=y[i]+(m1+m2)*h/2;		
		cout<<"value of x "<<x[i]<<'\t'<<y[i]<<endl;
		i++;
	}
	cout<<" functioinal value at x= "<<x[i]<<" is:\t"<<y[i]<<endl;
	
	return 0;
}