//��Ŀ����
//��һά����洢ѧ�źͳɼ���Ȼ�󣬰��ɼ����������
///��������:
//�����һ�а���һ������N(1<=N<=100)������ѧ���ĸ�����
//��������N��ÿ�а�����������p��q���ֱ����ÿ��ѧ����ѧ�źͳɼ���
//�������:
//����ѧ���ĳɼ���С����������򣬲���������ѧ����Ϣ��ӡ������
//���ѧ���ĳɼ���ͬ������ѧ�ŵĴ�С���д�С��������


#include<stdio.h>
struct student
{
	int num;
	int score;
};
int main()
{
	int n;
	scanf("%d",&n);//����ѧ���ĸ���
	struct student stu[101];//�洢ѧ���ĸ���
	struct student temp;
	int i,k,j;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&stu[i].num,&stu[i].score);//����ѧ�źͳɼ� 
	 }  
	for(i=0;i<n;i++) //......................ѡ������ 
	{ 
	    k=i;
		for(j=i+1;j<n;j++)
		{
			if(stu[j].score<stu[k].score)
			{
				k=j;//��ʱ�Ѿ���j��ֵ��k; 
				temp.score=stu[k].score;
				stu[k].score=stu[i].score;
				stu[i].score=temp.score;
			}
			if(stu[j].score==stu[j+1].score)
			{
				if(stu[j].num<stu[k].num)
				{
					k=j;//��ʱ�Ѿ���j��ֵ��k; 
				temp.num=stu[k].num;
				stu[k].num=stu[i].num;
				stu[i].num=temp.num;
				}
				
			}
			
			
		}
		
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",stu[i].num,stu[i].score);
	}
		
	return 0;
		
 } 
