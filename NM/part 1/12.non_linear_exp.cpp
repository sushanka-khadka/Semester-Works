//WAP to implement nonlinear least square method using exponential model 
//(nonlinear regression with exponential model) and test for some data.	
//	x	2		4		6		8		10	
//	y	4.077	11.084	30.124	81.697	222.62
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

//float x[5]={2,4,6,8,10};
//float y[5]={4.077,11.084,30.124,81.697,222.62};

float x[6]={0.0,1.0,3.0,5.0,7.0,9.0};
float y[6]={1.00,0.891,0.708,0.562,0.447,0.355};

void Non_Linear_exp(float X){
	int n=6;
	float sum_x=0,sum_x2=0;
	float log_y[n];
	float sum_log_y=0;
	float x_log_y=0;	
	
	for(int i=0;i<n;i++){
		sum_x+=x[i];
		sum_x2+=x[i]*x[i];
		log_y[i]= log(y[i]);
		sum_log_y += log_y[i];
		x_log_y	+= x[i]*log_y[i];
	}

	float b=(n*x_log_y-sum_x*sum_log_y)/(n*sum_x2 - sum_x*sum_x);
	float R= sum_log_y/n - b*sum_x/n;
	float a= exp(R);
		
	cout<<setw(5)<<"i"<<setw(10)<<"x"<<setw(10)<<"y"<<setw(10)<<"log(y)"<<setw(15)<<"x logy"<<setw(15)<<"x^2"<<endl;
	cout <<setw(3)<<" "<< string(65, '-') <<endl;

	for(int i=0;i<n;i++){
		cout<<setw(5)<<i+1<<setw(10)<<x[i]<<setw(10)<<y[i]<<setw(10)<<log_y[i]<<setw(15)<<x[i]*log_y[i]<<setw(15)<<x[i]*x[i]<<endl;
	}
	cout<<"TOTAL"<<string(65,'*')<<endl;	
	cout<<setw(5)<<n<<setw(10)<<sum_x<<setw(10)<<" "<<setw(10)<<sum_log_y<<setw(15)<<x_log_y<<setw(15)<<sum_x2<<endl;
	
	cout<<"\nb	"<<b<<endl<<"R	"<<R<<endl<<"a	"<<a<<endl;
	cout<<"\nRequired Regression equation is : y = ae^(bx)"<<endl;
	cout<<"\t y = "<<a<<"* e^("<<b<<"*x)"<<endl;
	cout<<"Value at x= "<<X<< " is:	"<<a*exp(b*X)<<endl;
	
	
}

int main(){
	float x;
	cout<<"Enter the value of a point:  ";
	cin>>x;
	Non_Linear_exp(x);
	return 0;
}
