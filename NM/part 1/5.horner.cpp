//WAP to implement Horner's method  to evaluate the polynomial and test for some 
//polynomials.  

#include<iostream>

using namespace std;
void Horner(float x){
	int n=3;
//	5x3 + 4x2 +3x +9
	float a[4]={9,3,4,5};
	float p=a[3];		// initially a3
	while(n>0){
		cout<<" value of p"<<n<<":	"<< p<<endl;
		p=p*x+a[n-1];				
		n--;
	}
	cout<<" value of eqn at x= "<<x<<"\t"<< p<<endl;
}


int main(){	
	float x;
	cout<<"enter the x: ";
	cin>>x;
	Horner(x);
	
	return 0;
}