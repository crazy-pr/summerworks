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
//����һ������ͷ��һ������β
struct emp *Head;//��Ϊȫ�ֱ���
struct emp *end=NULL;
FILE *fp;
void Exit();//�˳�����
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
		printf(" \t\t        ְ������ϵͳ--���ߣ�С����  ��Ȩ����\n");
        printf("\t\t=============================================\n");
        printf(" \t\t    1: ���ļ�                2: д�ļ�\n");
        printf("\t\t     3: ��ʾ����ְ����Ϣ      4: ����ְ����Ϣ\n");
        printf("\t\t     5:  ��ѯ                 7: ���ְ����Ϣ\n");
        printf("\t\t     0: �˳�����  6�� ɾ��    8���޸�\n");
        printf("\t\t=============================================\n");
        printf("\t\t     ��ѡ��:");
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
	system("cls");//������Ļ
	}
    
	return 0;
}
void Change()
{
if(Head==end)
{
	printf("������������.\n");
	system("pause");
	return;
	}
	else{
struct emp *p;
	int worknum;
	char sure[2];
	printf("������Ҫ�޸ĵ�ְ���ţ�");
	scanf("%d",&worknum);
	p=Head->next;
	while((p!=NULL)&&(p->num!=worknum))
	{
		p=p->next;
	 } 
	 if(p==NULL)
	 printf("��ְ���Ų�����");
	 else
	 {  printf("��ְ������Ϣ����                                                  ");
	 	printf("                 ����    ����      �Ա�      ����\n");
	 	printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 	
	 	printf("\n\n�����Ƿ��޸�%d��ְ����Ϣ��(y/n)",p->num);
	 	scanf("%s",sure);
	 	if((sure[0]=='y')||(sure[0]=='Y'))
	 	{
	 	  printf("����:");
	      scanf("%s",p->name);
          printf("�Ա�:");
	       scanf("%s",p->gender);
           printf("����:");
	       scanf("%d",&p->salary);
		   printf("�޸ĳɹ���");
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
	printf("������Ҫ��ѯ��ְ���ţ�");
	scanf("%d",&worknum);
	p=Head->next;
	while((p!=NULL)&&(p->num!=worknum))
	{
		p=p->next;
	 } 
	 if(p==NULL)
	 printf("��ְ���Ų�����");
	 else
	 {  printf("��ְ������Ϣ����                                                  ");
	 	printf("                 ����    ����      �Ա�      ����\n");
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
	 		printf("ɾ���ɹ���"); 
		 }
	 }
	 system("pause");
}
void QueryBynum()
{


struct emp *p;
	int worknum;
	
	
printf("������Ҫ��ѯ��ְ���ţ�");
	scanf("%d",&worknum);
	p=Head->next;
	while((p!=NULL)&&(p->num!=worknum))
	{
		p=p->next;
	 } 
	 if(p==NULL)
	 printf("��ְ���Ų�����");
	 else
	 {  printf("��ְ������Ϣ����                                                  ");
	 	printf("                 ����    ����      �Ա�      ����\n");
	 	printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 }
	 system("pause");
	
 } 
 void QueryBysalary()
{

int count=0;
struct emp *p;
	int maxsalary,minsalary;
printf("�������ѯ���ʵ����޺����ޣ�");
	scanf("%d%d",&maxsalary,&minsalary);
	p=Head->next;
	while(p!=NULL)
	{
	 	if((p->salary>=minsalary)&&(p->salary<=maxsalary))
	 	{
	 		count++;
	 		if(count==1)
		{
	    printf("��ְ������Ϣ����                                                  ");
	 	printf("                 ����    ����      �Ա�      ����\n");
	   }
	 	printf("                %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
	 	p=p->next;
	   }
	}
	    printf("�ܹ��ҵ�%d��",count); 
	 system("pause");
}
void Query()
{
	struct emp *p;
	int selection;
	printf("\n\n1-��ְ���źŲ�ѯ    2-�����ʲ�ѯ\n");
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
	if(Head!=end)//������� 
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
		printf("����(0=return)��");
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
	  printf("����:");
	  scanf("%s",p->name);
      printf("�Ա�:");
	  scanf("%s",p->gender);
      printf("����:");
	  scanf("%d",&p->salary);
	//��������ͷ

	end->next=p;//�ѽڵ���뵽����β�� 
	end=p;
	end->next=NULL;
}
while(1);

}
void DisplayEmp()
{
	struct emp *p;
	p=Head->next;
	printf("\n\n\n\n\n\t\t   ְ����Ϣ����    \n\n\n");
	printf("                 ����    ����      �Ա�      ����\n");
	while(p!=NULL)
	{
    printf("                  %d      %s      %s      %d\n",p->num,p->name,p->gender,p->salary);
		//���һ����
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

