// 3333333.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "stdlib.h"
#define OK 1;
#define ERROR 0;
#define OWERFLOW -2;
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;//ֵ
	struct LNode *next;//ָ����
}LNode,*LinkList;//�������ṹ�壬LinkListΪ������ָ������
//��������
int caidan();
void CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList &L,int i,ElemType &e);
Status ListInsert_L(LinkList &L,int i,ElemType e);
Status ListDelete_L(LinkList &L,int i,ElemType &e);
int LocateElem_L(LinkList L,ElemType e);
int main(int argc, char* argv[])
{
	LinkList L;
	ElemType e;
	int n,i;
	Status s;
	for(;;)
	{
		switch(caidan()){
		case 1:printf("������Ԫ�ظ�����");
			scanf("%d",&n);
			CreateList_L(L,n);
			printf("�������\n");
			break;
		case 2:
			PrintList_L(L);
			break;
		case 3:
			printf("��������ҵ�λ��");
			scanf("%d",&i);
	        s=GetElem_L(L,i,e);
			if(s){
		   printf("���ҵ�%d\n",e);
			}
			else
				printf("����ʧ��\n");
		break;
		case 4:
			printf("����������λ��");
			scanf("%d",&i);
			printf("����������ֵ��");
			scanf("%d",&e);
	        s=ListInsert_L(L,i,e);
			if(s)
			printf("����ɹ�\n"); 
			else
				printf("����ʧ��\n");
			break;
		case 5:
			printf("������ɾ����λ��\n");
			scanf("%d",&i);
	       s=ListDelete_L(L,i,e);
		   if(s)
		   {
			printf("ɾ����Ԫ��%d�ɹ�\n",e);
		   }
		   else
			   printf("ɾ��ʧ��\n");
			break;
		case 6:
			printf("��������ҵ�ֵ��");
			scanf("%d",&e);
			i=LocateElem_L(L,e);
			if(i){
			printf("%d���߼�˳����%d\n",e,i);
			}
			else
				printf("����ʧ��\n");
			break;
		case 0:printf("���������ллʹ�ã�\n");
				   exit(0);
			break;
		}
		}
	return 0;
}
int caidan()
{
int sn;
printf("\n�˵���ʾ\n");
printf("1:����\n");
printf("2:��ʾ\n");
printf("3:ȡԪ��\n");
printf("4:����\n");
printf("5:ɾ��\n");
printf("6:����\n");
printf("0:�˳�\n");
printf("������0~6\n");
for(;;)
{
scanf("%d",&sn);
if(sn<0||sn>6)
{
printf("\n�������,����������0~6");
}
else
break;
}
return sn;
}
void CreateList_L(LinkList &L,int n)
{
	LinkList p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	printf("����������%d��Ԫ��:\n",n);
	for(i=n;i>=1;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));//����ռ䣬����һ���ռ䣬�ռ�Ĵ�СΪLNode�Ĵ�С���ڴ��ַת��ΪLinkList����
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}
//�������
void PrintList_L(LinkList L)
{
	LinkList p;
	p=L->next;//��ʼ����pָ����Ԫ��
	printf("���������е�Ԫ�أ�\n");
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;//p���� 
	 } 
	 printf("\n");
 } 
 
 Status GetElem_L(LinkList &L,int i,ElemType &e)
 {
	 LinkList p;
 	p=L->next;
 	int j=1;
 	while(p&&j<i)
 	{
 		p=p->next;
 		++j;
 }
 if(!p||j>i)
 {
 	return ERROR;
 }
 e=p->data;
 return OK;
	 }
Status ListInsert_L(LinkList &L,int i,ElemType e)	 
{
	LinkList p,s;
	p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	 } 
	 if(!p||j>i-1)
	 return ERROR;
	 s=(LinkList)malloc(sizeof(LNode));
	 s->data=e;
	 s->next=p->next;
	 p->next=s;
	 	 return OK; 
}
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LinkList p,q;
	p=L;
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p->next||j>i-1)
	return ERROR;
		q=p->next;
		p->next=q->next;
		e=q->data;
		free(q);
	return OK;
}
int LocateElem_L(LinkList L,ElemType e)
{
	int j=0;
	LinkList p;
	p=L;
	while(p&&(p->data!=e))
	{
		p=p->next;
		j++;

	}
	return j;
	
}