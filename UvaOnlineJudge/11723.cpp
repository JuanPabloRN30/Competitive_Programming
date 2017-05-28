#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,n;
    int cases = 0;
    while( scanf("%d%d",&r,&n) && (r+n) )
    {
        int result = floor( (double)(r/n) );
        if( r%n == 0 )
            result--;
        if( result > 26 )
            printf("Case %d: impossible\n",++cases);
        else
            printf("Case %d: %d\n",++cases,result);
    }
    return 0;
}
