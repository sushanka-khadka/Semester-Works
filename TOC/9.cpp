// TM that accept palindrome binary string of even length 

#include<iostream>
using namespace std;

int main(){
//	string bin="10111101" ;
	string bin;
	cout<<"TM that accept palindrome binary string of even length\n";
	cout<<"Enter any binary string: ";
	cin>>bin;	
	bin[bin.size()]='$';	// refers to end of input	
	
	for(int i=0;i<bin.size();i++){
		if (bin[i] == '$'){
			cout<<"String Accepted! "<<endl;
			break;
		}
		else if(bin[i] == '0'){
			bin[i]= '*';
//			i++;
			
			while(bin[i] != '$')
				i++;
			i--;
			
			if(bin[i] == '0'){
				bin[i]= '$';				
			}
			else{
				cout<<"String Rejected not an even binary palindrome";
				break;
			}
			
			while(bin[i] != '*')
				i--;
//			i++; no need cuz for loop will increase i
		}
		else{	
			bin[i]= '*';
			while(bin[i] != '$')
				i++;
			i--;
			
			if(bin[i] == '1')
				bin[i]= '$';
			else{
				cout<<"String Rejected not an even binary palindrome!!";
				break;
			}
			
			while(bin[i] != '*')
				i--;
//			i++;
		}
	}
	
	cout<<"\nString State: ";
	for(int i=0;i<bin.size();i++){
		cout<<bin[i];
	}
	
	return 0;
}