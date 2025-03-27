// wap to solve boundary value problem using Shooting Method
#include<iostream>
#include<math.h>
using namespace std;
float func_z(float x, float y,float z){
	return 6*x;
//	return 2*x+y;
//	cout<<"return by z"<<2*exp(x) +2*z-y<<endl;
//	return 2*exp(x) +2*z-y;
}
float func_y(float x, float y,float z){
	return z;
}
int main(){
	
//	float x0=0,y0=1.5,xn=2,yn=2.5,z0,a,y,x,z;
	float x0=1,y0=2,xn=2,yn=9,y,x,z;
	float h=0.5,a=1.5;
	float xi,yi,zi;
	float g1,g2,g3,v,v1,v2;
	cout<<"Enter Boundary Conditions:\t";
	cin>>x0>>y0>>xn>>yn;
	cout<<"Enter x at which value  is required: ";
	cin>>a;
	
	x=x0,y=y0;
	g1=z=(yn-y0)/(xn-x0);
//	G1=z=5.5;
	for(x=x0;x<=a;x+=h){
		xi=x,yi=y,zi=z;
		cout<<"(x,y,z)= ("<<x<<','<<y<<','<<z<<")\n";		
		y=y+func_y(xi,yi,zi)*h;
		z=z+func_z(xi,yi,zi)*h;
	}
	v1=y;
	cout<<"(x,y,z)= ("<<x<<','<<y<<','<<z<<")\n\n";
	
	if(y>yn)
		z=(yn-y0)/(xn-x0)/2;
	else
		z=(yn-y0)/(xn-x0)*2;
	
	g2=z;
	y=y0;
	for(x=x0;x<=a;x+=h){
		xi=x,yi=y,zi=z;
		cout<<"(x,y,z)= ("<<x<<','<<y<<','<<z<<")\n";		
		y=y+func_y(xi,yi,zi)*h;		
		z=z+func_z(xi,yi,zi)*h;
	}
	v2=y; v=yn;
	cout<<"(x,y,z)= ("<<x<<','<<y<<','<<z<<")\n\n";	
	g3=g2-(v2-v)/(v2-v1)*(g2-g1);
	z=g3;
	y=y0;
	float sol=0;
	for(x=x0;x<=a;x+=h){
		xi=x,yi=y,zi=z;
		cout<<"(x,y,z)= ("<<x<<','<<y<<','<<z<<")\n";		
		y=y+func_y(xi,yi,zi)*h;
		z=z+func_z(xi,yi,zi)*h;
		if(x+h==a){
			sol=y;
		}
	}
	cout<<"(x,y,z)= ("<<x<<','<<y<<','<<z<<")\n\n";
		
	if(y==yn){
		cout<<"value of boundary condition: obtained from 3rd approximation \n";
		printf("Required ans:\t y(%.2f)=%.2f\n\n",a,sol);
	}
	
	return 0;
}

// if the first approximation is right doesn't matter if we further calculate it, cuz at the third approximation we will get the right value