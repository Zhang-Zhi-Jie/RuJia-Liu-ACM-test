#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char s[85];
		scanf("%s",s);
		int sum = 0;
		int t=0;
		for(int i=0; i<strlen(s); i++)
		{
			if(s[i]=='X')
			{
				sum +=0;
				t = 0;
			}
			else{
				t++;
				sum += t;
			}

		}
		printf("%d\n",sum);
	}
	return 0;
}
