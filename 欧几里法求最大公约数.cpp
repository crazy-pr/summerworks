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
	printf("��������������");
	scanf("%d%d",&a,&b);
	if(a<b){
		t=a;
		a=b;
		b=t;
		a=maq(a,b);
	}//�ж�a,b�Ĵ�С 
	else{
     a=maq(a,b);//���ú���		
		}
	printf("������Լ����%d",a);
     return 0;
}
//���ֵĴ��󣺵�һ������ĵ��������������Լ�����ĸ���
//�ڶ����ú����Ķ��壬�����ú���������������ǰ�� 
