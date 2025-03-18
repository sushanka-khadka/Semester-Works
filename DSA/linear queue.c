// Enque and Deque operatoin on Linear Queue
#include<stdio.h>
#include<stdlib.h>
#define max 4

struct Queue{
	int items[max],front,rear;
};
typedef struct Queue queue;

void enque(queue *,int);
int deque(queue*);
void show(queue*);

void main(){
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->front=q->rear=0;
	int choice,data,x;
	printf("Menu Driven Program For Linear Queue\n\t 1.Enque\n\t 2.deque\n\t 3.Display\n\t 4.Exit");
	do{
		printf("\nEnter your choice:  ");
		scanf("%d",&choice);		
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
	while(choice);			
	
}

void enque(queue*q,int d){
	if(q->rear==max)
		printf("Queue is FuLL!\n");
	else
		q->items[q->rear++]=d;
}

int deque(queue*q){
	int item;
	if(q->rear <= q->front){
		printf("Nth to remove !\n");
		return NULL
		;
	}
	else{
		item=q->items[q->front++];
		return item;
	}
}

void show(queue*q){
	printf("rear %d\t front %d\n",q->rear,q->front);
	if(q->rear <= q->front)
		printf("Queue is empty !\n");
	else{
		for(int i=q->front;i<q->rear;i++)
			printf("%d\t",q->items[i]);		
	}
}
		

/*
// Enque and Deque in Linear Queue

#include<stdio.h>
#include<stdlib.h>
#define max 4

struct Queue{
	int items[max];
	int front;
	int rear;
};
typedef struct Queue queue;

void enque(queue *,int);
int deque(queue*);
void display(queue*);

int main(){
	int data,choice;
	int x;
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	if(q==NULL){
		printf("Memory Allocaton Failed!\n");
		return 0;
	}
	
	q->rear=-1;
	q->front=-1;

	printf("Menu Driven Program For Linear Queue\n\t 1.Enque\n\t 2.deque\n\t 3.Display\n\t 4.Exit");
	do{
		printf("\nEnter your choice:  ");
		scanf("%d",&choice);		
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
				display(q);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid value!\n");		
		}
	}
	while(choice);			
	return 0;
}

void enque(queue*q,int d){
	if(q->rear ==max-1)		// initialized from -1
		printf("Queue is FuLL!\n");
	else{
//		q->rear++;
		++q->rear;
		q->items[q->rear]=d;
//		q->items[++q->rear]=d;
	}
}

int deque(queue *q){
	int item;
	if((q->rear) <= (q->front)){
		printf("Nth to remove !\n");
		return NULL;
	}
	else{
		++q->front;
		item=q->items[q->front];
//		item=q->items[++q->front];
		return item;
	}
}

void display(queue *q){
	printf("rear %d\t front %d\n",q->rear,q->front);
	if((q->rear) <= (q->front)){
		printf("Queue is empty !\n");
		
	}
	else{
		for(int i=q->front+1;i<=q->rear;i++){
			printf("%d\t",q->items[i]);
		}
	}
}
	

// FIFO sequence 
 Drawback of Linear  Queue 
	shows queue is full even if there is blank position  at the begining of the queue
	one directional
	*/	
		