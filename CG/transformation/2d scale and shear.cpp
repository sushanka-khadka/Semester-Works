#include<iostream>
#include<iostream>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7

using namespace std;
int x1=15,x2=45,x3=30,y_1=15,y2=15,y3=30;
void scale(float sx,float sy);
void shear(float shx,float shy);
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
	
	printf("Triangle(%d,%d,%d,%d,%d,%d)\n",x1,y_1,x2,y2,x3,y3);
	outtextxy(getmaxx()/2-30,getmaxy()/2-30,(char*)"Origin");	
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	
	draw(x1,y_1,x2,y2,x3,y3);
	scale(3,4);
	getch()	;
	
	shear(2,1);
	getch();
	
	closegraph();
}

void scale(float sx,float sy){	
	x1=x1*sx; y_1=y_1*sy; x2=x2*sx; y2=y2*sy;	x3=x3*sx; y3=y3*sy;
	draw(x1,y_1,x2,y2,x3,y3);
	
	outtextxy(x1+ getmaxx()/2,getmaxy()-(y_1+ getmaxy()/2),(char*)"scaled");
}

void shear(float shx,float shy){
//	cout<<"X-direction shear\n";
	float sx1=x1+shx*y_1;
	float sx2=x2+shx*y2;
	float sx3=x3+shx*y3;
	draw(sx1,y_1,sx2,y2,sx3,y3);
	outtextxy(sx1+ getmaxx()/2,getmaxy()-(y_1+ getmaxy()/2),(char*)"X-shear");

	//	x=x
	y_1=shy*x1+y_1;	y2=shy*x2+y2;	y3=shy*x3+y3;
	draw(x1,y_1,x2,y2,x3,y3);
	outtextxy(x1+ getmaxx()/2,getmaxy()-(y_1+ getmaxy()/2),(char*)"Y-shear");
}	
	
	
	

