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
void CreateTree(BiTree* &p);//中序递归建树 
void InOrderTraver(BiTree* T);//中序递归遍历二叉树 
void ThreadTreeTraver(BiTree *Thr);//利用线索二叉树进行遍历 
void ThreadingTree(BiTree *&Thr,BiTree *&T);//线索化二叉树 
void InThreading(BiTree *p);//线索化树 
void InitStack(Stack *&stack);//初始化stack 
void Push(Stack *stack, BiTree *p);//加元素 
void Pop(Stack *stack, BiTree *&p);//出元素 
void TraverWithStack(BiTree *T);//线索化遍历二叉树 
void TraverWithQuenue(BiTree *T);//层次遍历法 
void InitQuenue(Quenue *&Q);
void EnQuenue(Quenue *&Q, BiTree *p);
void DeQuenue(Quenue *&Q, BiTree *&p); 
int main(){
	BiTree* T,*Thr;
	printf("建树开始...\n");
	CreateTree(T);
	printf("建树完成\n");
	
	printf("中序递归遍历开始...\n");
	InOrderTraver(T);
	printf("\n--------------------\n");
	 
 	printf("中序非递归利用栈开始...\n");
	TraverWithStack(T);
	printf("\n-----------------------\n");
	
	printf("中序非递归利用队列开始...\n");
	TraverWithQuenue(T);
	printf("\n-------------------------\n"); 
	
	printf("线索化开始...\n");
	ThreadingTree(Thr,T);
	printf("^_^\n线索化结束...\n遍历线索化的树开始...\n");
	ThreadTreeTraver(Thr);
	printf("\n-----------------\n");	 
	return 0;
}
void CreateTree(BiTree* &p){
	char c=getchar();
	getchar();
	if(c==' ')
		p=NULL;//注意这里别写成==了 
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
void ThreadTreeTraver(BiTree *Thr){//对已经线索化好的树进行遍历，就是变异的单循环链表遍历 
	BiTree *p=Thr->lc;//把树的根节点摘出来 
	
	while(p!=Thr){//因为是循环链表，所以p为Thr时，遍历结束 
		while(p->ltag==0)p=p->lc;//ltag==0表示左子树为不是线索化的树 
		printf("%c|",p->data);//把坐标第一个元素数出来 
		while(p->rtag==1&&p->rc!=Thr){//这步很重要，他的作用是按照单链表一个一个往下找，如果下边找不到的话 
			p=p->rc;				//说明这个元素的后即节点在其右子树的最左边的那个 
			printf("%c|",p->data);
		}
		p=p->rc;//这个就是在找不到的时候拐一个弯 
	}
}
void ThreadingTree(BiTree *&Thr,BiTree *&T){
	Thr=(BiTree *)malloc(sizeof(BiTree));//初始化链表头结点 
	Thr->ltag=0;
	Thr->rtag=1;
	Thr->rc=Thr;//为了防止野指针，把头结点左右孩子都赋值 
	Thr->lc=T;
	pre=Thr;//pre记录当前节点的上一个,为了方便设置为全局变量，用他组织后继节点 
	InThreading(T);
	pre->rc=Thr;//收尾工作 
	pre->rtag=1;
	Thr->rc=pre;
}
void InThreading(BiTree *p){
	if(p){
		InThreading(p->lc);
		if(!p->lc){//说明其左子树为NULL，所以其左子树作为线索节点 
			p->ltag=1;p->lc=pre;//p的前驱为pre 
		}
		if(!pre->rc){//因为我么已经找到了一个可以线索化的节点，就是q,所以我们的前驱节点就可以有后继了 
			pre->rtag=1;
			pre->rc=p;
		}
		pre=p;//更新pre 
		InThreading(p->rc);
	}
}
 void TraverWithStack(BiTree *T){
 	Stack *stack;
 	BiTree *p=T;
 	InitStack(stack);
 	while(p||stack->top!=-1){
	 	if(p){Push(stack,p);p=p->lc;}//左子树入栈 
	 	else{
	 		Pop(stack,p);//出栈访问 
	 		printf("%c",p->data);
	 		p=p->rc;//中序遍历访问左子树 
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
 	Q->front=0;//先把零号元素舍弃作为一个辅助队列满的元素
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
 