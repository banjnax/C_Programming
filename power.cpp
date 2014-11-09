#include<stdio.h>
#include<stdlib.h>
void print(int *s);
void power(int n,int * s);
int counter=0;
int main(){
	int n,*s;
	printf("Insert the size of bin number to be generated!\n");
	scanf("%d",&n);
	if((s=(int *)malloc((n+1)*sizeof(int)))==NULL) exit(1);
	s[0]=n;
	power(n,s);	
	printf("Total number of generated bin is %d\n",counter);
	return 0;
}
void power(int n,int *s){
	if(n==0){
		print(s);
		counter++;
	}
	else{
		s[n]=1;power(n-1,s);
		s[n]=0;power(n-1,s);
	}	
}
void print(int *s){
	for(int i=s[0];i>=1;i--) printf("%d",s[i]);
	printf("\n");
}
