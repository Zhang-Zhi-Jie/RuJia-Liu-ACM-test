#include<cstdio>
#include<algorithm>
using namespace std;
struct Pallet{
	int w, h;
}p[6];

void swap(int &a, int &b)
{
	int t;
	t = a; a = b; b = t;
}

int cmp(const Pallet &a, const Pallet &b)
{
	return a.w < b.w || (a.w == b.w && a.h < b.h);
}
int main()
{
//	freopen("input.txt", "r", stdin);
	while(scanf("%d%d", &p[0].w, &p[0].h)!=EOF)
	{
		int t;
		if(p[0].w > p[0].h)
		{
			swap(p[0].w, p[0].h);
		}
		for(int i=1; i<6; i++)
		{
			scanf("%d%d", &p[i].w, &p[i].h);
			if(p[i].w > p[i].h)
			{
				swap(p[i].w, p[i].h);
			}
		}
		sort(p, p+6, cmp);
//		for(int i=0; i<6; i++)
//		{
//			printf("%d %d\n",p[i].w, p[i].h);
//		}
		int ok = 1;
		for(int i=0; i<6; i+=2)
		{
			if(p[i].w != p[i+1].w || p[i].h != p[i+1].h)
			{
				ok = 0;
				break;
			}
		}
		if(p[0].w != p[2].w || p[0].h != p[4].w || p[2].h != p[4].h)
		{
			ok = 0;
		}
		if(ok) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
    }
	return 0;
}
