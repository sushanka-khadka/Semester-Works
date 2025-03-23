//WAP to implement Lagrange Interpolation and test for some data.  
// e^x
//x	0	1		2		3	
//e^x 1	2.7183	7.3891	20.0855
#include<iostream>


using namespace std;

void lagrange(int n,float x){
	int a[5]={0,1,2,3};
	float f[5]={1,2.7183,7.3891,20.0855};
	float l[4];
	float p=0;
//	int n=2;	// second order polynomial
	for (int i=0;i<=n;i++){
		l[i]=1;
		for (int j=0;j<=n;j++){		
			if(j!=i)			
				l[i]	*= (x-a[j])/(a[i]-a[j]);
	//			l[0]	*= (x-a[j])/(a[0]-a[j]])			
		}
		cout<<"l"<<i<<":  "<<l[i]<<endl;
		p += l[i]*f[i];
	}
	cout<<" p2(x) :  "<<p<<endl;
	cout<<" The respective order interpolation at x="<<x<<" is :	"<<p<<endl;
}
	
int main(){
	int n;
	float x;
	cout<<"enter which order of interpolation:(<= 3) ";
	cin>>n;
	cout<<"Enter the value : ";
	cin>>x;
	lagrange(n,x);
	return 0;
}