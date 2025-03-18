// PROGRAM TO CONVERT BINARY TO DECIMAL

#include<iostream>
#include<math.h>
#include<conio.h>
#include<iomanip>
//#include<typeinfo>
using namespace std;

double binary_decimal(double bin) {
	if (bin== 0) {
		return 0;
	} else {
		int rem=0,i=0,count=0;
		int bin_int=0,dec_int;
		double dec=0;

		// #integer part
		bin_int=int(bin);
		while (bin_int!= 0) {
			rem = bin_int  % 10;
			try {
				if (rem != 0 && rem != 1) {
					throw "Not a Binary Number";
				} else {
					bin_int /=10;
					dec_int += rem * pow(2,i);
					i++;
				}
			} catch (const char *err) {
				cout<<err<<endl;
				exit(1);
			}
		}

		cout<<"Binary integer :"<<int(bin)<<endl;

//	# float part
		double bin_float =bin - int(bin);
		double dec_float=0;
		cout<<"Binary float :"<<bin_float<<endl;
//		double test_2 =bin;
//		while (test_2 / int(test_2) != 1) { // loop runs until num/(int)num is 17
//			count++;
//			test_2 *=10;		
//		}
//		cout<<endl<<"hello world    "<<test_2 <<endl;
		count=0;
		while (bin / int(bin) != 1) { // loop runs until num/(int)num is 17
			count++;
			bin *=10;
		}

		i=0;	// clearing previous value
		cout<<"floating numbers (count) :    "<<count<<endl;
		while (count !=0) {
			try {
				if (rem != 0 && rem != 1) {
					throw "Not a Binary Number";
				} else {
					bin_float *= 10;		// to get next digit in decimal part
				rem = int(bin_float )% 10;			// to get integer part
				dec_float += rem *pow(2,-(i+1));		// converting to decimal
				bin_float -= int(bin_float);		// removing previous decimal part
				count --;
				i++;
				}
			}
			 catch (const char *err) {
				cout<<err<<endl;
				exit(1);
			}			
		}
		cout<<"\n\nint dec  "<<dec_int<<endl;
		cout<<"float dec  "<<setprecision(8)<<dec_float<<endl;

		// final part
		dec=dec_int *pow(10,count) + dec_float;
		return dec;
	}
}

int main() {
	double bin_input;
	cout<<"Enter Binary number: ";
	cin>>bin_input;

	double dec_output=binary_decimal(bin_input);
	cout<<"Equivalent Decimal : "<<dec_output<<endl<<endl;

	cout<<"Press any key to continue !!!"<<endl<<endl;
	getch();
	main();

}

//	*((char *)type(bin).name());
//	char type = *((char *)typeid(bin).name());
//	if(type != 'i'){
//		cout<<"Not an Integer Value";
//		cout<<"Please, Try again"<<endl;
//		exit(1);
//	}