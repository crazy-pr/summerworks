//题目描述
//如果统计的个数相同，则按照ASCII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。

//实现以下接口：
//输入一个字符串，对字符中的各个英文字符，数字，空格进行统计（可反复调用）
//按照统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASCII码由小到大排序输出
///清空目前的统计结果，重新统计
//调用者会保证：
//输入的字符串以‘\0’结尾。
#include<stdio.h>
#include<string.h>
int main()
{
	char str[1000];
	int i,len;
	while(gets(str))
	{
		int count[256]={0};
		int max=0;
		len=strlen(str);//字符串的长度；
		for(i=0;i<len;i++)
		{
			count[str[i]]++;//每个字符的个数
			if(count[str[i]]>max)
			max=count[str[i]];// 从多到少 
		 } 
		 
		 
		 while(max)
		 {
		 	for(i=0;i<256;i++)
		 	{
		 		if(count[i]==max)
		 		{
		 			printf("%c",i);//输出对应的字符
					 max--; 
				 }
			 }
		  } 
		printf("\n");
		
	}
	return 0;
	
	
}
