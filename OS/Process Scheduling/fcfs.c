#include<stdio.h>

int main(){
	int n,i,j;
	float avg_wait_time=0,avg_turnaround_time=0;
	int process_no[20], burst_time[20], arrival_time[20], wait_time[20], turnaround_time[20], completion_time[20],temp;
	
	printf("Enter the no of process:");
	scanf("%d",&n);
	printf("Enter the arrivial and burst time for each process:\n");
	for (i=0; i<n;i++){
		printf("Process %d:",i+1);
		scanf("%d %d",&arrival_time[i],&burst_time[i]);
		process_no[i]=i+1;
	}	
	
	// sort processes according to theur arrival time
	for(i=0;i<n;i++){
		for(j=i+1; j<n;j++){
			if(arrival_time[i]>arrival_time[j]){
				temp = process_no[i];
				process_no[i] =process_no[j];
				process_no[j] =temp;
				temp = arrival_time[i];
				arrival_time[i] =arrival_time[j];
				arrival_time[j] =temp;
				temp= burst_time[i];
				burst_time[i]= burst_time[j];
				burst_time[j]= temp;
			}
		}
	}
	
	// calculate completion time for each process
	for(i=0;i<n; i++){
		if(i==0){
			completion_time[i] = arrival_time[i] + burst_time[i];
		}else{
			if(arrival_time[i]>completion_time[i-1]){
				completion_time[i] = arrival_time[i] + burst_time[i];
			}else{
				completion_time[i] = completion_time[i-1] + burst_time[i];
			}
		}
	}
	
	//calculate turnaround time for each process
	for(i=0;i<n;i++){
		turnaround_time[i] = completion_time[i] - arrival_time[i];
	}
	
	// calculate waiting time for each process
	for(i=0; i<n; i++){
		wait_time[i] = turnaround_time[i] - burst_time[i];
	}
	// calculate avg waiting time and turnaround time for each process
	for(i=0; i<n; i++){
		avg_wait_time += wait_time[i];
		avg_turnaround_time += turnaround_time[i];
	}
	avg_wait_time /= n;
	avg_turnaround_time /= n;
	
	//print results
	printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
	for(i=0;i<n;i++){
		printf("%d \t%d \t\t%d \t\t%d \t\t%d \t\t%d\n",process_no[i], arrival_time[i],burst_time[i],completion_time[i],turnaround_time[i],wait_time[i]);
	}		
	
	printf("\nAverage waiting time: %.2f",avg_wait_time);
	printf("\nAverage turnaround_time: %.2f",avg_turnaround_time);	
	return 0;
}