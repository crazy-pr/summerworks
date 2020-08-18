//编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
//输入
//abaca
//输出
//3
//输入描述:
//输入N个字符，字符在ACSII码范围内。
//输出描述:
//输出范围在(0~127)字符的个数。
#include<stdio.h> 
#include<string.h>//有的字符的函数要加这个头文件 
int main()
{
	int i,len;
	int num=0;
	char a[200];
	char b[128]={0};
	gets(a);//输入数组
	len=strlen(a);//字符串的长度//strlen()函数用来计算字符串的长度，C语言strlen 函数用来求字符串的长度(包含多少个字符)。
//strlen() 函数从字符串的开头位置依次向后计数，直到遇见\0，然后返回计时器的值。最终统计的字符串长度不包括\0。头文件:string.h语法/原型:
//size_t strlen(const char* str);
	for(i=0;i<len;i++)
	{
	if(a[i]>=0&&a[i]<=127)
	{
	b[a[i]]++;
    }		
	 } 
	 for(i=0;i<127;i++)
	 {
	 	
	 	if(b[i]>0)
	 	{
	 		num++;
		 }
	 }
	 printf("%d",num);
	 return 0;	 
						
}
