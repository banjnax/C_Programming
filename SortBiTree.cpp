#include<stdio.h>
#include<stdlib.h>
typedef struct BiTree{
	int data;
	BiTree *lc,*rc;
};
bool SearchTree(BiTree *T,int num,BiTree *f,BiTree *&p);
void Insert2Tree(BiTree *&T,int num);
void TraveTree(BiTree *T);
int main(){
	BiTree *T=NULL;
	int flag,num;
	while(1){
		printf(">"); 
		scanf("%d",&flag);
		switch(flag){
			case 1:scanf("%d",&num);
					Insert2Tree(T,num);
					break;
			case 2:printf("----------------\n");
					TraveTree(T);
					printf("\n----------------\n");
					break;
		}
	}
	return 0;
}
bool SearchTree(BiTree *T,int num,BiTree *f,BiTree *&p){
	if(!T){p=f; return false;}
	else if(T->data==num){p=T;return true;}
	else if(T->data>num) return SearchTree(T->lc,num,T,p);
	else return SearchTree(T->rc,num,T,p);
}
void Insert2Tree(BiTree *&T,int num){
	BiTree *p;
	if(!SearchTree(T,num,NULL,p)){
		BiTree *s=(BiTree *)malloc(sizeof(BiTree));
		s->data=num;s->lc=NULL;s->rc=NULL;
		if(!p) T=s;
		else if(p->data>num) p->lc=s;
		else p->rc=s;
	}
}
void TraveTree(BiTree *T){
	if(T){
		TraveTree(T->lc);
		printf("%d ",T->data);
		TraveTree(T->rc);
	}
}