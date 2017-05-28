#include <bits/stdc++.h>

using namespace std;

#define MAX 500

int dp[ MAX ][ MAX ];

int top( int n, int k )
{
    cout << n << " " << k << endl;
    if( k > n ) return 0;
    int r = top( n - k, k );
    if( k + 1 <= n )
    {
        r = min( r, top( n - k - 1 , k + 1 ) );
    }
    return 1 - r;
}

void precalc()
{
    dp[ 0 ][ 0 ] = 0;
/*    for( int i = 1 ; i <= n ; i++ )
    {
        //if(  )
    }*/
}

int main()
{

    int n;
    int cases = 0;
//    calculateGrundy( 10 );
    while( scanf("%d",&n) && n)
    {
        printf("Case #%d: ",++cases);
        //cout << "El resultado es: " << top( n,1 ) << endl;
        if( top( n,1 ) )
            printf("First");
        else
            printf("Second");
        printf(" player wins.\n");
    }
    return 0;
}
