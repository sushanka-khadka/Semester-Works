//6. Write a program to determine whether the given grammar is in Right Linear or Left Linear.

//left linear = non-terminal at left most
//right linear = non-terminal at right most

# include<iostream>
#include<string>
using namespace std;

int linear(string grammar[],const int& n){
	bool left=false,right=false;
	for(int g=0;g<n;g++){
		string cnf=grammar[g];
		
		bool stop=false;
		int str_len=cnf.size();
		if(str_len<3 || !isupper(cnf[0]) || cnf[1]!= ':'){
			cout<<"Not a Grammar";
			return 0;
		}
		else{
			int index=1;		
			for(int i=2;i<=str_len;i++){	// last string is assumed as : 
				if(cnf[i] ==':' || i==str_len){	// : or end of str
					int len =i-1-index;
					
					string slice_str= cnf.substr(index+1,len);					
					if ((len>2) || (len==1 && isupper(slice_str[0])) ||
					 (len==2 && (islower(slice_str[0]) && islower(slice_str[1]) || isupper(slice_str[0]) && isupper(slice_str[1])) )){
						left=false,right=false;
						stop=true;
						break;	// single variable and double terminal is invalid						
					}
					else if(len == 2){	// terminal and variable										
						if (isupper(slice_str[0]))
							left= true;						
						else if(isupper(slice_str[slice_str.size()-1]))
							right=true;
					}
					index=i;
				}			
			}
		}
		if (stop)
			break;	// exits the outer loop
		
	}
	cout<<"\nGiven Grammar: \n";

	if (left && right )
		cout<<"Not a Regular Grammar. It can be either left or right linear but not both."<<endl;
	else if(left)
		cout<<"Left Linear Grammar";
	else if(right)
		cout<<"Right Linear Grammar";
	else
		cout<<"Not a Regular Grammar";
	
	return 1;
}


int main(){
//	string cnf="A:a:Aa";
//	string cnf="A:Aa:a";
//	string cnf="A:a:aA";
	
	int n;
	bool status=true;
	string item;
	string production_list[5];
	cout<<"How many productions? ";
	cin>>n;	
	cout<<"Enter grammar(eg> S:AA:a)\n";
	for(int i=0;i<n;i++){
		cout<<"production: ";
		cin>>production_list[i];
	}
	linear(production_list,n);
		
	return 0;	
}