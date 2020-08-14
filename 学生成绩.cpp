//题目描述
//用一维数组存储学号和成绩，然后，按成绩排序输出。
///输入描述:
//输入第一行包括一个整数N(1<=N<=100)，代表学生的个数。
//接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
//输出描述:
//按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。
//如果学生的成绩相同，则按照学号的大小进行从小到大排序。


#include<stdio.h>
struct student
{
	int num;
	int score;
};
int main()
{
	int n;
	scanf("%d",&n);//输入学生的个数
	struct student stu[101];//存储学生的个数
	struct student temp;
	int i,k,j;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&stu[i].num,&stu[i].score);//输入学号和成绩 
	 }  
	for(i=0;i<n;i++) //......................选择排序 
	{ 
	    k=i;
		for(j=i+1;j<n;j++)
		{
			if(stu[j].score<stu[k].score)
			{
				k=j;//此时已经将j的值给k; 
				temp.score=stu[k].score;
				stu[k].score=stu[i].score;
				stu[i].score=temp.score;
			}
			if(stu[j].score==stu[j+1].score)
			{
				if(stu[j].num<stu[k].num)
				{
					k=j;//此时已经将j的值给k; 
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
