#include<stdio.h>
#include<math.h>
//���������ε�����Ĺ�ʽ�ú��׹�ʽ  temp=sqrt(s*(s-a)*(s-b)*(s-c));
//��Ҫ˼·��1.�ж��Ƿ������������Σ�Ȼ�����ù�ʽ���м��� 
int main()
{
	double a,b,c,l,s;
	printf("�����������εı߳���"); 
	scanf("%lf%lf%lf",&a,&b,&c);
	l=(a+b+c)/2;
	 if(((a+b)>c)&&((a+c)>b)&&((b+c)>a)&&((a-b)<c)&&((a-c)<b)&&((b-c)<a))//�ж��������Ƿ���� 
	 {
	 	s=sqrt(l*(l-a)*(l-b)*(l-c));//���׹�ʽ
	 	printf("��������ε������%f",s);
	 }
	 else{
	 	printf("��������β�����!");
	 }
	
 } 
