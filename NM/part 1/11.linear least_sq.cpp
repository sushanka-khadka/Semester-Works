//Implementing least square methods for curve fitting (regression analysis). 
//a) WAP to implement linear least square method (linear regression) and test for some data. 

#include<iostream>
#include<iomanip>
using namespace std;

	//x	4		7		11		13		17
	//f	2		0		2		6		7
	
	float x[5]={4,7,11,13,17};
	float y[5]={2,0,2,6,7};	

void Linear(float X){
	int n=5;
	float sum_x=0,sum_x2=0,sum_y=0,xy=0;
	float m_x,m_y;
	for(int i=0;i<n;i++){
		sum_x+=x[i];
		sum_x2+=x[i]*x[i];
		sum_y+=y[i];
		xy +=x[i]*y[i];	
	}
	m_x=sum_x/n;
	m_y=sum_y/n;	
	float b= (n*xy-	sum_x*sum_y)/(n*sum_x2-sum_x*sum_x);	
	float a= m_y -b *m_x;
	
	
	cout<<setw(5)<<"i"<<setw(10)<<"x"<<setw(10)<<"y"<<setw(10)<<"x^2"<<setw(15)<<"xy"<<endl;
	cout <<setw(3)<<" "<< string(50, '-') <<endl;

	for(int i=0;i<n;i++){
		cout<<setw(5)<<i+1<<setw(10)<<x[i]<<setw(10)<<y[i]<<setw(10)<<x[i]*x[i]<<setw(15)<<x[i]*y[i]<<endl;
	}
	cout<<"TOTAL"<<string(50,'*')<<endl;	
	cout<<setw(5)<<n<<setw(10)<<sum_x<<setw(10)<<sum_y<<setw(10)<<sum_x2<<setw(15)<<xy<<endl;
	
	cout<<"mean x  "<<m_x<<endl;
	cout<<"mean y  "<<m_y<<endl;
	
	
	cout<<"b	"<<b<<endl;
	cout<<"a	"<<a<<endl;
	
	cout<<"\nRequired Regression equation is : y = bx+ a"<<endl;	
	cout<<"\t y = "<<b<<" x + "<<a<<endl;
	cout<<"Value at x= "<<X<< " is:	"<<b*X+a<<endl;	
}


int main(){ 	
	float x;
	cout<<"Enter the value of a point:  ";
	cin>>x;	
	Linear(x);
}
