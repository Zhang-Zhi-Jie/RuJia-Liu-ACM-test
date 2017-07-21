#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100;
const int BIG = 10000;
int r, c, n;
int d[maxn][maxn], d2[maxn][maxn], ans[maxn][maxn], cols[maxn];

void copy(char type, int p, int q)
{
	if(type == 'R')
	{
		for(int i=1; i<=c; i++)
		{
			d[p][i] = d2[q][i];
		}
	}else{
		for(int i=1; i<=r; i++)
		{
			d[i][p] = d2[i][q];
		}
	}
}
/*删除*/
void del(char type)
{
	memcpy(d2, d, sizeof(d));
	int cnt = type == 'R' ? r : c, cnt2 = 0;//判断是删除行还是列 
	for(int i=1; i<=cnt; i++)
	{
		if(!cols[i]) copy(type, ++cnt2, i);
	}
	if(type == 'R') r = cnt2;//记录新行数 
	else c = cnt2;           //记录新列数 
}
/*插入*/ 
void ins(char type)
{
	memcpy(d2, d, sizeof(d));
	int cnt = type == 'R' ? r : c, cnt2 = 0;
	for(int i=1; i<=cnt; i++)
	{
		if(cols[i]) copy(type, ++cnt2, 0);
		copy(type, ++cnt2, i);
	}
	if(type == 'R') r = cnt2;
	else c = cnt2;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int r1, c1, r2, c2, q, kase = 0;
	char cmd[10];
	while(scanf("%d%d%d",&r, &c, &n)!=EOF && r)
	{
		int r0 = r, c0 = c;
		//构造一个表格 
		for(int i=1; i<=r; i++)
		{
			for(int j=1; j<=c; j++)
			{
				d[i][j] = i*BIG + j;//构造函数 
			} 
		} 
		while(n--)
		{
			scanf("%s",cmd);
			if(cmd[0] == 'E')
			{
				scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
				int t = d[r1][c1]; d[r1][c1] = d[r2][c2]; d[r2][c2] = t;//交换单元格 
			}else{
				int a, x;
				scanf("%d",&a);
				memset(cols, 0, sizeof(cols));
				for(int i=0; i<a; i++)
				{
					scanf("%d", &x);
					cols[x] = 1;              //记录要操作的行或列 
				}
				if(cmd[0] == 'D') del(cmd[1]);//删除 
				else ins(cmd[1]);             //插入 
			}
		}
//		for(int i=1; i<=r; i++)
//		{
//			for(int j=1; j<=c; j++)
//			{
//				printf("%d ",d[i][j]); 
//			}
//			printf("\n");
//		 } 
		memset(ans, 0, sizeof(ans));
		for(int i=1; i<=r; i++)
			for(int j=1; j<=c; j++)
			{
				ans[d[i][j]/BIG][d[i][j]%BIG] = i*BIG + j;
			}
		if(kase > 0) printf("\n");
//		for(int i=1; i<=r; i++)
//		{
//			for(int j=1; j<=c; j++)
//			{
//				printf("%d ",ans[i][j]); 
//			}
//			printf("\n");
//		} 
		printf("Spreadsheet #%d\n", ++kase);
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &r1, &c1);
			printf("Cell data in (%d,%d) ", r1, c1);
			if(ans[r1][c1] == 0) printf("GONE\n");
			else printf("moved to (%d,%d)\n", ans[r1][c1]/BIG, ans[r1][c1]%BIG);
		}
	}
	return 0;
} 
