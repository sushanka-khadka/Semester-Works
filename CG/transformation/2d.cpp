/*

// 2D
 scaling and rotation 
 scaling and shearing 
 scaling and translation
 tanslation and rotation
 
 // 3D 
 scaling and rotation 
 scaling and translation
 translation and rotation 
*/

#include<iostream>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7
using namespace std;

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");	
//	line(25,50,50,60);
//	outtextxy(45)
	
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(45,54,15);
	
	setfillstyle(SOLID_FILL,BLUE);
	bar3d(50,20,170,150,17,true);
	floodfill(80,100,15);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(80,17,15);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(185,140,15);
	
	bar3d(250,220,300,280,7,1);
		
	
	getch();
	closegraph();
}
