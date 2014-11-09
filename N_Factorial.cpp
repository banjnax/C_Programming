#include<stdio.h>
void init(int* s);
void process(int* s,int i);
void cal(int*s,int i);
void print(int*s);
int main(){
	
	int s[200];
	int i,N;
	
	printf("Please insert a number(1~100)!\n");
	scanf("%d",&N);
	init(s);
	
	for(i=1;i<=N;i++)
		process(s,i);
	print(s);	
	
	return 0;
} 
void init(int* s){
	for(int i=0;i<199;i++) s[i]=0;
	s[199]=1;
}
void process(int* s,int i){
	int j,tem=0;
	for(j=199;j>0;j--){
		s[j]*=i;
		s[j]+=tem;
		tem=s[j]/10;	
		s[j]=s[j]%10;
	}
}
void print(int*s){
	int l=0;
	for(int i=0;i<200;i++){
		if(s[i]!=0){
			for(int j=i;j<200;j++){
				l++;
				printf("%d",s[j]);
			}
			break; 
		}
	}
	printf("\nDigit Num:%d\n",l);	
}
