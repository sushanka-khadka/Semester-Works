//Write a program to determine whether the given grammar is in CNF or Not.

//Chomsky Normal Form(CNF)
//--if every produciton are either one of two term : A->BC(variable) or A-> a(terminal)

#include<iostream>
//#include <string>
//#include <sstream>
using namespace std;

int is_cnf(string cnf){
	int str_len=cnf.size();
	if(str_len<3 || !isupper(cnf[0]) || cnf[1]!= ':'){
//		cout<<"rejected 1";
		return 0;
//		exit(1);
	}
	else{
//		cout<<"pass form 1";
		int index=1;
		for(int i=2;i<=str_len;i++){	// last string is assumed as : 
			if(cnf[i] ==':' || i==str_len){	// : or end of str
				int len =i-1-index;
				if(len>2 || len<=0){	// e production also
//					cout<<"len"<<len<<endl;
//					cout<<"rejected 2";
					return 0;
//					exit(1);
				}
				else{
//					cout<<"pass form 2\n";
//					cout<<"len"<<len<<endl;
					for(int j=index+1;j<i;j++){
						if( (len==2 && !isupper(cnf[j])) || (len==1 && !islower(cnf[j])) ){
//							cout<<"rejected 3";						
							return 0;
//							exit(1);
						}
					}
					index=i;
//					cout<<"index:  "<<index<<endl;			
				}
			}
		}
		
	}
//	cout<<"accepted";
	return 1;
}

int main(){
//	string cnf="A:AA:a";	
	int n;
	bool status=true;
	string item;
	cout<<"Chomsky Normal Form(CNF)\n";
	cout<<"How many productions? ";
	cin>>n;
	cout<<"Enter grammar(eg> S:AA:a)\n";
	for(int i=0;i<n;i++){
		cout<<"production: ";
		cin>>item;
		if (!is_cnf(item))
			status=false;
	}
	if(status)
		cout<<"\nGiven grammar is a Chomsky Normal Form.";
	else
		cout<<"\nGiven grammar is not a Chomsky Normal Form.";	
	
    return 0;
}

/* CNF shouldn't have:
e production: e
unit production:  only one non-terminal
useless symbols: (non-generating= (can't produce terminal only) and non-reachable=(can't be produced starting form start node)
*/