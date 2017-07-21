#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
using namespace std;
int c, d;
int main()
{
	char a[5][5];
	bool line = false;
	int kase = 0;
//	freopen("input.txt", "r", stdin);
	while ( gets (a [0]) ) {

        if ( strcmp (a[0], "Z") == 0 ) return 0;
        gets (a [1]);
        gets (a [2]);
        gets (a [3]);
        gets (a [4]);
//		for(int i=0; i<5; i++)
//		{
//			for(int j=0; j<5; j++)
//			{
//				printf("%c ",a [i][j]);
//			}
//			printf("\n");
//		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(a[i][j]==' ')
				{
					c=i;d=j;
					break;
		    	}
			}
		}
		
		char command [1000];
		int mad = 0;
        bool exit_koro = false;

        while ( !exit_koro && gets(command)) {
            for ( int i = 0; command [i] != 0; i++ ) {
                if ( command [i] == '0' || mad ) {
                    exit_koro = true;
                    break;
                }
				switch(command[i])
				{
					case 'A':
					if ( c == 0 ) mad = 1;
				    else
				    {
					    a[c][d]=a[c-1][d];
					    a[--c][d]=' ';
				    }
				    break;
				    
				    case 'B':
					if ( c == 4 ) mad = 1;
				    else
				    { 
					    a[c][d]=a[c+1][d];
					    a[++c][d]=' ';
				    } 
				    break;
				    
				    case 'L':
					if ( d == 0 ) mad = 1;
				    else
				    { 
					    a[c][d]=a[c][d-1];
					    a[c][--d]=' ';
				    } 
				    break;
				    
				    case 'R':
					if ( d == 4 ) mad = 1;
				    else
				    { 
					    a[c][d]=a[c][d+1];
					    a[c][++d]=' ';
				    } 
				    break;
				}
			}
		}
		if ( line )
            printf ("\n");
      		line = true;
        
		printf("Puzzle #%d:\n", ++kase);
		if(mad == 1)
		{
			printf("This puzzle has no final configuration.\n");
		}		
		else
		{
			for ( int i = 0; i < 5; i++ ) {
                printf ("%c %c %c %c %c\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
            }
	 	}
	}
	return 0;
}
