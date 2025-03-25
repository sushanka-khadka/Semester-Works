//7. WAP to compute the numerical integration using  
//h. Romberg integration formula 


#include<iostream>
#include<math.h>
using namespace std;

float func(float x){
	return 1/(1+x);
}

//Romberg function
float a=0,b=1;
float R(int i,int j){
	if(i>=j){
		float h=b-a,rom_f=0;
		if(i==0 && j==0){
			return (func(a)+ func(b))*h/2;	
		}
		
		else if(j==0){		
			for(j=1;j<=pow(2,i-1);j++){
				rom_f += func(a+ (2*j-1)* h/pow(2,i));
			}
			rom_f *= h/pow(2,i);
			rom_f += R(i-1,0)/2;
			return rom_f;
		}
		
		else {
			rom_f = pow(4,j)*R(i,j-1) -R(i-1,j-1);
			rom_f /= pow(4,j) -1;
			return rom_f;
		}
	}
	else{
		cout<<"invalid input for Romberg integration\n";
		exit(1);
	}
}

int main(){
	cout<<string(10,'*');
	cout<<"ROMBERG INTEGRATION";
	cout<<string(10,'*');
	cout<<"\nEnter left and right limits:  ";
	cin>>a>>b;
	cout<<string(50,'-')<<endl;
	float ans =R(4,4);
	cout<<"By Romberg integration \n\tR(4,4) is:\t"<<ans<<endl;			
		
	return 0;
}