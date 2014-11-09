#include<stdio.h>
#include<malloc.h>
typedef struct{
	int *s;
	int top;
	int length;
}Stack;
#define ERROR -1;
void menu();
void init(Stack* S);
int pop(Stack *S);
void push(Stack *S,int number);
void print(Stack S);
int main(){
	Stack S;
	int flag,temp;
	init(&S);
	menu();
	printf("Function No.");
	scanf("%d",&flag);
	while(flag!=4){
		switch(flag){
			case 1:	printf("Input a number!\n");
					scanf("%d",&temp);
					push(&S,temp);
			break;
			case 2:	pop(&S);break;
			case 3:	print(S);break;
			case 4:	exit(255);
		}
		printf("Function No.");
		scanf("%d",&flag);
	}
	return 0;
}
void menu(){
	printf("1.Push a number to the stack!\n");
	printf("2.Pop a number from the stack!\n");
	printf("3.print the stack!\n");
	printf("4.Exit\n");
}

void init(Stack* S){
	printf("Please input the length of the stack!\n");
	scanf("%d",&(S->length));
	if(S->length<0)printf("Invaild stack space!\n");
	else{
 		S->s=(int*)malloc(sizeof(int));
 		S->top=0;
	}
}
int pop(Stack *S){
	if(S->top-1<0){
		printf("Stack has no more element!\n");
		return -1;
	}
	return S->s[--(S->top)];
}
void push(Stack *S,int number){
	if(S->top<S->length){
		S->s[(S->top)++]=number;
	}
	else printf("Stack space is not enough!\n");
}
void print(Stack S){
	printf("Stack length:%d,Usage:%d\nContent:",S.length,S.top);
	for(int i=0;i<S.top;i++)printf("%d ",S.s[i]);
	putchar('\n');
}
