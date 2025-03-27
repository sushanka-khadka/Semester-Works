#include<iostream>
using namespace std;
float func(float x,float y){
	return x*x+y*y;
}

int main(){
	cout<<"4th order Runge Kutta MEthod\n";	
	float x=0,y=0,h=0.2,a=12.4;
	cout<<"Enter initial approximation(x,y):\t";
//	cout<<"\tinitial approx. at and value at that point: ";
	cin>>x>>y;
	cout<<"Enter stepsize: ";
	cin>>h;
	cout<<"Enter point to calculate at: ";
	cin>>a;
	
	float m1,m2,m3,m4;
	for(x;x<a;x+=h){
		m1=func(x,y);
		m2=func(x+h/2,y+m1*h/2);
		m3=func(x+h/2,y+m2*h/2);
		m4=func(x+h,y+m3*h);
		y= y+ (m1+2*m2+2*m3+m4)*h/6;
		cout<<"value at x=  "<<x<<" :  "<<y<<endl;
	}
	return 0;
}