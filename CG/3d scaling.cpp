#include<iostream>
#include<conio.h>
//#include<math.h>
#include<process.h>
#include<graphics.h>
using namespace std;

int x1,x2,y_1,y2,mx,my,depth;
void draw();
void scale();

int main(){
	int gd=DETECT, gm,c;
//	initgraph(&gd,&gm,"D:\sushanka html\Dev-Cpp\MinGW64\bin");
//	initgraph(&gd,&gm,"")
	initgraph(&gd,&gm,(char*)"");
	
	cout<<"\n\t\t3D Scaling\n";
	cout<<"Enter 1st top value(x1,y_1):";
	cin>>x1>>y_1;
	cout<<"Enter right bottom value(x2,y2): ";
	cin>>x2>>y2;
	depth=(x2-x1)/4;
	mx=(x1+x2)/2;
	my=(y_1+y2)/2;
	draw();
	getch();
	cleardevice();
	scale();
	getch();
}

void draw(){
	bar3d(x1,y_1,x2,y2,depth,1);		// why 7
	outtextxy(x1+25,y_1-15,(char*)"Object");
	getch();	
}

void scale(){
	int a1,a2,b1,b2,dep,x,y;
	cout<<"Enter scaling factors: ";
	cin>>x>>y;
	
	a1= mx+(x1-mx)*x;
	a2= mx+(x2-mx)*x;
	b1= my+(y_1-my)*y;
	b2= my+(y2-my)*y;
	
	dep =(a2-a1)	/4;
	bar3d(a1,b1,a2,b2,dep,7);
	outtextxy(a1+25,b1-15,(char*)"Image");
	setcolor(3);
	draw();
}