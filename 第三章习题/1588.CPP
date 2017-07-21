#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100+5;
char s1[maxn], s2[maxn];

bool test(int k, char *s1, char *s2)
{
	for(int i=0; s1[k+i]&&s2[i]; i++)
	{
		if(s1[k+i] + s2[i] - 2*'0' > 3)
		return false;
	}
	return true;
}

int solve(char *s1, char *s2)
{
	int k = 0;
	while(!test(k, s1, s2))
	{
		k++;
	}
	return max(strlen(s1), strlen(s2) + k);
}
int main()
{
//	freopen("input.txt", "r", stdin);
	while(scanf("%s%s",s1, s2)!=EOF)
	{
		printf("%d\n", min(solve(s1, s2), solve(s2, s1)));
	}
	return 0;
}
