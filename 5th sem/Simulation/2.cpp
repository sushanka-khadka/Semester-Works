#include <iostream> 
using namespace std; 
int main(){ 
	int M = 1000, a = 15, X = 13, i; 
 	
 	cout<<"Multiplicative Congurential Method \n";
 	cout<<"First 50 random numbers: \n";
	
	for(i=0; i<50; i++) { 
		X=(a * X ) % M; 
		cout << X << " "; 
	} 
	return 0; 
}