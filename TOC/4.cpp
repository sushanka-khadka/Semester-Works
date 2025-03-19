//4. Write a program to remove the left recursion from the given left recursive grammar.

//(Removing Left Recursion)

#include<iostream>
using namespace std;

int main(){
	string cfg;
	cout<<"Enter a grammar (eg. A:A0.1) : ";
	cin>>cfg;
	
	if(cfg[0] != cfg[2]){
		cout<<"The Grammar is not Left Recursive.";
	}
	else{
		int len= cfg.size();
		int index;
		for(int i=0;i<len;i++){
			if (cfg[i] =='.'){
				index =i;
				break;
			}
		}			
		cout<<"\nGrammar after removing left recusion:\n";
		cout<<"$ referes to epsilon.\n";
		cout<<"\tA:";		
		for(int i=index+1;i<len;i++){
			cout<<cfg[i];
		}
		cout<<"A'"<<endl;
		cout<<"\tA':";
		for(int i=3;i<index;i++){
			cout<<cfg[i];
		}
		cout<<"A'.$"<<endl;		
	}
	
	return 0;
}


//a grammar is said to be left recursive if it has one of the productions of the form: A--> A@

/* let alpha =a beta=b
if (A--> Aa|B)
	left recursion: A-->BA'
	A'--> aA'| E

*/