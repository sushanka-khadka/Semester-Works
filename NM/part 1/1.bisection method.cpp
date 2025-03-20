/* WAP in C to find the roots of following equation using Bisection Method. (Take the 
values of intervals (brackets or initial guesses)  and error tolerance from user)   
x2 - 4 cos(x)  = 0 */

# include<iostream>
# include<math.h>
//#include<string>
#include<iomanip>
using namespace std;

float func_value(float x){
	return pow(x,2)- 4*cos(x/180);  // takes radian value so converting it to degree
}
void bisection(float a,float b,float E){
//	 given eqn is  x^2 - 4 cos(x)  = 0 
	float c=(a+b)/2;
	int iterator =0;
	float Er= abs((b-a) / b);
	
	cout<<left<<setw(5)<<" "<<setw(10)<<"a"<<setw(10)<<"b"<<setw(10)<<"c"<<setw(15)<<"f_a"<<setw(15)<<"f_c"<<setw(15)<<"f_a_c"<<setw(15)<<"Er"<<endl;
	cout<<left<<setw(4)<<" ";
	for (int i=0;i<80;i++){	
		cout<<"-";
	}
	cout<<endl;
	
	while (Er > E) {
		Er= abs((b-a) / b);
		c=(a+b)/2;
		float f_a=func_value(a);
		float f_c=func_value(c);
		float fun_a_c = f_a * f_c;
		
		cout<<left<<setw(5)<<" "<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<setw(15)<<f_a<<setw(15)<<f_c<<setw(15)<<fun_a_c<<setw(15)<<Er<<endl;
		if (fun_a_c < 0 ){
			b=c;
		}
		else{
			a=c;
		}
		iterator ++; // to count the iteratioin no
	}
	cout<<" loop terminated with: "<<endl;
	cout<<"iteration no _ "<<iterator<<endl;
	cout<<"root lies with in "<<a <<"and " <<b<<endl;
	cout<<"Root of eqn is " << c<<endl;	
}
int main(){
	float a=0.0,b=3.4,E=.01; 
	cout<<"enter the lower and upper bound : ";
	cin>>a>>b;
	cout<<"Enter Error Tolorence  ";
	cin>>E;
	bisection(a,b,E);
	return 0;
}