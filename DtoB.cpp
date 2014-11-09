#include<stdio.h>
void DtoB();
int main(){
	while(true){
		DtoB();
	}
} 
void DtoB(){
	int number,temp,store[20],flag=0;
	printf("Please input a number to be transfer to binary!\n");
	scanf("%d",&number);
	while(number!=0){
		temp=number%2;
		number=number/2;
		store[flag++]=temp;
	}
	for(int i=flag-1;i>=0;i--)printf("%d",store[i]);
	putchar('\n');
	
}
