// Program to convert decimal to octal
#include<iostream>
#include<math.h>
#include<conio.h>
#include<iomanip>
using namespace std;

double dec_2_oct(double decimal_num){
	int remainder=0;
	int temp=1,i=0;
	int oct_int=0,dec_int=0;
	
	// integer part 
	dec_int =int(decimal_num);
	while (dec_int!= 0){	
		remainder =dec_int %8;
		dec_int /= 8;
//		octal_num = octal_num + temp *remainder;
//		temp *= 10;
		oct_int += pow(10,i) * remainder;
		i++;
	}	
	
	cout<<"integer part "<<oct_int<<endl;
	// floating part 
	double oct_float=0,dec_float=0,oct_num;
	dec_float = decimal_num -int(decimal_num);
	cout<<"dec_float "<<dec_float<<endl;
	

	for(i=1;i<=6;i++){
		if (dec_float == 0)
			break;
		else{
			dec_float *=8;
			oct_float += int(dec_float) *pow(10,-i);
			dec_float -= int(dec_float);			
		}
	}	
	
	cout<<"oct int "<<oct_int<<endl;
	cout<<"oct float  "<<oct_float<<endl<<endl;
	
	oct_num =oct_int +oct_float;
//	return oct_int;
	return oct_num;
}


int main(){
	double dec,oct_output;
	cout<<"Enter decimal number: ";
	cin>>dec;
	oct_output=dec_2_oct(dec);
	
	cout<<"octal equivalent :  "<<setprecision(16)<<oct_output<<endl;
	cout<<"Press any key to continue !!!"<<endl<<endl;
	getch();
	main();	
}