//To accept even length of binary string

#include<iostream>
using namespace std;

int main(){
	int state=0;
	char input[10];
	printf("DFA Accepting Binary Strings of Even length");
	cout<<"\nEnter Binary input: ";
	cin>>input;
	
	for(int i=0;i<strlen(input);i++){
		if(input[i]!='0' && input[i]!='1'){
			cout<<"Not a Binary string";
			return 1;
		}
	}	
	
	cout<<"Path: Q"<<state<<",";
	for (int i=0;i<strlen(input); i++){
		if (state == 0)		
			state=1;
		else if(state==1)
			state= 2;
		else if(state == 2)
			state= 1;
		cout<<"Q"<<state<<',';
	}
	cout<<"\nStatus: ";
	if (state==2)
		cout<<"Accepted";
	else
		cout<<"Rejected";	
	return 0;
}