#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100+10;
char s1[maxn], s2[maxn];
int n1[27], n2[27];

int main()
{
//	freopen("input.txt", "r", stdin); 
	while(scanf("%s", s1)!=EOF)
	{
		scanf("%s", s2);
		memset(n1, 0, sizeof(n1));
		memset(n2, 0, sizeof(n2));
		int len = strlen(s1);
		for(int i=0; i<len; i++)
		{
			n1[s1[i]-'A']++;
			n2[s2[i]-'A']++;
		}
		sort(n1, n1+26);
		sort(n2, n2+26);
//		for(int i=0; i<26; i++)
//		{
//			printf("%d %d\n", n1[i], n2[i]); 
//		}
		int ok = 1;
		for(int i=0; i<26; i++)
		{
			if(n1[i] != n2[i])
			{
				ok = 0;
				break;
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
