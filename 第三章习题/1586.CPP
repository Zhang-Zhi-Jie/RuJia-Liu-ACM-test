#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
char s[100];
char m[4] = {'C','H', 'O', 'N'};
int search(char c)
{
	for(int i=0; i<4; i++)
	{
		if(c == m[i])
		{
			return i;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double sum = 0;
		scanf("%s",s);
		int num[4] = {0};
		for(int i=0; i<strlen(s); i++)
		{
			if(isalpha(s[i]))
			{
				int t = 0;
				if(isdigit(s[i+1]))
				{
					if(isdigit(s[i+2]))
					t = (s[i+1]-'0')*10 + (s[i+2]-'0');
					else t = s[i+1] - '0';
					num[search(s[i])]+=t;
				}
				else
				num[search(s[i])]++;
			}
		}
		sum +=num[0]*12.01 + num[1]*1.008 + num[2]*16.00 + num[3]*14.01;
		printf("%.3f\n", sum);
	}
	return 0;
 } 
