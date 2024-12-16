#include<stdio.h>

int main(){
	int n,i,j,smallest_index, time=0;
	float avg_waiting_time=0, avg_turnaround_time=0;
	int burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20],completion_time[20],remaining_time[20],process_no[20],temp;
	int response_time[20], acquire_turn[20];
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	printf("Enter the arrival time and burst time for each process:\n");
	for(i=0;i<n;i++){		
		printf("Process %d: ",i+1);
		scanf("%d %d",&arrival_time[i],&burst_time[i]);
		remaining_time[i] =burst_time[i];
		process_no[i]=i+1;
	}
	
	//sort processes according to their arrival time
	for (i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arrival_time[i]>arrival_time[j]){
				temp = process_no[i];
				process_no[i] =process_no[j];
				process_no[j] =temp;
				temp = arrival_time[i];
				arrival_time[i]=arrival_time[j];
				arrival_time[j]=temp;
				temp=burst_time[i];
				burst_time[i]=burst_time[j];
				burst_time[j]=temp;
				temp=remaining_time[i];
				remaining_time[i]=remaining_time[j];
				remaining_time[j]=temp;
			}
		}
		acquire_turn[i]=1;
	}
	// calculate completion time for each process
	int completed=0;
	while(completed!=n){
		smallest_index=-1;
		for(i=0;i<n;i++){
			if(remaining_time[i]>0 && arrival_time[i]<=time){
				if(smallest_index ==-1 || remaining_time[i]< remaining_time[smallest_index]){
					smallest_index=i;					
				}
			}
		}
		if(smallest_index==-1){
			time++;
			continue;
		}
		remaining_time[smallest_index] -=1;
		
		// response time = cpu acquired - arrival time
		if (acquire_turn[smallest_index] ==1){
			response_time[smallest_index] = time - arrival_time[smallest_index];
			acquire_turn[smallest_index] =0;
			
		}
		
		if(remaining_time[smallest_index] == 0){
			completion_time[smallest_index] =time+1;
			turnaround_time[smallest_index] =completion_time[smallest_index] - arrival_time[smallest_index];
			waiting_time[smallest_index] = turnaround_time[smallest_index] - burst_time[smallest_index];
			completed++;
		}
		time++;
	}
	
	// calculate avg waiting time and turnaround time
	for(i=0;i<n;i++){
		avg_waiting_time += waiting_time[i];
		avg_turnaround_time += turnaround_time[i];
	}
	avg_waiting_time /=n;
	avg_turnaround_time /=n;
	
	//print results	
	printf("\n%-10s %-15s %-10s %-15s %-15s %-15s %-15s \n","|Process|","|Arrival Time|","|Burst Time|","|Completion Time|","|Turnaround Time|","|Waiting Time|","|Response Time|");
	for(i=0;i<n;i++){
		printf("\t%-5d %-15d %-15d %-15d %-15d %-15d %d \n",process_no[i], arrival_time[i],burst_time[i],
		completion_time[i],turnaround_time[i],waiting_time[i],response_time[i]);
	}
	printf("\nAverage turnaround_time: %.2f",avg_turnaround_time);
	printf("\nAverage waiting time: %.2f",avg_waiting_time);
	
	return 0;
}