//����һ������ʵ��ɾ������� K ���ڵ�ĺ�����
//��������:
//n ��ʾ����ĳ��ȡ�
//m ��ʾɾ������ڼ����ڵ㡣
//val ��ʾ����ڵ��ֵ��
//�������:
//�ڸ����ĺ����з��������ͷָ
//5 3
//1 2 3 4 5
//���
//����
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
 H->next=NULL;//ͷ�ڵ�
 p=H;
 	for(i=0;i<n;i++)//����ڵ� 
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
    free(q);//ɾ���ڵ� 
    p=H;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d ",p->val);
    }
    return 0;
    } 
      
