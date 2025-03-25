//7. WAP to compute the numerical integration using 
//g. Gauss Legendre two point and three point  formula   

#include<iostream>
#include<math.h>
using namespace std;

float func(float x){
//	return exp(-x/2);
//	return exp(x);
	return (pow(x,4) +1);
	
}

void GaussQuadature(float a, float b,int n){
	if(n==2 || n==3){
		float z[3],w[3];
		if(n==2){		
			cout<<"2 point Formula \n";
			z[0]=-1/sqrt(3) ,z[1]= 1/sqrt(3);    // no need to take decimal sqrt gives floating so...
			w[0]=1, w[1] =1;
		}
		else if(n==3){
			cout<<"3 point Formula \n";
//			z[3]={-sqrt(3/5),	0, sqrt(3/5)};
			z[0]=-sqrt(3.0/5) ,z[1]=0, z[2]= sqrt(3.0/5);
			w[0] =5.0/9, w[1] =8/9.0, w[2] =5/9.0; 		// why decimal->> cuz 5/9 =0.0 division taken as int
		}
		float gauss=0;
		float x[4];
		for(int i=0;i<n;i++){
			x[i] = (b-a)*z[i]/2 +(b+a)/2;
			gauss += w[i] * func(x[i]);
		}
		gauss *= (b-a)/2;
		cout<<"\tIntegrated value:  "<<gauss<<endl;
	}
	else{
		exit(1);
	}
}
int main(){
	float a,b;
	cout<<string(10,'*');
	cout<<"Gausssian Legendre (Quadature)";
	cout<<string(10,'*');
	cout<<"\nEnter left and right limits:  ";
	cin>>a>>b;
	cout<<string(50,'-')<<endl;
	GaussQuadature(a,b,2);
	GaussQuadature(a,b,3);
	
	return 0;
}