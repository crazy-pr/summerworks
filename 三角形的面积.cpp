#include<stdio.h>
#include<math.h>
//计算三角形的面积的公式用海伦公式  temp=sqrt(s*(s-a)*(s-b)*(s-c));
//主要思路是1.判断是否存在这个三角形，然后在用公式进行计算 
int main()
{
	double a,b,c,l,s;
	printf("请输入三角形的边长："); 
	scanf("%lf%lf%lf",&a,&b,&c);
	l=(a+b+c)/2;
	 if(((a+b)>c)&&((a+c)>b)&&((b+c)>a)&&((a-b)<c)&&((a-c)<b)&&((b-c)<a))//判断三角形是否存在 
	 {
	 	s=sqrt(l*(l-a)*(l-b)*(l-c));//海伦公式
	 	printf("这个三角形的面积：%f",s);
	 }
	 else{
	 	printf("这个三角形不存在!");
	 }
	
 } 
