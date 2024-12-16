// program to implement LRU page replacement algorithm
#include <stdio.h> 
 
int findLRU(int time[], int n) { 
    int i, minimum = time[0], pos = 0; 
 
    for(i = 1; i < n; ++i) { 
        if(time[i] < minimum) { 
            minimum = time[i]; 
            pos = i; 
        } 
    }  
    return pos; 
} 
 
int main(){ 
    int no_of_frames, no_of_pages, frames[10], ref_string[30], counter = 0, time[10],flag1, flag2; 
    int i, j, pos, faults = 0; 
    int flag = 0; // for hit if flag = 1 ; then hit else fault 
 	printf("*****LRU*****\n");
    printf("Enter number of frames: "); 
    scanf("%d", &no_of_frames); 
 
    printf("Enter number of pages: "); 
    scanf("%d", &no_of_pages); 
 
    printf("Enter reference string: "); 
    for(i = 0; i < no_of_pages; ++i)
        scanf("%d", &ref_string[i]); 
 
    for(i = 0; i < no_of_frames; ++i) 
        frames[i] = -1;

    printf("==============================================================================\n"); 
	for(int i = 0; i < no_of_frames; i++)
		printf("frame[%d]\t", i); 
	
	printf("page fault"); 
	printf("\n==============================================================================\n"); 
	for(i = 0; i < no_of_pages; ++i){
		flag1 = flag2 = 0; 
		for(j = 0; j < no_of_frames; ++j){	
			if(frames[j] == ref_string[i]) { 
				counter++; 
				time[j] = counter; 
				flag1 = flag2 = 1; 
				flag = 1; // hit case 
				break; 
			} 
		} 
		if(flag1 == 0) { 
			for(j = 0; j < no_of_frames; ++j) { 
				if(frames[j] == -1) { 
					counter++; 
					faults++; 
					frames[j] = ref_string[i]; 
					time[j] = counter; 
					flag2 = 1; 
					break; 
				} 
			} 
		}
		 
		if(flag2 == 0) { 
			pos = findLRU(time, no_of_frames); counter++; 
	        faults++; 
	        frames[pos] = ref_string[i]; 
	        time[pos] = counter; 
	    }	 
	    
		printf("\n"); 
	    for(j = 0; j < no_of_frames; ++j)
	        printf("%4d\t\t", frames[j]);     
	    if(flag == 0)
	        printf(" F");     
	    flag = 0; 
	}	    
	printf("\n==============================================================================\n"); 
    printf("\n\nTotal Page Faults = %d\n", faults);  
    return 0; 
}