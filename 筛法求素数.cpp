#include<stdio.h>
#include<math.h>
int main()
{
	int a[101];
	int i,j;
	int c;
	for(i=1;i<=100;i++)
	{
		a[i]=i;//����һ�ٸ����� 
	}
	for(i=1;i<100;i++)
	{
		if(a[i]%2==0)
		{
			a[i]=0;
		}
		else{
		for(j=2;j<=sqrt(i);j++)
		{
		c=a[i]%j;
	   }
	                 }
		if(c==0){
			a[i]=0;
		}
		if(a[i]!=0)
		{
			printf(" %d",a[i]);
		}	
	} 
	
	return 0;
 } 
 //ע�����Ҫ����ֵΪ�㣬 sqrtΪ�����ź����������������ֵ�����Լ������Լ��� 
