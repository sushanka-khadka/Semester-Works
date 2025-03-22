#include<iostream>
#include<iostream>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7

using namespace std;
int x1=15,x2=45,x3=30,y_1=15,y2=15,y3=30;
void scale(float sx,float sy);
void translate(int ,int);
void draw(float x1,float y_1,float x2,float y2,float x3,float y3){
	float x_or=getmaxx()/2,y_or=getmaxy()/2,max=getmaxy();
	line(x1+x_or,max-(y_1+y_or),x2+x_or,max-(y2+y_or));
	line(x3+x_or,max-(y3+y_or),x2+x_or,max-(y2+y_or));
	line(x1+x_or,max-(y_1+y_or),x3+x_or,max-(y3+y_or));	
	
	floodfill((x1+x2+x3+3*x_or)/3,max-(y_1+y2+y3+3*y_or)/3,15);			
}

int main(){
	float x,y;
	int op,gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(getmaxwidth()/2,getmaxheight()/2,"SUSHANKA");
	outtextxy(getmaxx()/2-30,getmaxy()/2-30,(char*)"Origin");	
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	
	draw(x1,y_1,x2,y2,x3,y3);
	scale(3,4);
	getch()	;
	
	translate(50,70);
	getch();
	
	closegraph();
}

void scale(float sx,float sy){	
	x1=x1*sx; y_1=y_1*sy; x2=x2*sx; y2=y2*sy;	x3=x3*sx; y3=y3*sy;
	draw(x1,y_1,x2,y2,x3,y3);
	
	outtextxy(x1+ getmaxx()/2,getmaxy()-(y_1+ getmaxy()/2),(char*)"scaled");
}

void translate(int tx,int ty){	
	x1+=tx; x2+=tx; x3+=tx; y_1+=ty; y2+=ty; y3+=ty;
	draw(x1,y_1,x2,y2,x3,y3);
	outtextxy(x1+ getmaxx()/2,getmaxy()-(y_1+ getmaxy()/2),(char*)"Translated");
}
	
	

