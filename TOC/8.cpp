//PDA that accept palindrome binary string of odd length

#include<iostream>
using namespace std;

bool is_odd_palindrome(string input){
	char stack[15];
	int top =-1;
	if(input.size()%2==0){		
		return false;	// not an odd string
	}
	
	int mid= int(input.size()/2);	// middle input is skipped 	
	for(int i=0;i<mid;i++){	//before mid
		top++;
		stack[top]=input[i];	// push to stack
	}
	
	for(int i=mid+1;i<input.size();i++){	// after mid
		if(stack[top] == input[i])
				top--;	// pop			
			else
				return false;	// doesn't match to stack			
	}
		
	if(top==-1)
		return true;	// stack empty-> accepted	
	else
		return false; // rejected	
}


int main(){	
//	string input ="ababa";
	string input;
	cout<<"PDA that accept odd binary palindrome\n";
		
	cout<<"Enter string: ";
	cin>>input;
	for(char c:input){
		if(c!= '0' && c!='1'){
			cout << "Invalid input! Only binary characters (0 or 1) are allowed.\n";
        	return 1;
		}
	}
	cout<<"\nStatus:" ;
	if(is_odd_palindrome(input))
		cout<<"Binary Odd Palilndorme";
	else
		cout<<"Not an Binary Odd Palilndorme";		
	
	return 0;
}