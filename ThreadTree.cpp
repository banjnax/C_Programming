#include<stdio.h>
#include<stdlib.h>
typedef struct BiTree{
	int ltag;
	int rtag;
	char data;
	BiTree * lc;
	BiTree * rc;
};
typedef struct Stack{
	int top;
	int length;
	BiTree **S;
};
typedef struct Quenue{
	int rear;
	int front;
	int MaxSize;
	int length;
	BiTree **S;
}; 
BiTree * pre;
void CreateTree(BiTree* &p);//����ݹ齨�� 
void InOrderTraver(BiTree* T);//����ݹ���������� 
void ThreadTreeTraver(BiTree *Thr);//�����������������б��� 
void ThreadingTree(BiTree *&Thr,BiTree *&T);//������������ 
void InThreading(BiTree *p);//�������� 
void InitStack(Stack *&stack);//��ʼ��stack 
void Push(Stack *stack, BiTree *p);//��Ԫ�� 
void Pop(Stack *stack, BiTree *&p);//��Ԫ�� 
void TraverWithStack(BiTree *T);//���������������� 
void TraverWithQuenue(BiTree *T);//��α����� 
void InitQuenue(Quenue *&Q);
void EnQuenue(Quenue *&Q, BiTree *p);
void DeQuenue(Quenue *&Q, BiTree *&p); 
int main(){
	BiTree* T,*Thr;
	printf("������ʼ...\n");
	CreateTree(T);
	printf("�������\n");
	
	printf("����ݹ������ʼ...\n");
	InOrderTraver(T);
	printf("\n--------------------\n");
	 
 	printf("����ǵݹ�����ջ��ʼ...\n");
	TraverWithStack(T);
	printf("\n-----------------------\n");
	
	printf("����ǵݹ����ö��п�ʼ...\n");
	TraverWithQuenue(T);
	printf("\n-------------------------\n"); 
	
	printf("��������ʼ...\n");
	ThreadingTree(Thr,T);
	printf("^_^\n����������...\n����������������ʼ...\n");
	ThreadTreeTraver(Thr);
	printf("\n-----------------\n");	 
	return 0;
}
void CreateTree(BiTree* &p){
	char c=getchar();
	getchar();
	if(c==' ')
		p=NULL;//ע�������д��==�� 
	else{
		p=(BiTree *)malloc(sizeof(BiTree));
		p->data=c;p->ltag=0;p->rtag=0;
		CreateTree(p->lc);
		CreateTree(p->rc);
	}
}
void InOrderTraver(BiTree* T){
	if(T){
		printf("%c",T->data);
		InOrderTraver(T->lc);
		InOrderTraver(T->rc);
	}
}
void ThreadTreeTraver(BiTree *Thr){//���Ѿ��������õ������б��������Ǳ���ĵ�ѭ��������� 
	BiTree *p=Thr->lc;//�����ĸ��ڵ�ժ���� 
	
	while(p!=Thr){//��Ϊ��ѭ����������pΪThrʱ���������� 
		while(p->ltag==0)p=p->lc;//ltag==0��ʾ������Ϊ�������������� 
		printf("%c|",p->data);//�������һ��Ԫ�������� 
		while(p->rtag==1&&p->rc!=Thr){//�ⲽ����Ҫ�����������ǰ��յ�����һ��һ�������ң�����±��Ҳ����Ļ� 
			p=p->rc;				//˵�����Ԫ�صĺ󼴽ڵ�����������������ߵ��Ǹ� 
			printf("%c|",p->data);
		}
		p=p->rc;//����������Ҳ�����ʱ���һ���� 
	}
}
void ThreadingTree(BiTree *&Thr,BiTree *&T){
	Thr=(BiTree *)malloc(sizeof(BiTree));//��ʼ������ͷ��� 
	Thr->ltag=0;
	Thr->rtag=1;
	Thr->rc=Thr;//Ϊ�˷�ֹҰָ�룬��ͷ������Һ��Ӷ���ֵ 
	Thr->lc=T;
	pre=Thr;//pre��¼��ǰ�ڵ����һ��,Ϊ�˷�������Ϊȫ�ֱ�����������֯��̽ڵ� 
	InThreading(T);
	pre->rc=Thr;//��β���� 
	pre->rtag=1;
	Thr->rc=pre;
}
void InThreading(BiTree *p){
	if(p){
		InThreading(p->lc);
		if(!p->lc){//˵����������ΪNULL����������������Ϊ�����ڵ� 
			p->ltag=1;p->lc=pre;//p��ǰ��Ϊpre 
		}
		if(!pre->rc){//��Ϊ��ô�Ѿ��ҵ���һ�������������Ľڵ㣬����q,�������ǵ�ǰ���ڵ�Ϳ����к���� 
			pre->rtag=1;
			pre->rc=p;
		}
		pre=p;//����pre 
		InThreading(p->rc);
	}
}
 void TraverWithStack(BiTree *T){
 	Stack *stack;
 	BiTree *p=T;
 	InitStack(stack);
 	while(p||stack->top!=-1){
	 	if(p){Push(stack,p);p=p->lc;}//��������ջ 
	 	else{
	 		Pop(stack,p);//��ջ���� 
	 		printf("%c",p->data);
	 		p=p->rc;//����������������� 
	 	}
	 }
 }
 void InitStack(Stack *&stack){
 	stack=(Stack *)malloc(sizeof(Stack));
 	stack->top=-1;
 	stack->S=(BiTree **)malloc(sizeof(BiTree *)*20);
 	stack->length=20;
 }
 void Push(Stack *stack, BiTree *p){
 	if(stack->top!=20) stack->S[++(stack->top)]=p;
 	else printf("Stack is overflowing!\n");
 }
 void Pop(Stack *stack, BiTree *&p){
 	if(stack->top==-1) printf("Stack is already empty!\n");
 	else p=stack->S[(stack->top)--];
 }
 void TraverWithQuenue(BiTree *T){
 	Quenue *Q;
 	BiTree *p=T;
 	InitQuenue(Q);
 	EnQuenue(Q,p);
 	while(Q->length!=0){
	 	DeQuenue(Q,p);
		printf("%c",p->data);
	 	if(p->lc) EnQuenue(Q,p->lc);
	 	if(p->rc) EnQuenue(Q,p->rc);
	 }
 }
 void InitQuenue(Quenue *&Q){
 	Q=(Quenue *)malloc(sizeof(Quenue));
 	Q->front=0;//�Ȱ����Ԫ��������Ϊһ��������������Ԫ��
 	Q->rear=Q->front;
	Q->length=0;
	Q->MaxSize=21;
	Q->S=(BiTree **)malloc(sizeof(BiTree *)*21);	
 }
 void EnQuenue(Quenue *&Q, BiTree *p){
 	if((Q->rear+1)%Q->MaxSize==Q->front) printf("Quenue is already full!\n");
 	else {Q->S[Q->rear]=p;Q->rear=(Q->rear+1)%Q->MaxSize;Q->length++;}
 }
 void DeQuenue(Quenue *&Q, BiTree *&p){
 	if(Q->front==Q->rear) printf("Quenue is already empty!\n");
 	else {p=Q->S[Q->front];Q->front=(Q->front+1)%Q->MaxSize;Q->length--;}
 }
 