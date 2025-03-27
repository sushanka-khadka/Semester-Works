// program to find gcd of two numbers

#include<iostream>
using namespace std;

int GCD(int a, int b){
	int r=0;
	while(b!=0){
		r= a%b;
		a= b;
		b=r;
	}
	return a;
}

int main(){
	int a,b;
	cout<<"Enter two integers: ";
	cin>>a>>b;
	
	cout<<"GCD of "<<a<<" and "<<b<<" is: "<<GCD(a,b);
	
	GCD(a, b);
	
	return 0;
}
