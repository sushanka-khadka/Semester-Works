#include<iostream>
#include<graphics.h>
using namespace std;
;
void plot(int x,int y){
	setfillstyle(SOLID_FILL,YELLOW);
	circle(x,y,4);
    floodfill(x,y,15);
}
    
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(getmaxwidth()/2,getmaxheight()/2);
	int op;
	float x=20,y=30;
	cout<<"Enter operation:\t";
	cin>>op;
	while(1){
		switch(op){
			case 1:// translation				
				plot(x,y);  
				system("cls");				
				printf("Translated points: (%.2f,%.2f)\n",x,y);
				break;
			case 2://rotation
				system("cls");			
				break;
			case 3://scaling
				plot(x,y);
				system("cls");
				printf("Scaled points: (%.2f,%.2f)\n",x,y);
				break;
			case 4:// Shearing 	
				system("cls");
				plot(x,y);
				printf("Sheared points: (%.2f,%.2f)\n",x,y);
				break;
			case 5:// reflection
//				int re_op;
//				while(2){		
				
				system("cls");				
				
				do{	
					cout<<"Reflection about:\n";
					cout<<"\t1.line(y-axis) x=0\n\t2.line(x-axis) y=0\n\t3.line y=x or x=y\n\t4.ine y=-x\n";
					cout<<"\t5.line perpendicular to origin\n\t6.Home ";			
					cout<<"\nEnter operation:\t";
					cin>>op;
					switch(op){
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
				}while(op!=6);
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
    
//	getch();
	closegraph();
	
	return 0;
}