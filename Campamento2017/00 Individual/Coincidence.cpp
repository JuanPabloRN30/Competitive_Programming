#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

string a,b;
int matriz[ 110 ][ 110 ];

int dp(int i, int j)
{
    if( i <= 0 || j <= 0 )
        return 0;
    if( matriz[ i ][ j ] != -1 )
        return matriz[ i ][ j ];
    if( a[ i ] == b[ j ] )
    {
        return matriz[ i ][ j ] = dp( i - 1, j - 1 ) + 1;
    }
    return matriz[ i ][ j ] = max(dp( i - 1, j ),dp( i, j - 1 ));
}

int main()
{
    miniI = miniJ = 1e9;
    maxiI = maxiJ = -1;
    cin >> a >> b;
    memset( matriz, -1, sizeof matriz );
    cout << dp( a.size()-1 , b.size() - 1 ) << endl;
    return 0;
}
