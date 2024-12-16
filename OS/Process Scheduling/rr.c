#include<stdio.h>

int main(){
	int n,i,j,time_quantum,remaining_processes,time=0;
	float avg_waiting_time=0, avg_turnaround_time=0;
	int burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20],completion_time[20],remaining_time[20];
	int response_time[20], acquire_turn[20],temp,process_no[20];
	
	printf("Enter the no of processes: ");
	scanf("%d",&n);
	printf("Enter the arrival time and burst time for each process:\n");
	for(i=0;i<n;i++){		
		printf("Process %d: ",i+1);
		scanf("%d %d",&arrival_time[i],&burst_time[i]);
		remaining_time[i] =burst_time[i];
		process_no[i]=i+1;
	}
	
	printf("Enter the Time Quantum: ");
	scanf("%d",&time_quantum);
	
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
 
 	
	remaining_processes =n;
	int k=0,cp=0,turn=0,RQ[50],rr=0;	
	RQ[k]=turn;
	
	while(remaining_processes >0){
		rr=RQ[cp];	// actual process
		while(time<arrival_time[rr]){	// incase fused state
			time++;
		}
		if (acquire_turn[rr] ==1){
			response_time[rr] = time - arrival_time[rr];
			acquire_turn[rr] =0;			
		}
		if(remaining_time[rr] > time_quantum){		// uncomplete
			time+= time_quantum;
			remaining_time[rr] -= time_quantum;
			for(turn;turn<n;turn++){		// insert to rq
				if(arrival_time[turn]<=time){
					RQ[k++] =turn;
				}else{
					break;
				}
			}
			RQ[k++]	= rr;	// current process to RQ				
		}else{		// complete
			time += remaining_time[rr];
			completion_time[rr] = time;
			turnaround_time[rr]= completion_time[rr] - arrival_time[rr];
			waiting_time[rr] = turnaround_time[rr] - burst_time[rr];
			avg_waiting_time += waiting_time[rr];
			avg_turnaround_time += turnaround_time[rr];
			remaining_time[rr] =0;
			remaining_processes --;	
			
			for(turn;turn<n;turn++){	//insert to rq
				if(arrival_time[turn]<=time){
					RQ[k++] =turn;
				}else{
					break;
				}
			}				
		}		
		cp++;	// counter ro ready queue
	}		 
 
    // Print results 
    avg_waiting_time /= n; 
    avg_turnaround_time /= n; 
    printf("\n%-10s %-15s %-10s %-15s %-15s %-15s %-15s \n","|Process|","|Arrival Time|","|Burst Time|","|Completion Time|","|Turnaround Time|","|Waiting Time|","|Response Time|");
	for(i=0;i<n;i++){
		printf("\t%-5d %-15d %-15d %-15d %-15d %-15d %d \n",process_no[i], arrival_time[i],burst_time[i],completion_time[i],turnaround_time[i],waiting_time[i],response_time[i]);
	}
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time); 
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);  
	
	return 0;	
}