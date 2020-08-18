//给定一个链表，实现删除链表第 K 个节点的函数。
//输入描述:
//n 表示链表的长度。
//m 表示删除链表第几个节点。
//val 表示链表节点的值。
//输出描述:
//在给定的函数中返回链表的头指
//5 3
//1 2 3 4 5
//输出
//复制
//1 2 4 5
#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int val;
  struct Node *next;	
	
 };
 int main()
 {
 int i,n,m;
 int k=0;
 scanf("%d%d",&n,&m);
 struct Node *H,*p,*s,*q;
 H=(struct Node*)malloc(sizeof(struct Node));	
 H->next=NULL;//头节点
 p=H;
 	for(i=0;i<n;i++)//输入节点 
    {
        s=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&s->val);
        s->next=p->next;
       p->next=s;
        p=s;
 } p=H;
    q=p->next;
    while(k<m)
    {
        q=q->next;
        p=p->next;
        k++;
    }
    p->next=q->next;
    free(q);//删除节点 
    p=H;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d ",p->val);
    }
    return 0;
    } 
      
