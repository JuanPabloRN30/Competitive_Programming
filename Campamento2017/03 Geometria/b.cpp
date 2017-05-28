#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll suma( ll a, ll b )
{
    return (a+b)%2;
}

ll producto( ll a, ll b )
{
    return a*b;
}

ll combina2( ll n )
{
    return (n * (n - 1) ) / 2;
}

ll combina3( ll n )
{
    return ( ((n * (n - 1)) / 2) * (n - 2) ) / 3;
}

int main()
{
    int n;
    scanf("%d",&n);
    //vector < point > points( n );
    int x,y;
    ll number[ 4 ];
    number[ 0 ] = number[ 1 ] = number[ 2 ] = number[ 3 ] = 0;
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d%d",&x, &y);
        if( x%2 == 0 && y%2 == 0)
            number[ 0 ]++;
        else if( x%2 == 0 && y%2 != 0)
            number[ 1 ]++;
        else if( x%2 != 0 && y%2 == 0)
            number[ 2 ]++;
        else
            number[ 3 ]++;
    }
    ll solucion = 0;
    for( ll i = 0 ; i <= 3 ; i++ )
    {
        for( ll j = i ; j <= 3 ; j++ )
        {
            for( ll k = j ; k <= 3 ; k++ )
            {
                ll first = producto( i>>1, suma( j&1, k&1 ) );
                ll second = producto( j>>1, suma( i&1, k&1 ) );
                ll third = producto( k>>1, suma( j&1, i&1 ) );
                ll resultado = suma( first, suma( second, third ) );
                if( !resultado )
                {
                    if( i == j && j == k )
                        solucion += combina3( number[ i ] );
                    else if( i == j && j != k )
                        solucion += combina2( number[ i ] ) * number[ k ];
                    else if( i != j && j == k )
                        solucion += combina2( number[ j ] ) * number[ i ];
                    else if( i != j && j != k )
                        solucion += number[ i ] * number[ j ] * number[ k ];
                    else if( i == k && j != i )
                        solucion += combina2( number[ i ] ) * number[ j ];
                }
            }
        }
    }
    printf("%lld\n",solucion);
    return 0;
}
