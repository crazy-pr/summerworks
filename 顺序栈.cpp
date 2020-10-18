// 444.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 10//˳��ջ�洢�ռ�ĳ�ʼ��������
#define STACKINCREMENT 2//˳��ջ�ķ�������
//���ݽṹ
typedef int Status;
typedef int SElemType;
//�������ת��
//typedef char SElemType;
typedef struct
{
	SElemType *base;//�洢�ռ��ַ
	SElemType *top;
	int stacksize;//��ǰ����洢����
}SqStack;
//��������
int caidan();
Status InitStack(SqStack &S);
Status CreateStack(SqStack &S,int n);
void PrintStack(SqStack S);
Status GetTop(SqStack S,SElemType &e);//ȡջ��Ԫ�� 
Status Push(SqStack &S,SElemType e);//Ԫ����ջ 
Status Pop(SqStack &S,SElemType &e);//Ԫ�س�ջ 
Status StackEmpty(SqStack S);//�ж�ջ�Ƿ�Ϊ�� 
Status DestroyStack(SqStack &S);//����ջ 
int main(int argc, char* argv[])
{
	SqStack S;
	Status s;
	int n;
	SElemType e;
	for(;;)
	{
	switch(caidan())
	{
		case 1:
		s=InitStack(S);
		if(s)
		{
			printf("��ʼ���ɹ�");
		}
		else
		printf("��ʼ��ʧ��"); 
		break;
		case 2:printf("����ջ�ĳ��ȣ�");
		scanf("%d",&n); 
		s=CreateStack(S,n);
		if(s)
		printf("�����ɹ�");
		else
		printf("����ʧ��");
		break;
		case 3: 
		PrintStack(S);
		break;
		case 4:
			s= GetTop(S,e);
			if(s)
			printf("ȡջ��Ԫ��Ϊ%d",e);
			else
			printf("ȡջ��Ԫ��ʧ��");
			break; 
			case 5:
				printf("������ջԪ�أ�");
					scanf("%d",&e);
					s=Push(S,e);
				if(s)
				printf("%d��ջ�ɹ�",e);
				else
				printf("��ջʧ��");
				break;
				case 6:
				s=Pop(S,e);
				if(s)
				printf("%d��ջ�ɹ�",e);
				else
				printf("��ջʧ��");
				break;
				case 7:
				s= StackEmpty(S);
				if(s)
				printf("ջ��Ϊ��");
				else
				printf("ջΪ��");
				break;
				case 8:s=DestroyStack(S);
				if(s)
				printf("����ջ�ɹ�");
				else
				printf("����ջʧ��");
				break;
				case 0:printf("ллʹ�øó���");
				exit(0);	
	}

	}

	return 0;
}
//�˵�����
int caidan()
{
	int sn;
	printf("\n��ʾ�˵�\n");
	printf("0:�˳�����\n");
	printf("1:��ʼ��ջ\n");
	printf("2:����ջ\n");
	printf("3:��ʾջ��Ԫ��\n");
	printf("4:ȡջ��Ԫ��\n");
	printf("5:Ԫ����ջ\n");
	printf("6:Ԫ�س�ջ\n");
	printf("7:�ж�ջ�Ƿ�Ϊ��\n");
	printf("8:����ջ\n") ;
	printf("\n������0~8\n");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>8)
		printf("�����������������0~8\n");
		else
		break;
	}
	return sn;
 }
 Status InitStack(SqStack &S)
 {
 	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 	if(!S.base)
 	{
 		exit(OVERFLOW);
	 }
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	  }
	  
 Status CreateStack(SqStack &S,int n)//n��Ԫ����ջ 
 {
 	int i;
 	if(n>S.stacksize)
 	return ERROR;
 	printf("����%d��������",n); 
 	for(i=1;i<=n;i++)
 	{
 		scanf("%d",S.top++);
	 }
	 return OK;	
 }
 void PrintStack(SqStack S)
 {
 	SElemType *p;
 	for(p=S.base;p<S.top ;p++)
 	{
 		printf("%d\t",*p);
	 }
	  
 }
 Status GetTop(SqStack S,SElemType &e)
 {
 	if(S.base==S.top )
 	return ERROR;
 	e=*(S.top-1);
 	return OK;
 }
 Status Push(SqStack &S,SElemType e)
 {
 	if(S.top -S.base>=S.stacksize)
 	{
 		S.base =(SElemType*)realloc(S.base ,(S.stacksize +STACKINCREMENT)*sizeof(SElemType));
 		S.top =S.base +S.stacksize;
 		S.stacksize+=STACKINCREMENT;		
	 }
	 e=*(S.top ++);
	 return OK;
 }
Status Pop(SqStack &S,SElemType &e)
{
	if(S.base==S.top)
	return ERROR;
	e=*--S.top ;
	return OK;
}
Status StackEmpty(SqStack S)
{
	if(S.base =S.top )
	return ERROR;
	else
	return OK;
}
Status DestroyStack(SqStack &S)
{
	if(!S.base )
	return ERROR;
	free(S.base);
	return OK;
}
 
 

