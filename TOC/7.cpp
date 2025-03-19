//7. Write a program to design PDA that accept (a^n b^n,n>=1)
// Push Down Approach
#include<iostream>
#define max 15
using namespace std;

int main(){
	char stack[max];
	int top=-1;
	stack[0]={'z'};	// assume as empty
	top++;
	string input;
	cout<<"PDA that accept (a^n b^n,n>=1)\n";
	cout<<"Enter string: ";
	cin>>input;
	int i=0;	
	while(i<input.size()){
		while(input[i]=='a'){
			i++,top++;
			stack[top]='a';
		}
		while(input[i]=='b'){
			if (stack[top] == 'a')
				i++,top--;			
			else{
				cout<<"String Rejected";
				return 0;
			}
		}
		if(i<input.size()){
			cout<<"String Rejected.";
			return 0;			
		}			
	}
	cout<<"\ntop: "<<top;
	cout<<"\nstack: "<<stack[top]<<endl;
	if (stack[top]=='z')
		cout<<"String Accepted";	
	else
		cout<<"String Rejected(pattern unmatched)";
					
	return 0;
}

