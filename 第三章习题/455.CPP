#include<cstdio>
#include<cstring>
using namespace std;
char s[100];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int len = strlen(s);
		for(int i=1; i<=len; i++)
		{
			if(len%i) continue;
			int ok = 1;
			for(int j=0; j<i; j++)
			{
				for(int k=1; k<(len/i); k++)
				{
					if(s[j]!=s[j+k*i])
					{
						ok = 0;
						break;
					}
				}
				if(ok==0) break;
			}
			if(ok)
			{
				printf("%d\n",i);
				break;
			}  
		}
		if(T)  
        printf("\n");
	}
	return 0;
}
