//��⿵��չ��ʽ x=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!
//a[n]������Ԫ�����ڵ����򣨴��㿪ʼ�� 
//���磺��35412��{1��2��3��4��5��}�� ���ɵ��������ǵڼ���
//2*4��+3*3��+2*2��+0*1��+0*0��
//��׳����õݹ麯�� 
#include<stdio.h>
void cal();
void cal(){
	int fac[100];
	fac[0]=1;
	for(int i=1;i<=9;i++) 
	fac[i]=fac[i-1]*i;
}

//����չ�� 
int kangtuo(int* a,int n){
	int label[100];
	int fac[100];
	int ans=0;
	for(int i=0;i<=n;i++) 
	label[i]=1;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<a[i];j++) 
		if(label[j]) cnt++;
		label[a[i]]=0;
		ans+=cnt*fac[n-i-1];
	}
	return ans;
}
int main()
{
	int sum;
	int a[5]={3,5,4,1,2};
	sum=kangtuo(a,5);
	printf("������ǵڼ���%d",sum);
	
}

