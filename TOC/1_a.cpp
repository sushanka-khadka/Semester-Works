//Write a program to design the following DFA
//a. To accept the binary string that start with “0” and ending with “1”

#include<iostream>
using namespace std;
int main() {
	cout<<"DFA Accepting Binary Strings Start with 0 and End with 1";
	int state = 0;
	char input[10];
	cout<<"\nEnter the binary string :";
	gets(input);
	
	for(int i=0;i<strlen(input);i++){
		if(input[i]!='0' && input[i]!='1'){
			cout<<"Not a Binary string";
			return 1;
		}
	}
	
	for(int i=0; i<strlen(input); i++) {
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
		cout<<"Q"<<state<<",";
	}
	if(state == 2) {
		cout<<"Accepted";
	} else {
		cout<<"Rejected";
	}
	return 0;
}
