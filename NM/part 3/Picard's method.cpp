#include<iostream>
#include<math.h>
using namespace std;
//#define y1(x) 2+x-2/3*pow(x,3);
//#define y2(x) 2+x+pow(x,2)-2/3*pow(x,3)+pow(x,4)/4
//#define y3(x) 2+x+pow(x,2)-pow(x,4)/3 -pow(x,5)/15

#define y1(x) x-pow(x,3)/3
#define y2(x) x+pow(x,2)/2-pow(x,3)/3-pow(x,4)/12
#define y3(x) x+pow(x,2)/2-pow(x,3)/6-pow(x,4)/12-pow(x,5)/60

//#define y1(x) x+pow(x,2)/2
//#define y2(x) x+pow(x,2)/2+pow(x,3)/3+pow(x,4)/8
//#define y3(x) x+pow(x,2)/2+pow(x,3)/3+pow(x,4)/8+pow(x,5)/15+pow(x,6)/48

bool error(float ny,float y,float error){
//	float E_cal =abs(ny-y)/abs(ny);
	float E_cal =abs(y-ny)/abs(y);
//	cout<<"Error \t"<<E_cal<<endl;
	if(E_cal<=error)
		return true;
	else 
		return false;
}
int main(){
	float x,x0,y0,y,ny,er,E_Cal;
	x0=0,y0=1,x=0.2;
	er=0.0001;
	cout<<"Enter initial values of x & y\t";
	cin>>x0>>y0;
	cout<<"Enter point at which function to be evaluated:\t";
	cin>>x;
	cout<<"Enter accuracy level:\t";
	cin>>er;
//	x0=0,y0=2,x=0.4;
//	er=0.001;
	
	while(1){
//		y=y0;
		cout<<"First approximation\n";
		ny=y0;
		y=y0+y1(x);	// 1st approximation
//		cout<<"\tny:\t"<<ny<<endl;
		cout<<"\ty:\t"<<y<<endl;
//		E_cal =abs(ny-y)/abs(ny);
		if(error(ny,y,er))
			break;
		else{		
			cout<<"Second approximation\n";
			ny=y;
			y=y0+y2(x);	// 2nd approximation
//			cout<<"\tny:\t"<<ny<<endl;
			cout<<"\ty:\t"<<y<<endl;
			if(error(ny,y,er))
				break;
			else{
				cout<<"Third approximation\n";
				ny=y;	
				y=y0+y3(x);	//3rd approximation					
//				cout<<"ny:\t"<<ny<<endl;
				cout<<"\ty:\t"<<y<<endl;
				if(error(ny,y,er))
					break;
				else				
					break;
			}
		}

	}
	printf("Function value at x=%.2f is:%6f\n\n",x,y);
	
	return 0;
			
	
		
}

//#define y1(x) 1+x-pow(x,3)/3
//#define y2(x) 1+x+pow(x,2)/-pow(x,3)/3-pow(x,4)/12
//#define y3(x) 1+x+pow(x,2)/6-pow(x,3)/6-pow(x,4)/12-pow(x,5)/60