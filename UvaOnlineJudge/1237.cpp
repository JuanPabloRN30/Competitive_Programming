#include <bits/stdc++.h>

using namespace std;

string names[ 10010 ];
int low[ 10010 ];
int high[ 10010 ];

int result( int d, int q )
{
    int cont = 0;
    int pos;
    for( int i = 0 ; i < d ; ++i )
    {
        if( q >= low[ i ] && q <= high[ i ] )
        {
            cont++;
            pos = i;
        }
    }
    return cont > 1 || cont == 0 ? -1 : pos;
}

int main()
{
    int t,d,q,p,res;
    int cont = 0;
    scanf("%d",&t);
    while( t-- )
    {
        if( cont ) cout << '\n';
        cont++;
        scanf("%d",&d);
        for( int i = 0 ; i < d ; ++i )
        {
            cin >> names[ i ] >> low[ i ] >> high[ i ];
        }
        scanf("%d",&q);
        for( int i = 0 ; i < q ; ++i )
        {
            scanf("%d",&p);
            res = result( d, p );
            if( res == -1 )
                printf("UNDETERMINED\n");
            else
                cout << names[ res ] << '\n';
        }
    }
    return 0;
}
