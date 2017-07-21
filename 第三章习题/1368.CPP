#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char *DNA="ACGT";
char Dna_Cs[50+5][1000+5];

int main()
{
//	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m,n;
		scanf("%d%d\n",&m,&n);
		int sum[4]={0};
		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%c",&Dna_Cs[i][j]);
			}
			getchar();
		}
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			for(int g=0;g<4;g++)
			{
				sum[g]=0;
			}
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<4;k++)
				{
					if(Dna_Cs[j][i]==DNA[k])
					{
						sum[k]++;
					}
			    }
			}
			int max=sum[0];
			int p=0;
			for(int q=1;q<4;q++)
			{
				if(sum[q]>max)
				{
				max=sum[q];
				p=q;
			    }
			}
	//		printf("p=%d\n",p);
			printf("%c",DNA[p]);
			for(int j=0; j<m; j++)
			{
				if(DNA[p] != Dna_Cs[j][i])
				cnt++;
			}
		}
		printf("\n");
		printf("%d\n",cnt);
	}
	return 0;
}
