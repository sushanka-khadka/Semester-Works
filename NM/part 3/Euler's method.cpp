// Euler's Method
#include<iostream>
using namespace std;

float func(float x, float y){
	return 2*x+y;
}
// given y' = 2x+y

int main(){
	cout<<"\tEuler's Method\n";
	cout<<string(35,'~')<<endl;
	
	float x,y,h=0.1,a=0.4;
	
	cout<<"Enter initial approximation(x,y):\t";
//	cout<<"\tinitial approx. at and value at that point: ";
	cin>>x>>y;
	cout<<"Enter stepsize: ";
	cin>>h;
	cout<<"Enter point to calculate at: ";
	cin>>a;
	
	
	
		
	for(x;x<a;x+=h){		
//		cout<<" functioinal value at x= "<<x<<" is:\t"<<y<<endl;
		y= y+ func(x,y)*h;
//		y=y+func(x,y)*h;
	}
	cout<<" functioinal value at x= "<<x<<" is:\t"<<y<<endl;
	
}