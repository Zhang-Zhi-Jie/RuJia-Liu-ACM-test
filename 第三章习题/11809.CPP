/*
浮点数的指数形式由十进制数，加阶码标志“e”或“E”以及阶码（只能为整数，可以带符号）组成。其一般形式为：
a E n（a为十进制数，n为十进制整数）
*/

/*本题打表较好,lgM+Elg2=lgA+B*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long LL;
double M[10][31];
LL E[10][31];
char s[30];
double m,x;
int e;

int main(void)
{
//	freopen("input.txt", "r", stdin);
    for(int i=0;i<=9;i++)
    {
       for(int j=1;j<=30;j++)
       {
           m = 1-pow(2,-i-1);
           e = pow(2,j)-1;
           x = log10(m)+e*log10(2);
           E[i][j] = floor(x), M[i][j] = pow(10, x - floor(x));
       }
    }
    double A;
    int B;
    while(cin>>s)
    {
        if(s=="0e0")
        break;
        s[17]='/';
        sscanf(s,"%lf/%d",&A,&B);
        for(int i=0;i<=9;i++)
        {
            for(int j=1;j<=30;j++)
            {
                if(B==E[i][j]&&fabs(M[i][j]-A)<1e-4)
                {
                    printf("%d %d\n",i,j);
                }
            }
        }
    }
    return 0;
}
