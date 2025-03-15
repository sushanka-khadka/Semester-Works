//Consider the following grammar for palindrome binary string, and write a program to show
//the leftmost derivation for “10101”

// palindrom binary string

/*
S --> 0S0 | 1S1 | 0 | 1 | E
that is:
S--> 0S0
S--> 1S1
S--> 0
S--> 1
S--> E
*/

#include<iostream>
using namespace std;

int leftmost_derivation(const string & input){
	cout << "Leftmost derivation for \"" << input << "\":" << endl;
	int n= input.size();
	string derivation= "S";
	if (n==0){
		cout << "S -> E" << endl;
        return 0;
	}
	// left most derivation
	for(int i=0;i<n/2;i++){
		if(input[i]==input[n-i-1] && input[i]=='0')
			derivation.replace(derivation.find("S"),1,"0S0");
		else if(input[i] == input[n-i-1] && input[i] == '1')
			derivation.replace(derivation.find("S"),1,"1S1");
		else{
			cout<<"The string is not palindrome.";
			return 0;
		}
		cout<<derivation<<endl;
	}
	
	// if length of string is odd
	if (n%2 == 1){
		if (input[n/2] == '0')
			derivation.replace(derivation.find("S"),1,"0");
		else if(input[n/2] =='1')
			derivation.replace(derivation.find("S"),1,"1");
	}
	
	// finally replace the remaining S with epsilon(e)
	int pos = derivation.find("S");
    if (pos != string::npos) 
        derivation.replace(pos, 1, " E ");	
	cout<<derivation<<endl;
	return 0;
}

int main(){
	string input= "10101";
	leftmost_derivation(input);
	return 0;
}