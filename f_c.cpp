#include<stdio.h>
int fc(int l);
int main(){
for(int i=1;i<10;i++)printf("%d ",fc(i));	
}
int fc(int l){
	return (l==1||l==2)?1:fc(l-1)+fc(l-2);
}
