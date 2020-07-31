//给定一个未排序的数列，找到此数列在已排序状态下的两个相邻值的最大差值，少于两个值时返回0。例如：给定数列 [1,3,2,0,1,6,8] 则 最大差值为3。注意：请尽量使用时间复杂度为O(n)的方案。
//输入描述:
//第一行输入单个整数N作为数列的大小，第二行输入所有数列中的元素M，共N个。0 < N <= 1000000, 0 < M < 2100000000
#include<stdio.h> 
int a[1000000];
int b[1000000]; 
int main()
{
	int i;
	int j;
	int temp;
	int n;
	int max;
    int k;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		if(n<2){
			return 0;//小于二返回 
		}
		else{
			scanf("%d",&a[i]);//输出数组 
		} 
	}
	for(i=0;i<n;i++)
	{
        k=i;
		for(j=i+1;j<n;j++){
           
		if(a[j]<a[k])
		{
            k=j;
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}//排序
		
		} 
 }
    max=b[0];
    
 for(i=0;i<n-1;i++)
 {
 	b[i]=a[i+1]-a[i];
     if(b[i]>max){
     max=b[i];//最大差值 
	 }
} 
	 printf("%d",max);
	 return 0; 
}
