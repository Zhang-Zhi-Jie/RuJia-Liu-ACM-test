#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int r, c;
char a[12][12];
int s[12][12];
struct Down{
	int id;
	char ch[12];
}d[100+10];

int cmp(const Down &a, const Down &b)
{
	return a.id < b.id;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int kase = 1;
	while(scanf("%d", &r)!=EOF && r)
	{
		scanf("%d",&c);
		for(int i=0; i<r; i++)
		{
			getchar();
			for(int j=0; j<c; j++)
			{
				scanf("%c", &a[i][j]);
			}

		}		
//		
//		for(int i=0; i<=r; i++)
//		{
//			for(int j=0; j<=c; j++)
//			{
//				printf("%c",a[i][j]);
//			}
//			printf("\n");
//		}
		int k = 0;
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				if((!isalpha(a[i-1][j]) || !isalpha(a[i][j-1])) && a[i][j] != '*')
				{
					s[i][j] = ++k;
				}
			}
		}
		if  (kase > 1) printf("\n");
		printf("puzzle #%d:\n", kase++);
		printf("Across\n");
		for (int i=0; i<r; i++)
		{  
            int move = 0;  
            while (move < c) 
			{  
                if (s[i][move]!=0) 
				{  
					
                    printf("%3d.",s[i][move]); 
                    while (move < c && a[i][move] != '*')  
                        printf("%c",a[i][move ++]);  
                    printf("\n");  
                }
				else move ++;  
            }  
        }  
        int f = 0;
		printf("Down\n");
		for (int i=0; i<c; i++)
		{  
            int move = 0;  
            while (move < r) 
			{  
                if (s[move][i]!=0) 
				{  
					d[f].id = s[move][i];
                    int t = 0;
                    while (move < r && a[move][i] != '*')  
                    	d[f].ch[t++] = a[move++][i];
                    f++;
                }
				else move ++;  
       		}
		}
		
		sort(d, d+f, cmp);
		for(int i=0; i<f; i++)
		{
			printf("%3d.%s\n", d[i].id, d[i].ch);
		}
	}
	return 0;
}
