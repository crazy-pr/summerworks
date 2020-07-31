#include<stdio.h>
int maq(int m,int n)
{
	int c;
	while(n!=0){
		   c=m%n;
			m=n;
			n=c;
		}
	return m;
}
int main()
{
	int a,b;
	int t;
	printf("请输入两个数：");
	scanf("%d%d",&a,&b);
	if(a<b){
		t=a;
		a=b;
		b=t;
		a=maq(a,b);
	}//判断a,b的大小 
	else{
     a=maq(a,b);//调用函数		
		}
	printf("输出最大公约数：%d",a);
     return 0;
}
//出现的错误：第一交换后的的最后求出来的最大公约数是哪个；
//第二调用函数的定义，将调用函数放在主函数的前面 
