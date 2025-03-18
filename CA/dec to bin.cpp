// Program to convert decimal to binary
#include<iostream>
#include<math.h>
#include<conio.h>
#include<iomanip>
using namespace std;

double dec_2_bin(double decimal_num){
	int remainder=0;
	int temp=1,i=0;
	int bin_int=0,dec_int=0;
	
	// integer part 
	dec_int =int(decimal_num);
	while (dec_int!= 0){	
		remainder =dec_int %2;
		dec_int /= 2;
//		binary_num = binary_num + temp *remainder;
//		temp *= 10;
		bin_int += pow(10,i) * remainder;
		i++;
	}	
	
	cout<<"integer part "<<bin_int<<endl;
	// floating part 
	double bin_float=0,dec_float=0,bin_num;
	dec_float = decimal_num -int(decimal_num);
	cout<<"dec_float "<<dec_float<<endl;
	

	for(i=1;i<=6;i++){
		if (dec_float == 0)
			break;
		else{
			dec_float *=2;
			bin_float += int(dec_float) *pow(10,-i);
			dec_float -= int(dec_float);			
		}
	}	
	
	cout<<"bin int  "<<bin_int<<endl;
	cout<<"bin float  "<<bin_float<<endl<<endl;
	
	bin_num =bin_int +bin_float;
//	return bin_int;
	return bin_num;
}


int main(){
	double dec,bin_output;
	cout<<"Enter decimal number: ";
	cin>>dec;
	bin_output=dec_2_bin(dec);
	
	cout<<"Binary equivalent :  "<<setprecision(16)<<bin_output<<endl;
	cout<<"Press any key to continue !!!"<<endl<<endl;
	getch();
	main();
	
	
}