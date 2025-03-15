//To accept binary string such that it never ends with 1

#include<iostream>
using namespace std;

int main(){
	int state=0;	// start node
	char input[20];
	printf("DFA Accepting Binary Strings that never ends with 1");
	cout<<"\nEnter Binary input: ";
	cin>>input;
	int length=strlen(input);
	bool valid_input =true;
	for (int i=0;i<length;i++){
		if (input[i] != '0' && input[i] != '1')
			valid_input=false;
	}
	if (valid_input){
		cout<<"Path: Q"<<state<<",";
		for (int i=0;i<length; i++){
			char ch=input[i];
			if (state == 0){
				if (ch =='0')
					state=1;
			}		
			else if(state==1){
				if (ch =='0')
					state=1;
				else
					state=0;			
			}				
			cout<<"Q"<<state<<',';
		}
		cout<<"\nStatus: ";
		if (state==1)	// final state
			cout<<"Accepted";
		else
			cout<<"Rejected";	
	}
	else
		cout<<"Not a valid binary input";
	return 0;
}