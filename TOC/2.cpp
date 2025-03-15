//Write a program to show the transition state for string “0000001101” and “100000010” for DFA in 1(a)
//To accept the binary string that start with “0” and ending with “1”

#include<iostream>
using namespace std;

int dfs(string input){
	int state = 0;
			
//	getline(cin,input);	// reads until new line
//	cin>>input;	// reads till whitespace
	
	cout<<"\n\nFor input: "<<input;
	int i;
	cout<<"\n\tPaths: Q"<<state<<',';
	for(i=0; i<input.size(); i++) {
		char ch = input[i];
		if(state == 0) {
			if(ch == '0') {
				state = 1;
			} else {
				state = 3;
			}
		} else if(state == 1) {
			if(ch == '0') {
				state = 1;
			} else {
				state = 2;
			}
		} else if(state == 2) {
			if(ch == '0') {
				state = 1;
			} else {
				state = 2;
			}
		} else if(state == 3) {
			state = 3;
		}
		cout<<"Q"<<state<<',';
	}
	cout<<"\n\tStatus: ";
	if (state==2)	// final state
		cout<<"Accepted";
	else
		cout<<"Rejected";	
	return 0;
	
}

int main() {
	string input_1= "0000001101",input_2= "100000010";	
	
	cout<<"DFA Accepting Binary Strings Start with 0 and End with 1";
	dfs(input_1);
	dfs(input_2);
}
