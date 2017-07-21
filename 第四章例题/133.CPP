#include<cstdio>
using namespace std;
const int maxn = 20+5;
int N, k, m;
int a[maxn];

int move(int p, int k, int t)
{
	while(t--)
	{
		do{
			p = (p+k+N-1) % N + 1;
		}while(a[p] == 0);
	}
	return p;
}

int main()
{
	while(scanf("%d%d%d",&N, &k, &m)!=EOF)
	{
		if(N==0) break;	
		for(int i=1; i<=N; i++)
		{
			a[i] = i;
		} 
		int left = N;
		int p1 = N, p2 = 1; 
		while(left)
		{
			p1 = move(p1, 1, k);
			p2 = move(p2, -1, m);
			printf("%3d", p1);
			left--; 
			if(p1 != p2)
			{
			 	printf("%3d", p2);
			 	left--;
			}
			a[p1] = a[p2] = 0;
			if(left)
			printf(",");
		}
		printf("\n");
	}
	return 0;	
}
