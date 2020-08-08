//理解康托展开式 x=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!
//a[n]代表是元素所在的排序（从零开始） 
//例如：求35412在{1，2，3，4，5，}的 生成的排列中是第几大
//2*4！+3*3！+2*2！+0*1！+0*0！
//求阶乘运用递归函数 
#include<stdio.h>
void cal();
void cal(){
	int fac[100];
	fac[0]=1;
	for(int i=1;i<=9;i++) 
	fac[i]=fac[i-1]*i;
}

//康托展开 
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
	printf("这个数是第几大：%d",sum);
	
}

