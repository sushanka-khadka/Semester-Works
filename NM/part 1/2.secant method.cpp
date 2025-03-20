/* WAP in C to find the roots of following equation using Secant Method. (Take the 
values of intervals (brackets or initial guesses)  and error tolerance from user)   
	e^-x - 3x = 0
*/

#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

float f(float x){
	return exp(-x)- 3*x;  
//	return pow(x,2) -4*x -10;
}

void secant(float x1,float x2,float E){
	int iter=1;
	float f1=f(x1);
	float f2=f(x2);
	float x3= x2-(f2*(x2-x1) /(f2 -f1));
	float Er= abs((x3-x2) / x3);
	
	cout<<left<<setw(5)<<" "<<setw(5)<<"S.N."<<setw(10)<<"x1"<<setw(10)<<"x2"<<setw(15)<<"f1"<<setw(15)<<"f2"<<setw(15)<<"x3"<<setw(15)<<"Er"<<endl;
	cout<<left<<setw(4)<<" ";
	for (int i=0;i<85;i++){	
		cout<<"-";
	}
	cout<<endl;
		
	while (Er > E) {
		x3= x2-(f2*(x2-x1) /(f2 -f1));
		Er= abs((x3-x2) / x3);
		cout<<left<<setw(5)<<" "<<setw(5)<<iter<<setw(10)<<x1<<setw(10)<<x2<<setw(15)<<f1<<setw(15)<<f2<<setw(15)<<x3<<setw(15)<<Er<<endl;		
		x1=x2;		x2=x3;
		f1=f2;		
		f2=f(x2);
		iter++; // to count the iteratioin no
	}
	cout<<endl<<"Root of eqn is " << x3<<endl;	
	
}


int main(){
	float x1=4,x2=2;
	float E =0.0001;
	cout<<"enter the lower and upper bound : ";
	cin>>x1>>x2;
	cout<<"Enter Error Tolorence  ";
	cin>>E;
	
	secant(x1,x2,E);
	return 0;	
}