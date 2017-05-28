#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,b,l,r;
    while( scanf("%d%d",&s,&b) && (s+b) )
    {
        int left[ s + 1 ];
        int right[ s + 1 ];
        for( int i = 0 ; i <= s ; i++ )
        {
            left[ i ] = i - 1;
            right[ i ] = i + 1;
        }
        for( int i = 0 ; i < b ; i++ )
        {
            scanf("%d%d",&l,&r);
            left[ right[ r ] ] = left[ l ];
            right[ left[ l ] ] = right[ r ];
            if( left[ l ] >= 1 && right[ r ] <= s )
                printf("%d %d\n",left[ l ], right[ r ]);
            else if( left[ l ] == 0 && right[ r ] <= s )
                printf("* %d\n",right[ r ]);
            else if( right[ r ] == s + 1 && left[ l ] >= 1)
                printf("%d *\n",left[ l ]);
            else
                printf("* *\n");
        }
        printf("-\n");
    }
    return 0;
}
