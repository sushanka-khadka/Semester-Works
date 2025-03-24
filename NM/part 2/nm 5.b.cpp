// WAP to implement  numerical differentiation techniques using
//b) Central Difference Formula ( for 1st derivative and  2nd Derivative) 

#include<iostream>
#include<math.h>
using namespace std;

float func(float x){
	return exp(x)*sqrt(sin(x) +log(x));	// ln(x)
}

int main(){
	float x,h;
	cout<<"Derivatives Using Central Difference for \n\tf(x) = e^x sqrt(sinx(x) +ln(x))) :\n";
	cout<<"derivative to be calculated at (point): ";
	cin>>x;
	cout<<"interval gap(h): \t";
	cin>>h;
	float first = (func(x+h)- func(x-h))/2/h;
	float second = (func(x+h)- 2*func(x)+ func(x-h))/h/h;
	cout<<"Derivative at that point is :\n";
	cout<<"\t1st :\t"<<first<<endl;
	cout<<"\t2nd :\t"<<second<<endl;
	
	cout<<endl<<string(35,'_')<<endl;
	cout<<"Name :Santosh B.K. \tSection : C\nRoll no:76"<<endl;
	cout<<"Lab no: 5b"<<endl;
	
	return 0;
}
//Backward Difference Formula mostly used for Right end points: