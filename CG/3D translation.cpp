#include<iostream>
#include<conio.h>
//#include<math.h>
#include<process.h>
#include<graphics.h>
using namespace std;

int x1,x2,y_1,y2,mx,my,depth;
void draw();
void trans();

int main(){
	int gd=DETECT, gm,c;
//	initgraph(&gd,&gm,"D:\sushanka html\Dev-Cpp\MinGW64\bin");
//	initgraph(&gd,&gm,"")
	initgraph(&gd,&gm,(char*)"");
	
	cout<<"\n\t\t3D Translation\n";
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
	trans();
	getch();
}

void draw(){
	bar3d(x1,y_1,x2,y2,depth,7);		// why 7
	outtextxy(x1+50,y_1-15,(char*)"Object");
	getch();	
}

void trans()	{
	int a1,a2,b1,b2,dep,x,y;
	cout<<"Enter the translation distance(tx,ty): ";
	cin>>x>>y;
	a1= x1+x;
	a2= x2+x;
	b1= y_1+y;
	y2= y2+y;
	dep=(a2-a2)/4;
	bar3d(a1,b1,a2,b2,dep,7);
	outtextxy(a1+50,b1-15,(char*)"Image");
	setcolor(15);
	draw();
//	getch();
}
	