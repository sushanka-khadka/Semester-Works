// Menu driven program for transformation

#include<iostream>
//#include<conio.h>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7
using namespace std;
//void plot(int x,int y){
//	setfillstyle(SOLID_FILL,YELLOW);
//	circle(x,y,4);
//    floodfill(x,y,15);
//}
void draw(float x1,float y1,float x2,float y2,float x3,float y3){
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill((x1+x2+x3)/3,(y1+y2+y3)/3,15);			
}
int main(){
	float x,y;
	int op,gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
//	initwindow(getmaxwidth(),getmaxwidth());
	float x1,x2,x3,y1,y2,y3;
	x1=150,x2=450,x3=300,y1=150,y2=150,y3=300;
	cout<<"Transformation\n\t 1.Translation\n\t 2.Rotation\n\t 3.Scaling\n\t 4.Shearing\n\t 5.Reflection\n\t 6.Exit\n";
	cout<<"Enter points:(x1,y1,x2,y2,x3,y3) ";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	x1+=50;	y1+=50;		// we consider origin at 50,50	
	x2+=50,y2+=50;	x3+=50,y3+=50;
	outtextxy(30,30,(char*)"Origin");
	line(50,50,50,getmaxy());
	line(50,50,getmaxx(),50);
//	plot(x,y);    
	draw(x1,y1,x2,y2,x3,y3);

	cout<<"Enter operation:\t";
	cin>>op;
	while(1){
		switch(op){
			case 1:// translation//			
				float tx,ty;
				cout<<"Enter translation distance (tx,ty): ";
				cin>>tx>>ty;
//				x+=tx; y+=ty;
				x1+=tx; x2+=tx; x3+=tx; y1+=ty; y2+=ty; y3+=ty;
//				plot(x,y);
				draw(x1,y1,x2,y2,x3,y3);
				system("cls");								
				printf("Translated points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)",x1,y1,x2,y2,x3,y3);
				break;
			case 2://rotation
				float a;
				cout<<"Enter angle(deg) to rotate anti-clockwise(+ve) or clockwise(-ve): ";
				cin>>a;
				a=pi/180*a;
				cout<<"A     "<<a<<endl;
				float x1_,x2_,x3_;
				if(a>=0){					
					x1_=x1*cos(a)-y1*sin(a);
					y1=x1*sin(a)+y1*cos(a);
					x2_=x2*cos(a)-y2*sin(a);
					y2=x2*sin(a)+y2*cos(a);
					x3_=x3*cos(a)-y3*sin(a);
					y3=x3*sin(a)+y3 *cos(a);
				}
				else{
					x1_ = x1*cos(a)+y1*sin(a);
					y1= -x1*sin(a)+y1*cos(a);
					x2_ = x2*cos(a)+y2*sin(a);
					y2 = -x2*sin(a)+y2*cos(a);
					x3_ = x3*cos(a)+y3*sin(a);
					y3 = -x3*sin(a)+y3*cos(a);
				}
				draw(x1_,y1,x2_,y2,x3_,y3);				   
				system("cls");
				printf("Rotated points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)",x1,y1,x2,y2,x3,y3);				
				break;
			case 3://scaling
				float sx,sy;
				cout<<"Enter scaling factor(sx,sy): ";
				cin>>sx>>sy;
				x1=x1*sx; y1=y1*sy; x2=x2*sx; y2=y2*sy;	x3=x3*sx; y3=y3*sy;
				draw(x1,y1,x2,y2,x3,y3);
				system("cls");
				printf("Scaled points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)",x1,y1,x2,y2,x3,y3);
				break;
			case 4:// Shearing 			
				float shx,shy;
				cout<<"Enter shearing factor(shx,shy) : ";
				cin>>shx>>shy;
				system("cls");
				cout<<"X-direction shear\n";
				x1=x1+shx*y1;
				x1=x1+shx*y1;
				x1=x1+shx*y1;				
			//	y=y;	
				draw(x1,y1,x2,y2,x3,y3);
				printf("Sheared points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)",x1,y1,x2,y2,x3,y3);
				cout<<"Y-direction shear\n";
			//	x=x
				y1=shy*x1+y1;	y2=shy*x2+y2;	y3=shy*x3+y3;
				draw(x1,y1,x2,y2,x3,y3);
				printf("Sheared points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)\n",x1,y1,x2,y2,x3,y3);
				break;
			case 5:// reflection
				int re_op;			
				system("cls");
				do{	
					cout<<"Reflection about:\n";
					cout<<"\t1.line(y-axis) x=0\n\t2.line(x-axis) y=0\n\t3.line y=x or x=y\n\t4.ine y=-x\n";
					cout<<"\t5.line perpendicular to origin\n\t6.Home ";			
					cout<<"\nEnter reflection operation:\t";
					cin>>re_op;
					switch(re_op){
						case 1://	reflecton about a line(y-axis) x=0
							x1=-x1;	y1=y1;
							x2=-x2;	y2=y2;
							x3=-x3;	y3=y3;
							draw(x1,y1,x2,y2,x3,y3);
							break;
						case 2://	reflecton about a line(x-axis) y=0
							x1=x1;	y1=-y1;
							x2=x2;	y2=-y2;
							x3=x3;	y3=-y3;
							draw(x1,y1,x2,y2,x3,y3);						
							break;
						case 3://	reflecton about a line y=x or x=y
							swap(x1,y1);	swap(x2,y2);	swap(x3,y3);
							draw(x1,y1,x2,y2,x3,y3);
							break;
						case 4://	reflecton about a line y=-x
							//	swap(-x,-y);
							x1=-x1;	y1=-y1;
							x2=-x2;	y2=-y2;
							x3=-x3;	y3=-y3;
							swap(x1,y1);	swap(x2,y2);	swap(x3,y3);
							draw(x1,y1,x2,y2,x3,y3);
							break;
						case 5://	reflecton about a line perpendicular to origin 
							x1=-x2;	y1=-y1;
							x2=-x2;	y2=-y2;
							x3=-x3;	y3=-y3;
							draw(x1,y1,x2,y2,x3,y3);
							break;
						case 6:    
							break;
		//					exit(1);
					}
					system("cls");                                
					printf("Reflected points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)\n",x1,y1,x2,y2,x3,y3);
				}
				while(re_op!=6);
			case 6:
				exit(1);
			default:			
				cout<<"Wrong option\n";
			}
//		system("cls");
		cout<<"\nTransformation\n\t 1.Translation\n\t 2.Rotation\n\t 3.Scaling\n\t 4.Shearing\n\t 5.Reflection\n\t 6.Exit\n";
		cout<<"Enter operation:\t"; 
		cin>>op;
	}
	getch();
	closegraph();
	
	return 0;
}