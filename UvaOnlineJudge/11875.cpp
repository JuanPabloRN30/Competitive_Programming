#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases,n,age;
    scanf("%d",&cases);
    for( int i = 0 ; i < cases ; ++i )
    {
        scanf("%d",&n);
        int mid = ceil( n / 2.0);
        for( int j = 0 ; j < n ; j++ )
        {
            scanf("%d",&age);
            if( j+1 == mid )
                printf("Case %d: %d\n",i+1,age);
        }
    }
    return 0;
}
