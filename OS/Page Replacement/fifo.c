//Program to implement FIFO page replacement
#include <stdio.h> 
 
int main() { 
    int referenceString[30], pageFaults = 0, m, n, s, pages, frames; 
    int flag = 0; 
 	printf("*****FIFO*****\n");
    printf("Enter number of frames: "); 
    scanf("%d", &frames); 
 
    printf("Enter number of pages: "); 
    scanf("%d", &pages); 
 
    printf("Enter reference string values: "); 
    for(m = 0; m < pages; m++) 
        scanf("%d", &referenceString[m]); 
     
    int temp[frames]; 
    for(m = 0; m < frames; m++) 
        temp[m] = -1;  
 
    
	printf("\n\n=============================================================\n" ); 
    for(int i = 0; i < frames; i++) 
        printf("frame[%d]\t", i );     
    printf("page fault" ); 
    
	printf("\n=============================================================\n" ); 
 
    for(m = 0; m < pages; m++) { 
        s = 0; 
        for(n = 0; n < frames; n++) { 
          if(referenceString[m] == temp[n]) { 
                s++; 
                pageFaults--; 
                flag = 1; 
            } 
        } 
        pageFaults++; 
        if((pageFaults <= frames) && (s == 0)) 
            temp[m] = referenceString[m]; 
        else if(s == 0) 
            temp[(pageFaults - 1) % frames] = referenceString[m];         
        printf("\n"); 
        for(n = 0; n < frames; n++) 
            printf("%4d\t\t", temp[n]);         
        if (flag == 0) 
            printf(" F" );         
        flag = 0; 
    } 
    
printf("\n=============================================================\n" ); 
    printf("\nTotal Page Faults: %4d\n", pageFaults); 
    return 0; 
}
