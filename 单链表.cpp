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
	ElemType data;//值
	struct LNode *next;//指针域
}LNode,*LinkList;//创建结点结构体，LinkList为新类型指针类型
//函数声明
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
		case 1:printf("请输入元素个数：");
			scanf("%d",&n);
			CreateList_L(L,n);
			printf("创建完成\n");
			break;
		case 2:
			PrintList_L(L);
			break;
		case 3:
			printf("请输入查找的位序：");
			scanf("%d",&i);
	        s=GetElem_L(L,i,e);
			if(s){
		   printf("查找到%d\n",e);
			}
			else
				printf("查找失败\n");
		break;
		case 4:
			printf("请输入插入的位序；");
			scanf("%d",&i);
			printf("请输入插入的值：");
			scanf("%d",&e);
	        s=ListInsert_L(L,i,e);
			if(s)
			printf("插入成功\n"); 
			else
				printf("插入失败\n");
			break;
		case 5:
			printf("请输入删除的位序：\n");
			scanf("%d",&i);
	       s=ListDelete_L(L,i,e);
		   if(s)
		   {
			printf("删除了元素%d成功\n",e);
		   }
		   else
			   printf("删除失败\n");
			break;
		case 6:
			printf("请输入查找的值：");
			scanf("%d",&e);
			i=LocateElem_L(L,e);
			if(i){
			printf("%d的逻辑顺序是%d\n",e,i);
			}
			else
				printf("查找失败\n");
			break;
		case 0:printf("程序结束，谢谢使用！\n");
				   exit(0);
			break;
		}
		}
	return 0;
}
int caidan()
{
int sn;
printf("\n菜单显示\n");
printf("1:创建\n");
printf("2:显示\n");
printf("3:取元素\n");
printf("4:插入\n");
printf("5:删除\n");
printf("6:查找\n");
printf("0:退出\n");
printf("请输入0~6\n");
for(;;)
{
scanf("%d",&sn);
if(sn<0||sn>6)
{
printf("\n输入错误,请重新输入0~6");
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
	printf("请逆序输入%d个元素:\n",n);
	for(i=n;i>=1;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));//申请空间，分配一个空间，空间的大小为LNode的大小，内存地址转化为LinkList类型
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}
//输出链表
void PrintList_L(LinkList L)
{
	LinkList p;
	p=L->next;//初始化，p指向首元素
	printf("输出链表表中的元素：\n");
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;//p下移 
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