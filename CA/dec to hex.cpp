/*7
// PROGRAM TO CONVERT BINARY TO DECIMAL 

#include<iostream>
#include<math.h>
#include<conio.h>
#include<iomanip>
using namespace std;

double binary_decimal(double bin){
	if (bin== 0){
		return 0;		
	}
	else{
	int rem=0,i=0,count=0;
	int bin_int=0,dec_int;
	double dec=0;
	
	// #integer part
	bin_int=int(bin);	
	while (bin_int!= 0){
		rem = bin_int  % 10;
		try{		
			if (rem != 0 && rem != 1){				
				throw "Not a Binary Number";				
			}
			else{				
				bin_int /=10;
				dec_int += rem * pow(2,i);
				i++;		
			}
		}
		catch (const char *err){
			cout<<err<<endl;
			exit(1);
		}		
	}
			
	cout<<"Binary integer :"<<int(bin)<<endl;	

//	# float part	
	double bin_float =bin - int(bin);
	double dec_float=0;	
	cout<<"Binary float :"<<bin_float<<endl;	
	
	while (bin / int(bin) != 1){  // loop runs until num/(int)num is 1
		count++;
		bin *=10;
	}
	
	i=0;	// clearing previous value
	cout<<"floating numbers (count) :    "<<count<<endl;
	while (count !=0){
		if (rem==1 || rem ==0){
			bin_float *= 10;		// to get next digit in decimal part
			rem = int(bin_float )% 10;			// to get integer part
			dec_float += rem *pow(2,-(i+1));		// converting to decimal
			bin_float -= int(bin_float);		// removing previous decimal part 
			count --;
			i++;
		}
		else{
			cout<<" Error in floating part. \n Not a Binary number: Expected 0 and 1"<<endl;
			dec_float=0;
			break;
		}			
	}
	cout<<"\n\nint dec  "<<dec_int<<endl;
	cout<<"float dec  "<<setprecision(8)<<dec_float<<endl;
	
	// final part
	dec=dec_int *pow(10,count) + dec_float;
	return dec;
	}
}

int main(){
	double bin_input;
	cout<<"Enter Binary number: ";
	cin>>bin_input;
	
	double dec_output=binary_decimal(bin_input);
	cout<<"Equivalent Decimal : "<<dec_output<<endl<<endl;

	cout<<"Press any key to continue !!!"<<endl<<endl;
	getch();
	main();	

}

*/


// Program to convert octal to decimal

#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;

int octal_2_decimal(int octal_num){
	int decimal_num=0,i=0,remainder=0;
	while (octal_num != 0){
		remainder = octal_num % 10;
		try{
			if (remainder != 8 && remainder !=9){
				octal_num /= 10;
				decimal_num += (remainder * pow(8,i));
		//		i++;
				++i;
			}
			else{
				throw "NOT a Octal Number!!!";
			}
		}
		catch(const char *err){
			cout<<err<<endl;
			break;
		}
	}
	return decimal_num;
}

int main(){
	int bin;
	cout<<"Enter octal number: ";
	cin>>bin;
	cout<<"Decimal equivalent :  "<<octal_2_decimal(bin)<<endl;	
	cout<<"press any key to continue !!!"<<endl<<endl;

	getch();
	main();

}

