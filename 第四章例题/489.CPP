#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100;
char s1[maxn], s2[maxn];
int chance, left;
int lose, win;

void guess(char ch)
{
	int bad=1;
	for(int i=0; i<strlen(s1); i++)
	{
		if(ch == s1[i])
		{
			left--;
			s1[i] = ' ';
			bad = 0;
		}
	}
	if(bad) chance--; 
	if(!chance) lose = 1; 
	if(!left) win = 1;
}
int main()
{
//	freopen("input.txt", "r", stdin);
	int round;
	while(scanf("%d", &round)!=EOF && round != -1)
	{
		chance = 7;
		win = lose = 0; 
		scanf("%s%s",s1,s2);
		left = strlen(s1);
		for(int i=0; i<strlen(s2); i++)
		{
			guess(s2[i]);
			if(win || lose) break; 
		}
		printf("Round %d\n",round);
		if(lose) printf("You lose.\n");
		else if(win) printf("You win.\n");
		else printf("You chickened out.\n");
	}	
} 
