#include <stdio.h> 
#include <stdlib.h> 
int main(){
	int RQ[100], i, n, TotalHeadMovement = 0, initialHead; 
	printf("\t****FCFS****\n");
	printf("Enter the number of Requests: "); 
	scanf("%d", &n); 
	printf("Enter the Requests sequence: "); 
	for(i = 0; i < n; i++) 
	scanf("%d", &RQ[i]); 
	printf("Enter initial head position: "); 
	scanf("%d", &initialHead); 
	// FCFS disk scheduling 
	for(i = 0; i < n; i++){ 
		TotalHeadMovement += abs(RQ[i] - initialHead); 
		initialHead = RQ[i]; 
	} 
	printf("Total head movement is %d\n", TotalHeadMovement);
	return 0; 
} 
