#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initData(FILE*f);
void sort(FILE*f,FILE*f1);
int part(int *a,int beg,int end);
void Q_sort(int *a,int beg,int end);
int main(){
	FILE* f;
	FILE*f1;
	f=fopen("data.txt","w+");
	f1=fopen("result.txt","w+");
	initData(f);
	sort(f,f1);
	printf("The sort is over,please check the result file \"result.txt\"!\n");
	fclose(f);
}
void initData(FILE*f){
	srand(time(NULL));
	int num;
	for(int i=0;i<1000;i++){
		num=rand()%1000;
		fprintf(f,"%d ",num);
	}
}
void sort(FILE*f,FILE*f1){
	int a[1000],i;
	fseek(f,0L,SEEK_SET);
	for(i=0;i<1000;i++) fscanf(f,"%d",&a[i]);
	Q_sort(a,0,999);
	for(i=0;i<1000;i++) fprintf(f1,"%d ",a[i]);
	
}
void Q_sort(int *a,int beg,int end){
	if(beg<end){
		int loc=part(a,beg,end);
		Q_sort(a,beg,loc-1);
		Q_sort(a,loc+1,end);
	}
}
int part(int *a,int beg,int end){
	int tem=a[beg];
	while(end>beg){
		
		while(end>beg&&a[end]>=tem) end--;
		a[beg]=a[end];
		while(end>beg&&a[beg]<=tem) beg++;
		a[end]=a[beg];
	}
	a[beg]=tem;
	return beg;
}
