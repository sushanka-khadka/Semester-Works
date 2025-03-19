// one's complement

//#include<iostream>
//using namespace std;
#include<stdio.h>
# define size 3

int main(){
	char binary[size +1], onesComp [size+1];
	int i, error=0;
	printf("enter %d bit binary value:	",size);
//	gets(binary);	// why gets  ->>> scanf("%s",binary);
	scanf("%s",binary);
	// store all inverted binary bits to ones complement 
	
	for(i=0;i<size;i++){
		if(binary[i]=='1'){
			onesComp[i]='0';
		}
		else if(binary[i]=='0'){
			onesComp[i]='1';
		}
		else{
			printf("wrong Input");
			error =1;	// error genersted 
			break; 	// exits from loop
		}
	}
	// marks the end of OnesComp string 
	onesComp[size]=='\0';
	if(error==0){
		printf("Original value:  %s\n",binary);
		printf("Ones Complement = %s\n\n",onesComp);
		
	}
			
	main();
	return 0;
}
/*  drawbacks of this program 
		need to input exact 8 bit binary no. 
		can't do operation with higher or lower bit 
		
		*/
		
	
	