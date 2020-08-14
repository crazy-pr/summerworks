#include <iostream>
#include "stdlib.h"
#include "string.h"
struct emp
{
	char name[20];
	char gender[10];
	int num;
	int salary;
	struct emp *next;
};
//定义一个链表头和一个链表尾
struct emp *Head;//作为全局变量
struct emp *end=NULL;
FILE *fp;
void Exit();//退出程序
void InputEmp();
void DisplayEmp();
void WriteToFile();
void ReadFromFile();
void Query();
void Dismiss();
void Change();


int main(int argc, char* argv[])
{
	Head=(struct emp*)malloc (sizeof(struct emp));
	Head->next=NULL;
	end=Head;
	int selection;
	system("color f0");
	while(1)
	{
		printf(" \t\t        职工管理系统--作者：小青龙  版权所有\n");
        printf("\t\t=============================================\n");
        printf(" \t\t    1: 读文件                2: 写文件\n");
        printf("\t\t     3: 显示所有职工信息      4: 输入职工信息\n");
        printf("\t\t     5:  查询                 7: 浏览职工信息\n");
        printf("\t\t     0: 退出程序  6： 删除    8：修改\n");
        printf("\t\t=============================================\n");
        printf("\t\t     请选择:");
	    scanf("%d",&selection);
		switch(selection)
		{
		case 0:Exit();break;
		case 1:ReadFromFile();break;
			
	    case 2:WriteToFile();break;
	    case 8:Change();break;
			
		case 4:InputEmp();break;
		case 5:Query();break;
		case 6:Dismiss();break;	
		case 7:DisplayEmp();break;
			default:;

		}
	system("cls");//清理屏幕
	}
    
	return 0;
}
void Change()
{
if(Head==end)
{
	printf("链表中无数据.\n");
	system("pause");
	return;
	}
	else{
struct emp *p;
	int worknum;
	char sure[2];
	printf("请输入要修改的职工号：");
	scanf("%d",&worknum);
	p=Head->next;
	while((p!=NULL)&&(p->num!=worknum))
	{
		p=p->next;
	 } 
	 if(p==NULL)
	 printf("该职工号不存在");
	 else
	 {  printf("该职工的信息如下                                                  ");
	 	printf("                 工号    姓名      性别      工资\n");
	 	printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 	
	 	printf("\n\n请问是否修改%d号职工信息？(y/n)",p->num);
	 	scanf("%s",sure);
	 	if((sure[0]=='y')||(sure[0]=='Y'))
	 	{
	 	  printf("姓名:");
	      scanf("%s",p->name);
          printf("性别:");
	       scanf("%s",p->gender);
           printf("工资:");
	       scanf("%d",&p->salary);
		   printf("修改成功！");
		 }
	 
}
}
system("pause");
return;	
}
void Dismiss()
{
	struct emp *p,*q;
	int worknum;
	char sure[2];
	printf("请输入要查询的职工号：");
	scanf("%d",&worknum);
	p=Head->next;
	while((p!=NULL)&&(p->num!=worknum))
	{
		p=p->next;
	 } 
	 if(p==NULL)
	 printf("该职工号不存在");
	 else
	 {  printf("该职工的信息如下                                                  ");
	 	printf("                 工号    姓名      性别      工资\n");
	 	printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 	printf("are you sure to delete this?(y/n)");
	 	scanf("%s",sure);
	 	if((sure[0]=='Y')||sure[0]=='y')
	 	{
	 		q=Head;
	 		while(q->next!=p)
	 		q=q->next;
	 		q->next=p->next;
	 		if(end==p)
	 		end=q;
	 		free(p);
	 		printf("删除成功！"); 
		 }
	 }
	 system("pause");
}
void QueryBynum()
{


struct emp *p;
	int worknum;
	
	
printf("请输入要查询的职工号：");
	scanf("%d",&worknum);
	p=Head->next;
	while((p!=NULL)&&(p->num!=worknum))
	{
		p=p->next;
	 } 
	 if(p==NULL)
	 printf("该职工号不存在");
	 else
	 {  printf("该职工的信息如下                                                  ");
	 	printf("                 工号    姓名      性别      工资\n");
	 	printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 }
	 system("pause");
	
 } 
 void QueryBysalary()
{

int count=0;
struct emp *p;
	int maxsalary,minsalary;
printf("请输入查询工资的上限和下限：");
	scanf("%d%d",&maxsalary,&minsalary);
	p=Head->next;
	while(p!=NULL)
	{
	 	if((p->salary>=minsalary)&&(p->salary<=maxsalary))
	 	{
	 		count++;
	 		if(count==1)
		{
	    printf("该职工的信息如下                                                  ");
	 	printf("                 工号    姓名      性别      工资\n");
	   }
	 	printf("                %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 	p=p->next;
	   }
	}
	    printf("总共找到%d：",count); 
	 system("pause");
}
void Query()
{
	struct emp *p;
	int selection;
	printf("\n\n1-按职工号号查询    2-按工资查询\n");
	scanf("%d",&selection);
	switch(selection)
	{
		case 1: QueryBynum();
		break;
		case 2: QueryBysalary();
		break;
		default:;
		
	}
	  
}
void ReadFromFile()
{
	char sure[2];
	printf("are you sure?(y/n)");
	scanf("%s",sure);
	if((sure[0]=='N')||(sure[0]=='n'))
	return;
	struct emp *p,*q;
	if(Head!=end)//清除链表 
	{
		p=Head->next;
		do
		{
			q=p->next;
			free(p);
			p=q;
		}
		while(p!=NULL);
		end=Head;
	}
		fp=fopen("C:\\emp.txt","r");
		while(feof(fp))
		{
		p=(struct emp*)malloc (sizeof(struct emp));
		fscanf(fp,"%d%s%s%d",&p->num,p->name,p->gender,&p->salary);
		end->next=NULL;
	   }
	fclose(fp);
		printf("Read file successfully!\n");
	system("pause");	
	
}
void WriteToFile()
{
	struct emp *p;
	char sure[2];
	printf("are you sure?(y/n)");
	scanf("%s",sure);
	if((sure[0]=='N')||(sure[0]=='n'))
	
	return;
if((fp=fopen("c:\\emp.txt","w"))==NULL)
	{
		printf("open file failure");
		system("pause");
		return;
	}
	p=Head->next;
	while(p!=NULL)
	{
	fprintf(fp,"%d %s %s %d\n",p->num,p->name,p->gender,p->salary);
	p=p->next;
    }
	fclose(fp);
	printf("Write file successfully!\n");
	system("pause");	
}

void InputEmp()
{
	struct emp *p,*q;
	int worknum;
	bool Repeat;
	do
	{
		do{
		printf("工号(0=return)：");
		scanf("%d",&worknum);
		if(worknum==0)
		return;
		else
		{
			Repeat=0;
			q=Head->next;
			while(q!=NULL)
			{
				if(q->num==worknum)
				Repeat=1;
				q=q->next;
			}
		}
		
	      }while(Repeat);
		 
	  p=(struct emp*)malloc (sizeof(struct emp));
	  p->num=worknum;
	  printf("姓名:");
	  scanf("%s",p->name);
      printf("性别:");
	  scanf("%s",p->gender);
      printf("工资:");
	  scanf("%d",&p->salary);
	//插入链表头

	end->next=p;//把节点插入到链表尾部 
	end=p;
	end->next=NULL;
}
while(1);

}
void DisplayEmp()
{
	struct emp *p;
	p=Head->next;
	printf("\n\n\n\n\n\t\t   职工信息如下    \n\n\n");
	printf("                 工号    姓名      性别      工资\n");
	while(p!=NULL)
	{
    printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
		//输出一个人
        p=p->next;
	}
	getchar();
	getchar();
}
void Exit()
{
	char sure;
	printf("Are you sure to exit?(y/n):");
	getchar();
	scanf("%c",&sure);
	if((sure=='Y')||(sure=='y'))
		exit(0);
	
}

