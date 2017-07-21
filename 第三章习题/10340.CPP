#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100000+10;
char s1[maxn], s2[maxn];

int main()
{
//	freopen("input.txt", "r", stdin);
	while(~scanf("%s%s", s1, s2))
	{
		int j = 0, ok = 0;
		for(int i=0; i<strlen(s2); i++)
		{
			if(s2[i] == s1[j])
			{
				j++;
			}
			if(j == strlen(s1))
			{
				ok = 1;
				break;
			}
		}
		if(ok) printf("Yes\n");
		else printf("No\n");
	}
}
