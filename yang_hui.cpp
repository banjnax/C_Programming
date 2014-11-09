#include<stdio.h>
#include<malloc.h>
void Y_H(int c);
void printY(int*a,int l);
void perm(int level);
int main(){
	int c;
	printf("Please inter the level!:)\n");
	scanf("%d",&c);
	Y_H(c);
	return 0;
}
void Y_H(int c){
	int l=c*(c+1)/2;
	int* a=(int*)malloc(sizeof(int)*l);
	int i,j,beg,end;
	for(i=0;i<c;i++){
		beg=i*(i+1)/2;
		end=beg+i;
		a[beg]=1;
		for(j=beg+1;j<end;j++){
			a[j]=a[j-i-1]+a[j-i];
		}
		a[end]=1;
	}
	printY(a,c);
}
void printY(int*a,int l){
	int flag,j,beg,end;
	for(int i=0;i<l;i++){
		perm(l-i);
		beg=i*(i+1)/2;
		end=beg+i;
		for(j=beg;j<=end;j++)
			printf("%d ",a[j]);
		putchar('\n');
	}
}
void perm(int level){
	for(int i=0;i<level;i++)printf(" ");
}
