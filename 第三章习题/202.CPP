#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3000+5;
int r[maxn],u[maxn],s[maxn];
int a,b;

int main()
{
	int t;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
	    t = a;
	    memset(r,0,sizeof(r));
	    memset(u,0,sizeof(u));
	    int index = 0;
	    r[index++] = a / b;
	    a = a%b;
	    while(!u[a] && a)
	    {
	        u[a] = index;
	        s[index] = a;
	        r[index] = 10*a/b;
	        a=10*a%b;
//	        printf("%d %d %d %d\n", u[a], s[index], r[index], a);
	        index++;
	    }
	    printf("%d\n",a);
	  	printf("%d/%d = %d",t,b,r[0]);  
        printf(".");  
	    for(int i=1; i<index && i<=50; i++)
	    {
	    	if(a && s[i] == a) printf("(");
	    	printf("%d", r[i]);
		}
	    if (!a) printf("(0");  
        if (index > 50) printf("...");  
        printf(")\n");  
        printf("   %d = number of digits in repeating cycle\n\n",!a ? 1 : index-u[a]);  
	}
    return 0;
}
