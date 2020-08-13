//对于同一个除数，如果两个整数同余，那么他们的差就一定能被这个数整除

//三个数字比较大，但是他们对于m同余，那么当中任意两个数字的差必然是m倍数，要求m的最大的数值可以转化位求他们的三个差的最大公约数，从而降低计算的难度

//6520-14903=1617=3×7的平方×11，16520-14177=2343=3×11×71，14903-14177=726=2×3×11的平方，三个差的最大公约数是3×11=33,m的最大数字等于33.

//思路比较简单：

//第一步：输入三个数

//第二部：求三个数的差

//第三部：先求前两个数的最大公约数t,再求t和第三个数的最大公约数（求最大公余数可借助辗转相除法）
#include<stdio.h>
#define Max 100//不需要打分号 
int num[Max];
int val[Max];
int end[Max];
int i,n;
int qiuyushu(int a,int b)//辗转相除法 
{
	int r = a % b;//求余数 
	if(r==0)
		return b;
	else
		return qiuyushu(b,r);

	
}
void function(int num[],int n) 
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			val[k]=num[i]-num[j];	
			if	(val[k]>0)//判断两个数的大小 
			{
				val[k]=val[k];
			}
				else{
					val[k]=0-val[k];
				} 
              k++;
			}
	}
	
	int t=qiuyushu(val[0],val[1]);
	for(i=2;i<n;i++)
	{
		t=qiuyushu(t,val[i]);
	}
	printf("%d是%d的最大m/n",t,n);
}

int main()
{
	int i;
	printf("请输入元素的个数：");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
	printf("请输入第%d个元素：",i+1);
		scanf("%d",&num[i]);
	}
 
	function(num,n);

	return 0;
}

 
