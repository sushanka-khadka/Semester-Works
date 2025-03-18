// program to perform binary addition
#include<iostream>
using namespace std;

int main(){
	long bin_1,bin_2;
	cout<<"enter two binary numbers:	";
	cin>>bin_1>>bin_2;
//	bin_1=1011;
//	bin_2=1010;
	
	int rem_1=0,rem_2=0;
	int bin,i=0;

//	bin_1 /=10;
//	rem_1=bin_1%10;
//	bin_2 /=10;
//	rem_2=bin_2%10;
//	bin+= 
	int sum[12],rem=0;
	while (bin_1!=0 || bin_2!=0){	
		sum[i++]=(bin_1%10 + bin_2%10 +rem)%2;
		rem=(bin_1%10 + bin_2%10 +rem)/2;
		bin_1 /=10;
		bin_2 /=10;
	}
	if (rem !=0){
		sum[i+1]=rem;
		--i;
	}
	
	printf("sum of two binary numbers:\n");
	while(i>=0){
		printf("%d",sum[i--]);
	}
		
		
//	sum[i++]=sum;
	
}