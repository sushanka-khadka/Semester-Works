// Program to implement OPR algorithm
#include<stdio.h>

int main(){
	int tot_frames,tot_pages,frames[10],pages[10],ref_string[30],temp[10],flag1,flag2,flag3;
	int i,j,k,pos,max,faults=0;
	int flag=0; // flag=1->> hit, else fault
	printf("*****OPR*****\n");
	printf("Enter no of frames: ");
	scanf("%d",&tot_frames);
	printf("Enter no of pages: ");
	scanf("%d",&tot_pages);
	
	printf("Enter page reference string: ");
	for(i=0;i<tot_pages;++i){
		scanf("%d",&ref_string[i]);
	}
	
	for(i=0;i<tot_frames;++i){
		frames[i]=-1;
	}
	
	printf("\n=========================================================\n");
	for(i=0;i<tot_frames;i++){
		printf("frame[%d]\t",i);
	}	
	printf("page fault");
	printf("\n=========================================================\n");
	
	for(i=0;i<tot_pages;++i){
		flag1=flag2=0;
		for(j=0;j<tot_frames;++j){
			if(frames[j]==ref_string[i]){
				flag1=flag2=1;
				flag=1; // page hit
				break;
			}
		}	
			
		if(flag1==0){
			for(j=0;j<tot_frames;++j){
				if(frames[j] ==-1){
					faults++;
					frames[j] =ref_string[i];
					flag2=1;
					break;
				}
			}
		}
		
		if(flag2==0){
			flag3=0;
			for(j=0;j<tot_frames;++j){
				temp[j] = -1;
				
				for(k=i+1;k<tot_pages;++k){
					if(frames[j]==ref_string[k]){
						temp[j] =k;
						break;
					}
				}
			}
			
			for(j=0;j<tot_frames;++j){
				if(temp[j]== -1){
					pos=j;
					flag3=1;
					break;					
				}
			}
			if(flag3==0){
				max=temp[0];
				pos=0;
				for(j=1;j<tot_frames;++j){
					if(temp[j]>max){
						max=temp[j];
						pos=j;						
					}
				}
			}
			faults++;
			frames[pos] =ref_string[i];
		}
		
		printf("\n");
		for(j=0;j<tot_frames;++j){
			printf("%4d\t\t",frames[j]);
		}
		if(flag==0)
			printf("F");	// page fault		
		flag=0;
	}
			
			
printf("\n=========================================================\n");
	printf("\nTotal Page Faults= %d\n",faults);
	return 0;
}