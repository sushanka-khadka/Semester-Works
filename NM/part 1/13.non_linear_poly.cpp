
//WAP to implement nonlinear least square method using polynomial model 
//(nonlinear regression with polynomial model) and test for some data. 
	

	//x	3	4	5	6	7	9	10
	//f	7	8	10	11	10	9	8

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int m,n;
    float X,reg=0;
    float a[20][20],b[20],z[20],x[20],fx[20];
    float sum,pivot,term;
    cout<<"Enter the number of data points: ";
    cin>>n;

    cout<<"Enter the degree of polynomial to be fitted: ";
    cin>>m;

    cout<<"Enter the value of x and fx";
    cout<<"\nx       fx\n";
    for(int i=0;i<n;i++){        
        cin>>x[i]>>fx[i];
    }
    cout<<"Enter at which point reg.to be calc..	";
    cin>>X;

    //Construction of coefficient matrix
    for( int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            sum = 0;
            for(int k=0; k<n; k++ ){
                sum=sum+pow(x[k],i+j);
            }
            a[i][j]=sum;
        }
    }

    //COnstruction of the RHS vectors
    for(int i=0; i<=m; i++){
        sum = 0;
        for(int k=0; k<n; k++ ){
            sum=sum+fx[k]*pow(x[k],i);
        }
        b[i]=sum;
    } 

    //Forward Elimination
    for(int k=0;k<m;k++)
    {
        pivot=a[k][k];
        if(pivot<0.000001){
            cout<<"\nMethod failed!!\n";
        }
        else{
            for(int i=k+1;i<=m;i++){
                term=a[i][k]/pivot;
                for(int j=0; j<=m; j++){
                    a[i][j]=a[i][j]-a[k][j]*term;
                }
                b[i]=b[i]-b[k]*term;
            }
        }
    }
    z[m]=b[m]/a[m][m];

    //Backward substitution
    for(int i=m-1;i>=0;i--){
        sum=0;
        for(int j=i+1;j<=m;j++){
            sum=sum+a[i][j]*z[j];
        }
        z[i]=(b[i]-sum)/a[i][i];
    }

	reg	= 	z[0] + z[1]*X;	
    cout<<"\nThe polynomial of regression is: \n";
	cout<<"y = "<<z[0]<<" + "<<z[1]<<" x ";
    for(int i=2; i<=m; i++){
        cout<<"+ "<<z[i]<<" x^"<<i;
        reg += z[i]*pow(X,i);
    }

	cout<<"\n\t Regression value at x= "<<X<<" is:"<<reg<<endl<<endl;


return 0;
}