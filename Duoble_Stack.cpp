#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
 int length;
 int top1;
 int top2;
 int *S;
};
void init(Stack *stack);
void push(Stack *stack,int flag,int num);
void pop(Stack *stack,int flag);
void printStack(Stack *stack);
int main(){
	Stack *stack;
	init(stack);
	printStack(stack);
	
	printf("Push 2 to S1\n");
	push(stack,1,2);
	printf("Push 5 to S1\n");
	push(stack,1,5);
	printf("Push 1 to S1\n");
	push(stack,1,1);
	printf("Push 7 to S1\n");
	push(stack,1,7);
	
	printStack(stack);
	
	printf("Push 8 to S2\n");
	push(stack,0,8);
	printf("Push 3 to S2\n");
	push(stack,0,3);
	printf("Push 9 to S2\n");
	push(stack,0,9);
	printStack(stack);
	
	printf("Pop S1\n");
	pop(stack,1);
	printf("Pop S1\n");
	pop(stack,1);
	
	printStack(stack);
	
	printf("Pop S2\n");
	pop(stack,0);
		printStack(stack);
		
		printf("Pop S2\n");
	pop(stack,0);
		printStack(stack);
		
		printf("Pop S2\n");
	pop(stack,0);
		printStack(stack);
		
		printf("Pop S2\n");
	pop(stack,0);
		printStack(stack);
		pop(stack,0);
		printf("Pop S2\n");
			printStack(stack);
	pop(stack,0);
	
	printStack(stack);
	
	return 0;
}
void init(Stack *stack){
	stack->S=(int *)malloc(sizeof(int)*20);
	stack->length=20;
	stack->top1=-1;
	stack->top2=20;
	for(int i=0;i<stack->length;i++) stack->S[i]=0;
}
void push(Stack *stack,int flag,int num){
	if(flag==0){
		if(stack->top1!=stack->top2) stack->S[++(stack->top1)]=num;
		else printf("Stack is overflowing!!\n");
		
	}
	else{
		if(stack->top1!=stack->top2) stack->S[--(stack->top2)]=num;
		else printf("Stack is overflowing!!\n");
	}
}
void pop(Stack *stack,int flag){
	if(flag==0){
		if(stack->top1!=-1) stack->S[(stack->top1)--]=0;
		else printf("Stack is alreaady empty!!\n");
		
	}
	else{
		if(stack->top1!=stack->length+1) stack->S[(stack->top2)++]=0;
		else printf("Stack is alreaady empty!!\n");
	}
}
void printStack(Stack *stack){
	printf("-----------------Stack Info----------------\n");
	for(int i=0;i<stack->length;i++) printf("%d|",stack->S[i]);
	printf("\n--------------------Over-------------------\n");
}
