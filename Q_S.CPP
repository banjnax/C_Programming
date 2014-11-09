#include<stdio.h>
void print(int* a);
int part(int* a,int low,int high);
void sort(int* a,int low,int high);
void init(int* a);
int main(){
	int a[5]={1,2,3,10,5};
//	int *a;
	printf("please inter the numbers!\n");
//	init(a);
	print(a);
	sort(a,0,4);
	printf("\n");
	print(a);
	printf("sort finished");
	return 0;
}
void init(int* a){
	char c;
	int i=0;
while(c!='\n'){
	scanf("%d%d%d%d%d",a,a+1,a+2,a+3,a+4);
	c=getchar();
	i++;
} 
}
void sort(int* a,int low,int high){
	if(low<high){
		int flag=part(a,low,high);
		sort(a,low,flag-1);
		sort(a,flag+1,high);
	}
	
}

int part(int* a,int low,int	high){
	
	int beg=a[low];
	while(high>low){
		
		while(high>low&&a[high]>=beg){
		high--;
		}
		a[low]=a[high];
		while(low<high&&a[low]<=beg){
			low++;
		}
		a[high]=a[low];
	}
	a[low]=beg;
	return low;
}
void print(int* a){
	int i=0;
	for(;i<5;i++)
		printf("%d ",a[i]);
}
