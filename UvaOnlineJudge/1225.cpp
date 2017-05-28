#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int cases;
    scanf("%d",&cases);
    while(  cases--  )
    {
        scanf("%d",&n);
        int digits[ 10 ];
        memset( digits, 0, sizeof digits );
        for( int i = 1 ; i <= n ; i++ )
        {
            int copia = i;
            while( copia != 0 )
            {
                digits[ copia%10 ]++;
                copia /= 10;
            }
        }
        for( int i = 0 ; i < 10 ; i++ )
        {
            if( i != 0 )
                printf(" ");
            printf("%d",digits[ i ]);
        }
        printf("\n");
    }

    return 0;
}

