//����ͬһ�������������������ͬ�࣬��ô���ǵĲ��һ���ܱ����������

//�������ֱȽϴ󣬵������Ƕ���mͬ�࣬��ô���������������ֵĲ��Ȼ��m������Ҫ��m��������ֵ����ת��λ�����ǵ�����������Լ�����Ӷ����ͼ�����Ѷ�

//6520-14903=1617=3��7��ƽ����11��16520-14177=2343=3��11��71��14903-14177=726=2��3��11��ƽ��������������Լ����3��11=33,m��������ֵ���33.

//˼·�Ƚϼ򵥣�

//��һ��������������

//�ڶ��������������Ĳ�

//������������ǰ�����������Լ��t,����t�͵������������Լ��������������ɽ���շת�������
#include<stdio.h>
#define Max 100//����Ҫ��ֺ� 
int num[Max];
int val[Max];
int end[Max];
int i,n;
int qiuyushu(int a,int b)//շת����� 
{
	int r = a % b;//������ 
	if(r==0)
		return b;
	else
		return qiuyushu(b,r);

	
}
void function(int num[],int n) 
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			val[k]=num[i]-num[j];	
			if	(val[k]>0)//�ж��������Ĵ�С 
			{
				val[k]=val[k];
			}
				else{
					val[k]=0-val[k];
				} 
              k++;
			}
	}
	
	int t=qiuyushu(val[0],val[1]);
	for(i=2;i<n;i++)
	{
		t=qiuyushu(t,val[i]);
	}
	printf("%d��%d�����m/n",t,n);
}

int main()
{
	int i;
	printf("������Ԫ�صĸ�����");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
	printf("�������%d��Ԫ�أ�",i+1);
		scanf("%d",&num[i]);
	}
 
	function(num,n);

	return 0;
}

 
