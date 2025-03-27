// program to find nth fibonacci series

#include<iostream>
using namespace std;

int fibo(int n){
	int a=0, b=1, f=0;
	if (n ==1)
		return 1;
	else{	
		for(int i=2; i<=n;i++){
			f= a+b, a=b, b=f;		
		}
		return f;	
	}
}

int main(){
	int n;
	cout<<"Enter which number of fibo series:  ";
	cin>>n;	
	cout<<n<<"th number of fibonacci series is :"<<fibo(n);
	
	return 0;
}