// 444.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 10//顺序栈存储空间的初始化分配量
#define STACKINCREMENT 2//顺序栈的分配增量
//数据结构
typedef int Status;
typedef int SElemType;
//完成数制转换
//typedef char SElemType;
typedef struct
{
	SElemType *base;//存储空间基址
	SElemType *top;
	int stacksize;//当前分配存储容量
}SqStack;
//函数声明
int caidan();
Status InitStack(SqStack &S);
Status CreateStack(SqStack &S,int n);
void PrintStack(SqStack S);
Status GetTop(SqStack S,SElemType &e);//取栈顶元素 
Status Push(SqStack &S,SElemType e);//元素入栈 
Status Pop(SqStack &S,SElemType &e);//元素出栈 
Status StackEmpty(SqStack S);//判断栈是否为空 
Status DestroyStack(SqStack &S);//销毁栈 
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
			printf("初始化成功");
		}
		else
		printf("初始化失败"); 
		break;
		case 2:printf("输入栈的长度：");
		scanf("%d",&n); 
		s=CreateStack(S,n);
		if(s)
		printf("创建成功");
		else
		printf("创建失败");
		break;
		case 3: 
		PrintStack(S);
		break;
		case 4:
			s= GetTop(S,e);
			if(s)
			printf("取栈顶元素为%d",e);
			else
			printf("取栈顶元素失败");
			break; 
			case 5:
				printf("输入入栈元素：");
					scanf("%d",&e);
					s=Push(S,e);
				if(s)
				printf("%d入栈成功",e);
				else
				printf("入栈失败");
				break;
				case 6:
				s=Pop(S,e);
				if(s)
				printf("%d出栈成功",e);
				else
				printf("出栈失败");
				break;
				case 7:
				s= StackEmpty(S);
				if(s)
				printf("栈不为空");
				else
				printf("栈为空");
				break;
				case 8:s=DestroyStack(S);
				if(s)
				printf("销毁栈成功");
				else
				printf("销毁栈失败");
				break;
				case 0:printf("谢谢使用该程序");
				exit(0);	
	}

	}

	return 0;
}
//菜单函数
int caidan()
{
	int sn;
	printf("\n显示菜单\n");
	printf("0:退出程序\n");
	printf("1:初始化栈\n");
	printf("2:创建栈\n");
	printf("3:显示栈内元素\n");
	printf("4:取栈顶元素\n");
	printf("5:元素入栈\n");
	printf("6:元素出栈\n");
	printf("7:判断栈是否为空\n");
	printf("8:销毁栈\n") ;
	printf("\n请输入0~8\n");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>8)
		printf("输入错误，请重新输入0~8\n");
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
	  
 Status CreateStack(SqStack &S,int n)//n个元素入栈 
 {
 	int i;
 	if(n>S.stacksize)
 	return ERROR;
 	printf("输入%d个整型数",n); 
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
 
 

