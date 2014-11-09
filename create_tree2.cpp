#include<stdio.h>
#include<malloc.h>
struct T{
	T* LT;
	T* RT;
	char value;
};
void create_T(T*&TT);
void print_T(T*&TT);
int main(){
	//T* H=(T*)malloc(sizeof(T));
	T* H1;
	T* H; 
	create_T(H);
	printf("print tree:\n");
	print_T(H);
	return 0;
}
void create_T(T*&TT){
	char c=getchar();
	getchar();
	if(c==' ') TT=NULL; 
	else{
		TT=(T*)malloc(sizeof(T));
		TT->value=c;
		create_T(TT->LT);
		create_T(TT->RT);
	}
}
void print_T(T*&TT){
	if(TT!=NULL){
	    printf("%c ",TT->value);
		print_T(TT->LT);
		print_T(TT->RT);
	}
}
