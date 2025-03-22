// Menu driven program for transformation

#include<iostream>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7
using namespace std;

void draw(float x1,float y1,float x2,float y2,float x3,float y3){
	float x_or=getmaxx()/2,y_or=getmaxy()/2,max=getmaxy();
	line(x1+x_or,max-(y1+y_or),x2+x_or,max-(y2+y_or));
	line(x3+x_or,max-(y3+y_or),x2+x_or,max-(y2+y_or));
	line(x1+x_or,max-(y1+y_or),x3+x_or,max-(y3+y_or));	
	
	floodfill((x1+x2+x3+3*x_or)/3,max-(y1+y2+y3+3*y_or)/3,15);			
}
int main(){
	float x,y;
	int op,gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(getmaxwidth()/2,getmaxheight()/2,"SUSHANKA");
	float x1,x2,x3,y1,y2,y3;
	cout<<"Transformation\n\t 1.Translation\n\t 2.Rotation\n\t 3.Scaling\n\t 4.Shearing\n\t 5.Reflection\n\t 6.Exit\n";
//	cout<<"Enter points:(x1,y1,x2,y2,x3,y3) ";
//	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	x1=15,x2=45,x3=30,y1=15,y2=15,y3=30;
	printf("Trinagle(%.2f,%.2f,%.2f,%.2f,%.2f,%.2f)\n",x1,y1,x2,y2,x3,y3);
	
	outtextxy(getmaxx()/2-30,getmaxy()/2-30,(char*)"Origin");	
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	
	draw(x1,y1,x2,y2,x3,y3);
	cout<<"Enter operation:\t";
	cin>>op;
	while(1){
		switch(op){
			case 1:// translation			
				float tx,ty;
				cout<<"Enter translation distance (tx,ty): ";
				cin>>tx>>ty;
				x1+=tx; x2+=tx; x3+=tx; y1+=ty; y2+=ty; y3+=ty;
				draw(x1,y1,x2,y2,x3,y3);
				system("cls");								
				printf("Translated points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)",x1,y1,x2,y2,x3,y3);
				break;
			case 2://rotation
				float a;
				cout<<"Enter angle(deg) to rotate anti-clockwise(+ve) or clockwise(-ve): ";
				cin>>a;
				a=pi/180*a;
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
				x2=x2+shx*y2;
				x3=x3+shx*y3;				
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
//				int re_op;			
				system("cls");
				do{	
					cout<<"Reflection about:\n";
					cout<<"\t1.line(x-axis) y=0\n\t2.line(y-axis) x=0\n\t3.line y=x or x=y\n\t4.ine y=-x\n";
					cout<<"\t5.line perpendicular to origin\n\t6.Home ";			
					cout<<"\nEnter reflection operation:\t";
					cin>>op;
					switch(op){
						case 1://	reflecton about a line(x-axis) y=0
							x1=x1;	y1=-y1;
							x2=x2;	y2=-y2;
							x3=x3;	y3=-y3;
							draw(x1,y1,x2,y2,x3,y3);						
							break;							
						case 2: //	reflecton about a line(y-axis) x=0
							x1=-x1;	y1=y1;
							x2=-x2;	y2=y2;
							x3=-x3;	y3=y3;
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
							x1=-x1;	y1=-y1;
							x2=-x2;	y2=-y2;
							x3=-x3;	y3=-y3;
							draw(x1,y1,x2,y2,x3,y3);
							break;
						case 6:    
							break;
						default:
						cout<<"!!!Wrong option!!!\n";
					}
					system("cls");                                
					printf("Reflected points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)\n",x1,y1,x2,y2,x3,y3);
				}
				while(op!=6);
				break;
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