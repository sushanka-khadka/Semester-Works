// Program to draw line using Bresenham Algorithm (BSA)

#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
//	setfillstyle(SOLID_FILL,GREEN);
//	bar(0, 0, getmaxx(), getmaxy());
//	setcolor(GREEN);
	float x0,y0,x1,y1,x_end,m,x,y;
	x0=100,y0=15,x1=25,y1=180;
//	x0=60,y0=40,x1=20,y1=10;
//x0=60,y0=40,x1=20,y1=10;
//	x0=25,y0=180,x1=100,y1=15;
	cout<<"Enter end points (x0,y0) and (x1,y1):\t";
	cin>>x0>>y0>>x1>>y1;
	
	m=(y1-y0)/(x1-x0);
	int dx=abs(x1-x0), dy=abs(y1-y0);	// actually its del_x
	int pk=2*dy-dx;	// initial decision
	
//	cout<<"steps\t x\t y\t pk\t  points(x,y)\n";
//	cout<<0<<'\t'<<x<<'\t'<<y<<'\t'<<pk<<"\t("<<x<<','<<y<<")\n";
	putpixel(x,y,YELLOW);
	if(x1>x0){
		x=x0; y=y0; x_end=x1;
	}
	else{
		x=x1; y=y1; x_end=x0;
	}
	int i=0;
	if(m>0){
		cout<<0<<'\t'<<x<<'\t'<<y<<'\t'<<pk<<"\t("<<x<<','<<y<<")\n";
		putpixel(x,y,YELLOW);
//		for(x;x<=x_end;x++){
		while(x<x_end){
			x++;
			if(pk<0)
				pk+= 2*dy;
			else{
				y++;
				pk+= 2*dy-2*dx;
			}
//		cout<<++i<<'\t'<<x<<'\t'<<y<<'\t'<<pk<<"\t("<<x<<','<<y<<")\n";
		putpixel(x,y,YELLOW);
		}
	}
	else{		
//		cout<<0<<'\t'<<x<<'\t'<<y<<'\t'<<pk<<"\t("<<x<<','<<y<<")\n";
		putpixel(x,y,YELLOW);	
		for(i=1;i<=dx;i++){
			while(pk>0){
				y--;
				pk=pk-2*dx;
			}
			x++;
			pk=pk+ 2*dy;
//			i++;
//			cout<<i<<'\t'<<x<<'\t'<<y<<'\t'<<pk<<"\t("<<x<<','<<y<<")\n";
			putpixel(x,y,YELLOW);
			
		}
	}
			
		
	getch();
	closegraph();
	
}