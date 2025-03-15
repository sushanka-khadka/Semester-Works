//To accept binary string where “0” is always followed by “1”

#include<iostream>
using namespace std;

int main(){
	int state=0;	// start node
	char input[10];
	printf("DFA Accepting Binary Strings where 0 is always followed by 1");
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
		char ch=input[i];
		if (state == 0){
			if (ch =='0')
				state=1;
			else
				state=2;
		}		
		else if(state==1){
			if (ch =='0')
				state=3;
			else
				state=2;			
		}
		else if(state == 2){
			if (ch =='0')
				state=1;
//			else
//				state=2;
		}
//		else if(state==3){
//			state=3;
//		}
			
		cout<<"Q"<<state<<',';
	}
	cout<<"\nStatus: ";
	if (state==2)	// final state
		cout<<"Accepted";
	else
		cout<<"Rejected";	
	return 0;
}