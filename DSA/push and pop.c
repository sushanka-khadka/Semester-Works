// menu driver PUSH and POP Operation on stack 

#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

struct stack{
	int items[maxsize];
	int top;	// top of stack
};
typedef struct stack st;

void push(st*,int);
int pop(st*);
void display(st*);

// why pointer is used because when we pass by value it creates another var,
// objects thus we are unable to access the actual structure object




int main(){
	st *s;
	s=(st*)malloc(sizeof(st));	// memory allocation
	if(s==NULL){
		printf("Memory Allocaton Failed!\n");
		return 0;
	}	
	s->top=-1;
//	st.top=-1;	// Empty
	
	int data,choice;;
	int x;
	printf("Menu Driven Program For Stack\n\t 1.PUSH\n\t 2.POP\n\t 3.Display\n\t 4.Exit");
	do{
		printf("\nEnter your choice:  ");
		scanf("%d",&choice);		
		switch(choice){
			case 1:
				printf("Item to PUSH:\t");
				scanf("%d",&data);
				push(s,data);
				break;
			case 2:
				x=pop(s);				
				if(x!='\0')
				printf("Item Popped:\t%d",x);
				break;
			case 3:
				display(s);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid value!\n");		
		}
	}
	while(choice);
}

void push(st*s,int d){
	if(s->top==maxsize-1)
		printf("stack is Full!\n");
	else{
//		s->top++
		++s->top;
//		s->items[++s->top]=d;
		s->items[s->top]=d;
	}
}
	
	
int pop(st*s){
	int item;
	if(s->top==-1){		// Empty
		printf("Nothing to pop!\t");
		return NULL;
	}
		
	else{
//		item=s->items[s->top];
//		s->top--;
		item=s->items[s->top--];
		return item;
	}
	
}

void display(st*s){
	if(s->top==-1)
		printf("Stack is empty!\n");
	else{
		printf("Items on stack:\t");
		for(int i=s->top;i>=0;i--){
			printf("%d\t",s->items[i]);
		}
	}
}

// LIFO sequence 