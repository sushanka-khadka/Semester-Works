#include<iostream>
using namespace std;

int main(){
	int x, a, c, m, n;
	cout<<"Random numbers generation using Mixed Congurential Method\n";
	cout<<"Enter Seed: ";
	cin>>x;
	cout<<"Enter constant multiplier: ";
	cin>>a;
	cout<<"Enter incrementer(c != 0): ";
	cin>>c;
	if (c == 0){
		cout<<"df";
	}
	cout<<"Enter modulus(+ve): ";
	cin>>m;
	cout<<"Enter sequence length: ";
	cin>>n;
	for(int i=0; i<n; i++){
		x= (a * x + c)  % m;
		cout<<x<<" ";
	}
	
	
	
	return 0;
}