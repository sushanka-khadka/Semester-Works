/* WAP in C to find the roots of following equation using Fixed Point Iteration 
Method. (Take the values of initial guess  and error tolerance from user)   
1+ 1/2 sin(x)  - x  = 0 
*/

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float f(float x){
	return 1+ sin(x)/2  -x;
}
float g(float x){
	return 1+sin(x)/2;		// sol-n of x 	
}

void fixed_point(float x1,float E){
	int iter=1;
	float f1=f(x1);	
	float x2= g(x1);	
	float Er= abs((x2-x1) / x2);
	cout<<left<<setw(5)<<" "<<setw(5)<<"S.N."<<setw(10)<<"x_i"<<setw(15)<<"x_i+1"<<setw(15)<<"Er"<<endl;
	cout<<left<<setw(4)<<" ";
	for (int i=0;i<55;i++){	
		cout<<"-";
	}
	cout<<endl;
		
	while (Er > E) {
		cout<<left<<setw(5)<<" "<<setw(5)<<iter<<setw(10)<<x1<<setw(15)<<x2<<setw(15)<<Er<<endl;		
		x1=x2;
		f1=f(x1);		
		x2= g(x1);
		Er= abs((x2-x1) / x2);
		Er= int(Er*10/E) *E/10;
		iter++; // to count the iteratioin no
	}
	cout<<endl<<"Root of eqn is " <<x2<<endl;	
	
}


int main(){
	float x=5;
	float E =0.0009;
	cout<<"enter the x: ";
	cin>>x;
	cout<<"Enter Error Tolorence  ";
	cin>>E;
	
	fixed_point(x,E);
	
	return 0;	
}
