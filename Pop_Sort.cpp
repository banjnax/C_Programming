#include<stdio.h>
#include"global.h"
void sort(int* a);
int main(){
	int a[5]={1,3,6,2,8};
	print(a);
	sort(a);
	print(a);
	return 0;
}
void sort(int *a){
	int i,j;
	for(i=0;i<5;i++){
		int flag=i;
		for(j=i;j<5;j++){
			if(a[flag]<a[j]){
				flag=j;
			}
		}
		int tem=a[i];
		a[i]=a[flag];
		a[flag]=tem;
	}
}
