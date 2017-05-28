#include <bits/stdc++.h>

using namespace std;

char board[ 60 ][ 60 ];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for( int i = 0 ; i < n ; ++i )
    {
        for( int j = 0 ; j < m ; ++j )
        {
            cin >> board[ i ][ j ];
        }
    }

    return 0;
}
