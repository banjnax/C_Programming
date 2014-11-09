#include<stdio.h>
#include<stdlib.h>
void Quick_Sort(int *s, int b, int e);
int Part(int *s,int b,int e);
void Print(int *s,int len);
void Merge_Branch(int *s1, int *s2, int *s3, int *out);
void Create_FTree(int *fail, int *leaf);
void Adjust(int *fail, int *leaf, int i);
int main(){
	int s1[6]={2,7,3,13,9,1000},s2[6]={11,5,3,25,19,1000},s3[6]={12,21,24,20,17,1000},out[15];	
	//ģ���ڴ�������--����
	printf("ԭʼ��1��");
	Print(s1,5); 
	Quick_Sort(s1,0,5);
	printf("�����1��");
	Print(s1,5);
	
	printf("\nԭʼ��2��");
	Print(s2,5);
	Quick_Sort(s2,0,5);
	printf("�����1��");
	Print(s2,5);
	
	printf("\nԭʼ��3��");
	Print(s3,5);
	Quick_Sort(s3,0,5);
	printf("�����3��");
	Print(s3,5);
	
	printf("------------------------------------------------------\n"); 
	Merge_Branch(s1,s2,s3,out); 
	printf("�����ϲ���");
	Print(out,15);
	printf("------------------------------------------------------\n"); 
	return 0;
} 

void Quick_Sort(int *s,int b, int e){
	if(b<e){
		int loc=Part(s,b,e);
		Quick_Sort(s,b,loc-1);
		Quick_Sort(s,loc+1,e);
	}
}

int Part(int *s, int b, int e){
	int voke;
	voke=s[b]; 
	
	while(b<e){
		while(s[e]>voke&&b<e) e--;
		s[b]=s[e];
		while(s[b]<voke&&b<e) b++;
		s[e]=s[b];
	}
	s[b]=voke;
	return b;
}
void Print(int *s, int len){
	for(int i=0;i<len;i++)printf("%d ",s[i]);
	printf("\n");
}

void Merge_Branch(int *s1, int *s2, int *s3, int *out){
	int fail[3],leaf[4],i=0,q,k1=0,k2=0,k3=0;
	
	leaf[0]=s1[k1];
	leaf[1]=s2[k2];
	leaf[2]=s3[k3];
	
	//����������
	Create_FTree(fail,leaf); 
	
	while(leaf[fail[0]]!=1000){
		q=fail[0];
		out[i]=leaf[q];i++;
		
		switch(q){
			case 0:k1++;leaf[q]=s1[k1];break;
			case 1:k2++;leaf[q]=s2[k2];break;
			case 2:k3++;leaf[q]=s3[k3];break;
		}
		
		Adjust(fail,leaf,q);
		
	}
	out[i]=leaf[fail[0]];
} 
void Create_FTree(int *fail, int *leaf){
	int i;
	leaf[3]=-1;//���������Ķ�Ϊ����
	
	for(i=0;i<3;i++) fail[i]=3;//fail���leaf�����±� 
	for(i=0;i<3;i++) Adjust(fail,leaf,i);
 	
	
}

void Adjust(int *fail, int * leaf, int i){
	int tem;
	int t=(i+3)/2;
	while(t>0){
		if(leaf[i]>leaf[fail[t]]){//�˴�ʤ����Ϊ��С�ߣ���С�����ϲ�Ƚϣ�ʧ�������ڽڵ� 
			tem=i;					//i��¼ʤ�����±꣬if��������˵����Ҫ�޸�i 
			i=fail[t];
			fail[t]=tem;	
		}
		t=t/2;
	}
	fail[0]=i;
}
