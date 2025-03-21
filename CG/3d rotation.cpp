#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
int x1,x2,y_1,y2,mx,my,depth;
void draw();
void rotate();

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
//	initwindow(1400,900,(char*)"Hello");
	cout<<"3D Transformation Rotating :\n";
	cout<<"Enter 1st top value(x1,y_1):";
	cin>>x1>>y_1;
	cout<<"Enter right bottom value(x2,y2): ";
	cin>>x2>>y2;
	depth=(x2-x1)/4;
	draw();
	getch();
	cleardevice();
	rotate();
	getch();
}



void draw(){
	bar3d(x1,y_1,x2,y2,depth,7);
	outtextxy(x1+50,y_1-50,(char*)"Object");	
}

void rotate(){
	float t;
	int a1,a2,b1,b2,dep;
	cout<<"Enter the angle to rotate:  ";
	cin>>t;
	t =t*(3.14/180);	// conversion to radian 
	cout<<"t  "<<t<<endl;
	a1= mx+(x1-mx)*cos(t) - (y_1-my) *sin(t);
	a2= mx+(x2-mx)*cos(t) - (y2-my) *sin(t);
	b1= my+(x1-mx)*sin(t) - (y_1-my) *cos(t);
	b2= my+(x2-mx)*sin(t) - (y2-my) *cos(t);
	
	if(a2>a1)
		dep = (a2-a1)/4;		
	else
		dep =(a1-a2)/4;
	
	bar3d(a1,b1,a2,b2,dep,7);
	outtextxy(a1+50,b1-15,(char*)"Image");
	setcolor(15);
}