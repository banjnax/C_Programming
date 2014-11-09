#include<stdio.h>
void hano(int n,char a,char b,char c);
int main(){
	hano(3,'A','B','C');
}
void hano(int n,char a,char b,char c){
	if(n==1)printf("%c-->%c\n",a,b);
	else{
		hano(n-1,a,c,b);
		printf("%c-->%c\n",a,b);
		hano(n-1,c,b,a);
	}
}
