#include "global.h"
void sort(int* a);
int main(){
	
int a[5]={1,3,6,2,8};
print(a);
sort(a);
print(a);
return 0;
} 
void sort(int* a){
	int i,j;
	for(i=1;i<5;i++){
		if(a[i]<a[i-1]){
			int tem=a[i];
			a[i]=a[i-1];
			for(j=i-1;tem<=a[j];j--)
				a[j]=a[j-1];
			a[j+1]=tem;
		}
	}
}
