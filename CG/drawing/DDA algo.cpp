#include<iostream>
#include<math.h>
#include<graphics.h>
//#include<stdio.h>
using namespace std;

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	
	int x0=5,y0=4,x1=70,y1=70;
	cout<<"Enter end points (x0,y0) and (x1,y1):\t";
	cin>>x0>>y0>>x1>>y1;
	float x=x0,y=y0;
	
	int dx=abs(x1-x0),dy=abs(y1-y0),steps;
	float x_inc,y_inc;
	if(dx>dy)
		steps=dx;
	else
		steps=dy;
	x_inc= (float)dx/steps;
	y_inc= (float)dy/steps;
	
	cout<<"steps\t x\t y\t  points(x,y)\n";
	cout<<0<<'\t'<<x<<'\t'<<y<<"\t("<<round(x)<<','<<round(y)<<")\n";
	putpixel(round(x),round(y),YELLOW);
	for(int i=0;i<steps;i++){
		x +=x_inc;
		y +=y_inc;		
		cout<<i+1<<'\t'<<x<<'\t'<<y<<"\t("<<round(x)<<','<<round(y)<<")\n";
		putpixel(round(x),round(y),YELLOW);
	}	
	
	
	getch();
	closegraph();
	
}