#include<stdio.h>
//����ʸ������ж�����ʱ�뻹��˳ʱ�롣
//��A(x1,y1),B(x2,y2),C(x3,y3),�����������ߵ�ʸ���ֱ��ǣ�
//AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)
//��AB��AC�Ĳ��Ϊ��(2*2������ʽ)
//|x2-x1, y2-y1|
//|x3-x1, y3-y1|
//ֵΪ��(x2-x1)(y3-y1) - (y2-y1)(x3-x1)
//�������ַ�������жϣ�
//���ABxAC>0����������ABC����ʱ��ģ�
//���ABxAC<0����������ABC��˳ʱ��ģ�
//���ABxAC=0����˵�����㹲�ߡ�
int main(){
	
double x1,x2,x3,y1,y2,y3;
printf("������������"); 
scanf("%lf%lf%lf%lf%lf%lf",&x1,&x2,&x3,&y1,&y2,&y3);
double a=x2-x1;
double b=x3-x1;
double c=y2-y1;
double d=y3-y1;
if((a*d-c*b)>0)
{
	printf("��ʱ�룡");
	 
}
else if((a*d-c*b)==0)
{
	printf("���ߣ�");
	 
}

else {
	printf("˳ʱ�룡"); 
}
return 0; 
} 
 
