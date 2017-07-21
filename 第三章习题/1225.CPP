#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{ 
		int n;
		scanf("%d",&n);
		int num[10]={0};
	    for(int i=1;i<=n;i++)
	    {
	        int k=i;
	        while(k>0)
	        {
	        num[k%10]++;
	        k/=10;
			}   
		}
		for(int i=0;i<9;i++)
		{
			printf("%d ",num[i]);
		}
		printf("%d\n",num[9]);
	}
	 return 0;
}
