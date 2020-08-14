#include<stdio.h> 
//题目描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
// 解题思路：如果要登上的话，最后一步要在n-1或者在n-2上，那么就有两种情况，假设第一种情况那么就是f(n-1)*1,假设第二种情况就是f(n-2)*1
//f(1)=1 f(2)=2........f(10)=f(8)+(9)
int jumpfloor(int n)
{
	if(n<=2)
	{
	return n;	
	}
	if(n>=3)
	{
		
		return jumpfloor(n-1)+jumpfloor(n-2);//递归函数 
	}
	
}

int main ()
{
	int s=0;
	int n;
	scanf("%d",&n);
	s=jumpfloor(n); 
printf("一共有的跳法：%d",s);
return 0;
}
