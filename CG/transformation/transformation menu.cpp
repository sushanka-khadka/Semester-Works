// Menu driven program for transformation

#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7
using namespace std;
void plot(int x,int y){
	setfillstyle(SOLID_FILL,YELLOW);
	circle(x,y,4);
    floodfill(x,y,15);
}
int main(){
	float x,y;
	int op,gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	cout<<"Transformation\n\t 1.Translation\n\t 2.Rotation\n\t 3.Scaling\n\t 4.Shearing\n\t 5.Reflection\n\t 6.Exit\n";
	cout<<"Enter points: ";
	cin>>x>>y;
	x+=50;	y+=50;		// we consider origin at 50,50
	outtextxy(30,30,(char*)"Origin");
	line(50,50,50,getmaxy());
	line(50,50,getmaxx(),50);
	plot(x,y);    
	cout<<"Enter operation:\t";
	cin>>op;
	while(1){
		switch(op){
			case 1:// translation
				float tx,ty;		
				cout<<"Enter translation distance (tx,ty): ";
				cin>>tx>>ty;
				x+=tx;
				y+=ty;
				plot(x,y);  
				system("cls");				
				printf("Translated points: (%.2f,%.2f)\n",x,y);
//				system("cls");
				break;
			case 2://rotation
				cout<<"Enter angle(deg) to rotate anti-clockwise(+ve) or clockwise(-ve): ";
				float a;
				cin>>a;
				a=pi/180*a;
				cout<<"A     "<<a<<endl;
				float x_,y_;
				if(a>=0){
					x_=x*cos(a)-y*sin(a);
					y_=x*sin(a)+y*cos(a);					
				}
				else{
					x_ = x*cos(a)+y*sin(a);
					y_= -x*sin(a)+y*cos(a);
				}
				plot(x_,y_);    
				system("cls");
				printf("Rotated points: (%.2f,%.2f)\n",x_,y_);				
				break;
			case 3://scaling
				float sx,sy;
				cout<<"Enter scaling factor(sx,sy): ";
				cin>>sx>>sy;
				x=x*sx;
				y=y*sy;
				plot(x,y);
				system("cls");
				printf("Scaled points: (%.2f,%.2f)\n",x,y);
				break;
			case 4:// Shearing 			
				float shx,shy;
				cout<<"Enter shearing factor(shx,shy) : ";
				cin>>shx>>shy;
				system("cls");
				cout<<"X-direction shear\n";
				x=x+shx*y;
			//	y=y;	
				plot(x,y);
				printf("Sheared points: (%.2f,%.2f)\n",x,y);
					
				cout<<"Y-direction shear\n";
			//	x=x
				y=shy*x+y;
				plot(x,y);
				printf("Sheared points: (%.2f,%.2f)\n",x,y);
				break;
			case 5:// reflection
				int re_op;
//				while(2){		
				
				system("cls");				
				
				do{	
					cout<<"Reflection about:\n";
					cout<<"\t1.line(y-axis) x=0\n\t2.line(x-axis) y=0\n\t3.line y=x or x=y\n\t4.ine y=-x\n";
					cout<<"\t5.line perpendicular to origin\n\t6.Home ";			
					cout<<"\nEnter reflection operation:\t";
					cin>>re_op;
					switch(re_op){
						case 1://	reflecton about a line(y-axis) x=0
							x=-x;	y=y;
							plot(x,y);
							break;
						case 2://	reflecton about a line(x-axis) y=0
							x=x;	y=-y;
							plot(x,y);
							break;
						case 3://	reflecton about a line y=x or x=y
							swap(x,y);
							plot(x,y);
							break;
						case 4://	reflecton about a line y=-x
							//	swap(-x,-y);
							x=-x;	y=-y;
							swap(x,y);
							plot(x,y);						
						case 5://	reflecton about a line perpendicular to origin 
							x=-x;	y=-y;
							plot(x,y);
						case 6:
							break;
						default:
							cout<<"!!!Wrong option!!!\n";
					}
					system("cls");
					printf("Reflected points: (%.2f,%.2f)\n",x,y);
				}while(re_op!=6);
				break;				
			case 6:
				exit(1);
			default:			
				cout<<"Wrong option\n";
		}
		cout<<"Transformation\n\t 1.Translation\n\t 2.Rotation\n\t 3.Scaling\n\t 4.Shearing\n\t 5.Reflection\n\t 6.Exit\n";
		cout<<"Enter operation:\t";
		cin>>op;
	}
	getch();
	closegraph();
	
	return 0;
}