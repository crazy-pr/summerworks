#include<stdio.h>
#include <conio.h>
void Output(char s[],int n)
{   for(int i=0;i<n;i++)printf("%6c",s[i]); }
void BubbleSort(char s[],int n)
{
	int j;
	int i;
	char t;
	for(j=0;j<n;j++){
		for(i=0;i<n-j;i++){
			if(s[i]<s[i+1])
			{
				t=s[i];
				s[i]=s[i+1];
				s[i+1]=t;
			}
		}
	}
}

void Input(char s[],int n)
{
   for(int i=0;i<n;i++){
      printf("\ns[%d]=",i);   
      putch(s[i]=getch());
   }
}
int main(void)
{
char c[10];
Input(c,10);			//输入
BubbleSort(c,10); 		//排序(完成此函数)
Output(c,10);			//输出
getch();
return 0;
}

 
