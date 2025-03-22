// Menu Driven program for Transformation of 3D objects

#include<iostream>
#include<graphics.h>
#include<math.h>
#define pi 22.0/7
using namespace std;

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	
	float l,t,r,b,d,top_flag;		
//	cout<<"Enter left,top,right, bottom and depth values: ";
//	cin>>l>>t>>r>>b>>d;
	l=50,t=20,r=170,b=150,d=15,top_flag=1;
	outtextxy(l-20,t-20,(char*)"Object");
	bar3d(l,t,r,b,d,top_flag);
	int op; 
	
	while(1){
		cout<<"Transformation\n\t 1.Translation\n\t 2.Rotation\n\t 3.Scaling\n\t 4.Shearing\n\t 5.Reflection\n\t 6.Exit\n";
		cout<<"Enter operation:\t";
		cin>>op;	
		switch(op){
			case 1:// translation			
				float tx,ty,tz;
				cout<<"Enter translation vector (tx,ty): ";
				cin>>tx>>ty;
//				x1+=tx; x2+=tx; x3+=tx; y1+=ty; y2+=ty; y3+=ty;
				l+=tx;r+=tx;	t+=ty;b+=ty;				
				outtextxy(l-20,t-20,(char*)"Image");
				bar3d(l,t,r,b,d,top_flag);
//				system("cls");								
//				printf("Translated points: \n\t(x1,y1)=(%.2f,%.2f)\n\t(x2,y2)=(%.2f,%.2f)\n\t(x3,y3)=(%.2f,%.2f)",x1,y1,x2,y2,x3,y3);
				break;
			case 2: 	// Rotation 
				float a;
				do{
					system("cls");
					cout<<"Rotation about\n\t 1. X-axis (Pitch)\n\t 2. Y-axis (Yaw) \n\t 3.Z-axis (Roll)\n4.Back";
					cout<<"Enter operation: ";
					cin>>op;
					cout<<"Enter angle(deg) to rotate anti-clockwise(+ve) or clockwise(-ve): ";
					cin>>a;
					a=pi/180*a;
					switch(op){						
						case 1:// pitch
							l=l;r=r;
							b+=y*cos(a) -z*sin(a);
							t+=y*cos(a) -z*sin(a);
//							y1+=y*cos(a) -z*cos(a);
//							z1+=y*sin(a); +z*cos(a);
							break;
						case 2:	// Yaw
							l+=x*cos(a) +z*sin(a);
//							x1+=x*cos(a) +z*sin(a);
//							z1+=z*cos(a) -x*sin(a);
							break;
						case 3:	// Roll
							l+=x*cos(a) -y*sin(a);
							r+=x*cos(a) -y*sin(a);
							t+=x*sin(a) +y*cos(a);
							b+=x*sin(a) +y*cos(a);
							
//							x1+=x*cos(a) -y*sin(a);
//							y1+=x*sin(a) +y*cos(a);
							break;
						case 4:
							break;
						default:
							cout<<"!!!Wrong Option!!!\n";				
					}
					outtextxy(l-20,t-20,(char*)"Image");
					bar3d(l,t,r,b,d,top_flag);
				}while(op!=4);			
				break;
			
			case 3:	// Scaling
				float sx,sy,sz;
				do{
				system("cls");
				cout<<" 1.Uniform && Differential Scaling\n 2. Fixed point Scaling\n 3.Back\n";
				// uniform scaling-> preseves the shape of the object (size differs)
				// differential scaling -> soesn't preserve shape 
				cout<<"Enter operation: ";
				cin>>op;
				switch(op){						
					case 1:
						float sx,sy,sz;
						cout<<"Enter Scaling factor(sx,sy,sz): ";
						cin>>sx>>sy>>sz;
						l*=sx;r*=sx;	t*=sy;b*=ty;	d*=sz;
						cleardevice();
						bar3d(l,t,r,b,d,top_flag);
						break;
					case 2:
						cout<<"Scaling w.r.t. selected fixed position\n";
						break;
					case 3:
						break;
					default:
						cout<<"!!!Wrong Option!!!\n";
				}
				}while(op!=3);
				break;
					
				
			case 5:// Reflection 
				do{
				system("cls");
				cout<<"Reflection about:\n";
				cout<<"\t1.relative to x-axis (z-x plane) \n\t2.relative to y-axis (yz plane) "
				"\n\t3.relative to z-axis (xy plane)\n\t 4. Back\n";
				
				cout<<"\nEnter reflection operation:\t";
				cin>>op;
				switch(op){
					case 1: //x-axis(zx plane)
//						y=-y;
						t=-t;	b=-b;
						cleardevice();
						bar3d(l,t,r,b,d,top_flag);
						break;
					case 2: // y-axis(yz plane)
//						x-=x;
						l=-l;	r=-r;
						cleardevice();
						bar3d(l,t,r,b,d,top_flag);
						break;
					case 3:	// z-axis (xy plane)
//						z-=z;
						bar3d(l,t,r,b,d,top_flag);
						break;
					case 4:
						break;
					default:
						cout<<"!!!Wrong Option!!!";
				}
				}while(op!=4);
				break;			
						
			case 6:
				exit(1);
			default:
				cout<<"wrong option\n";
		}
	}
	outtextxy(100,100,'Not Complete');
	getch();
	closegraph;
}