#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
	int r=75,h=90,k=90,gd=DETECT,gm;
//	cout<<"Enter radius of circle\t";
//	cin>>r;
//	cout<<"Enter center(h,k):\t";
//	cin>>h>>k;
	// initialization 
	int x=0,y=r, p0=1-r;
	initgraph(&gd,&gm,(char*)"");
	while(x<=y){
		delay(10);
		putpixel(x+h,y+k,YELLOW);
		putpixel(-x+h,y+k,YELLOW);
		putpixel(-x+h,-y+k,YELLOW);
		putpixel(x+h,-y+k,YELLOW);
		
		putpixel(y+h,x+k,YELLOW);
		putpixel(-y+h,x+k,YELLOW);
		putpixel(-y+h,-x+k,YELLOW);
		putpixel(y+h,-x+k,YELLOW);
		
		x++;
		if(p0<0){	// i.e r>1
			p0= p0+2*x+1;

		}
		else{

			p0 =p0+2*x+1 -2*y;
			y--;
		}
	}
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(100,190,(char*)"Name: Sushanka Khadka");
	outtextxy(100,210,(char*)"Section: C  Roll no.: 84");
	outtextxy(100,230,(char*)"Mid-point Circle Algorithm");
	
	
	getch();
	closegraph();
		
}