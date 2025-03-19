//TM that accept {a^n b^n, n<=1}

#include<iostream>
using namespace std;

int main(){
	//	string bin="aabb";
	string bin;
	cout<<"Turing Machine that accept eq no of a followed by eq no of b\n\n";

	cout<<"Enter any binary string: ";
	cin>>bin;	
	bin[bin.size()]='$';	// refers to end of input	
	
	for(int i=0;i<bin.size();i++){
		if (bin[i] == 'a'){
			bin[i]= 'x';
			while(bin[i] !='$'){
				i++;
				if(bin[i] == 'b'){
					bin[i] ='y';
					break;
				}
				if (i== bin.size()){
					cout<<"String Rejected";
						exit(1);
				}
			}
			while(bin[i]!= 'x'){
				i--;
			}
		}
		else if(bin[i] == 'y'){
			while(bin[i] != '$'){
				if(bin[i]!='x' && bin[i]!='y'){
					cout<<"String Rejected";
						exit(1);
				}
				i++;			
			}
			cout<<"String Accepted";
		}
		else{
			cout<<"String Rejected";
			break;
		}		
	}	
	return 0;
}