#include<iostream>
#include<math.h>
#define pi 22.0/7
using namespace std;

int main(){
	float x,y,tx,ty;
	cout<<"Enter points: ";
	cin>>x>>y;
	cout<<"Enter translation distance (tx,ty): ";
	cin>>tx>>ty;
	x+=tx;
	y+=ty;
	printf("Translated points: (%.2f,%.2f)\n",x,y);
	cout<<"Enter angle(deg) to rotate anti-clockwise(+ve) or clockwise(-ve): ";
	float a;
	cin>>a;
	a=pi/180*a;
	cout<<"A     "<<a<<endl;
	
	if(a>=0){
		x=x*cos(a)-y*sin(a);
		y=x*sin(a)+y*cos(a);
	}
	else{
		x = x*cos(a)+y*sin(a);
		y = -x*sin(a)+y*cos(a);
	}
	printf("Rotated points: (%.2f,%.2f)\n",x,y);
	
	float sx,sy;
	cout<<"Enter scaling factor(sx,sy): ";
	cin>>sx>>sy;
	x=x*sx;
	y=y*sy;
	printf("Scaled points: (%.2f,%.2f)\n",x,y);
	
	// Shearing 
	float shx,shy;
	cout<<"Enter shearing factor(shx,shy) : ";
	cin>>shx>>shy;
	cout<<"X-direction shear\n";
	x=x+shx*y;
//	y=y;	
	printf("Sheared points: (%.2f,%.2f)\n",x,y);
		
	cout<<"Y-direction shear\n";
//	x=x
	y=shy*x+y;
	printf("Sheared points: (%.2f,%.2f)\n",x,y);
	
	// Reflection
//	reflecton about a line(y-axis) x=0
//	reflecton about a line(x-axis) y=0
//	reflecton about a line y=x or x=y
//	reflecton about a line y=-x
//	reflecton about a line perpendicular to origin 

//	reflecton about a line(y-axis) x=0
	x=-x;	y=y;
//	reflecton about a line(x-axis) y=0
	x=x;	y=-y;
//	reflecton about a line y=x or x=y
	swap(x,y);
//	reflecton about a line y=-x
	//	swap(-x,-y);
	x=-x;	y=-y;
	swap(x,y);
//	reflecton about a line perpendicular to origin 
	x=-x;	y=-y;
	
	
	
	
}