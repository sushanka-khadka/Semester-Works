// Factorial using Recursion 
#include<stdio.h>

long fact(long n){
	if(n==0 || n==1)
		return 1;
	else
		return n* fact(n-1);
}

void main(){
	int f;
	printf("Enter number to calculate factorial: ");
	scanf("%d",&f);
	if(f<0)
		printf("factorial Not defined");
	else{
		long ans=fact(f);
		printf("%d",ans);	
	}
}