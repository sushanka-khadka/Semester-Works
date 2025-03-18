// Circular queue inplementation
// Enque and Deque operatoin on Linear Queue
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5

struct C_queue{
	int items[max],front,rear;
};
typedef struct C_queue c_queue;

void enque(c_queue *,int);
int deque(c_queue*);
void show(c_queue*);

int main(){
	
	c_queue *q;
	q=(c_queue*)malloc(sizeof(c_queue));
	q->front=q->rear=0;
	int choice,data,x;
	do{
		printf("\nMenu Driven Program For Circular Queue\n\t 1.Enque\n\t 2.deque\n\t 3.Display\n\t 4.Exit");
		printf("\nEnter your choice:  ");
		scanf("%d",&choice);		
		system("cls");
		switch(choice){
			case 1:
				printf("Item to Insert:\t");
				scanf("%d",&data);
				enque(q,data);
				break;
			case 2:
				x=deque(q);												
				if(x!='\0')
					printf("Item Removed\t%d",x);
				break;
			case 3:
				show(q);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid value!\n");		
		}
	}
	while(choice !=4);			
	return 0;
	
}

void enque(c_queue*q,int d){
//	if(q->front == (q->rear+1)%max)
	if(q->front == (q->rear+1)%max)
		printf("Circular Queue is FuLL!\n");
	else{
		q->items[q->rear]=d;
		q->rear = (q->rear+1)%max;
	}
}

int deque(c_queue*q){
	int item;
	if(q->rear == q->front){
		printf("Nth to remove !\n");
		return NULL;
	}
	else{
		item=q->items[q->front];
		q->front =(q->front+1) %max;
		return item;
	}
}

void show(c_queue*q){
	printf("rear %d\t front %d\n",q->rear,q->front);
	if(q->rear == q->front)
		printf("Queue is empty !\n");
	else{
//		for(int i=q->front;i<=q->rear;i++)
		for(int i=q->front;i!=q->rear;i=(i+1)%max)
			printf("%d\t",q->items[i]);		
	}
}