//WAP to implement  numerical differentiation techniques using  
//a) Forward Difference Formula  and Backward Difference Formula (for 1st Derivative) 
//b) Central Difference Formula ( for 1st derivative and  2nd Derivative) 


#include<iostream>
#include<math.h>
using namespace std;

float func(float x){
	return exp(x)*sqrt(sin(x) +log(x));	// ln(x)
}

int main(){
	float x,h;
	cout<<"Derivatives Using Forward & Backward Difference \n\tfor f(x) = e^x sqrt(sinx(x) +ln(x))) :\n";
	cout<<"derivative to be calculated at (point): \t";
	cin>>x;
	cout<<"interval gap(h): \t";
	cin>>h;
	float fd= (func(x+h) -func(x))/h;
	float bd = (func(x) -func(x-h))/h;
	cout<<"Derivative at that point is\n";
	cout<<"\tForward Diff>\t"<<fd<<endl;
	cout<<"\tBackward Diff>\t"<<bd<<endl;

	cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 5a"<<endl;
	
	
	return 0;
}
//Forward Difference Formula mostly used for left end points:
//Backward Difference Formula mostly used for left end points: