#include<cstdio>
#include<cstring>
using namespace std;
char code[8][1<<8];
/*读取字符，可跨行*/ 
int readchar()
{
	for(;;)
	{
		int ch = getchar();
		if(ch != '\n' && ch != '\r')
		return ch;
	}
}
/*读取编码头，打到表中*/
int readcodes()
{
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for(int len=2; len<=7; len++)
	{
		for(int i=0; i<(1<<len)-1; i++)
		{
			int ch = getchar();
			if(ch == EOF) return 0;
			if(ch == '\n' || ch == '\r') return 1;
			code[len][i] = ch;
		} 
	}
	return 1;
}
/*读取c位二进制数，并转换为10进制返回*/
int readint(int c)
{
	int v = 0;
	while(c--)
	{
		v = 2*v + readchar() - '0';
	}
	return v;
}
/*调试所用*/
void printcodes()
{
	for(int len=1; len<=7; len++)
	{
		for(int i=0; i<(1<<len)-1; i++)
		{
			if(code[len][i] == 0) return;
			printf("code[%d][%d] = %c\n",len, i, code[len][i]);
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
	while(readcodes())
	{
//		printcodes();
		for(;;)
		{
			int len = readint(3);
			if(len == 0) break;
			for(;;)
			{
				int v = readint(len);
				if(v == (1<<len)-1) break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}
