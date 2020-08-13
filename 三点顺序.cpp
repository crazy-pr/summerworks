#include<stdio.h>
//利用矢量叉积判断是逆时针还是顺时针。
//设A(x1,y1),B(x2,y2),C(x3,y3),则三角形两边的矢量分别是：
//AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)
//则AB和AC的叉积为：(2*2的行列式)
//|x2-x1, y2-y1|
//|x3-x1, y3-y1|
//值为：(x2-x1)(y3-y1) - (y2-y1)(x3-x1)
//利用右手法则进行判断：
//如果ABxAC>0，则三角形ABC是逆时针的；
//如果ABxAC<0，则三角形ABC是顺时针的；
//如果ABxAC=0，则说明三点共线。
int main(){
	
double x1,x2,x3,y1,y2,y3;
printf("输入三个坐标"); 
scanf("%lf%lf%lf%lf%lf%lf",&x1,&x2,&x3,&y1,&y2,&y3);
double a=x2-x1;
double b=x3-x1;
double c=y2-y1;
double d=y3-y1;
if((a*d-c*b)>0)
{
	printf("逆时针！");
	 
}
else if((a*d-c*b)==0)
{
	printf("共线！");
	 
}

else {
	printf("顺时针！"); 
}
return 0; 
} 
 
