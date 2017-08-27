#include <iostream>
#include <string.h>

using namespace std;

const int INF = 1e9;

int memo[ 1010 ][ 1010 ];

int dp( int n, int num_res)
{
    if( n < 0 || num_res < 0)
        return -INF;
    if( memo[ n ][ num_res ] != -1 )
        return memo[ n ][ num_res ];
    if( n == 0 )
        return 0;
    return memo[ n ][ num_res ] = max(dp( n, num_res - 1 ),dp( n - num_res, num_res - 1) + 1);
}

int cont;

void print_path( int n, int num_res)
{
    if( n < 0 || num_res < 0)
        return ;
    if( dp( n - num_res, num_res - 1) + 1 == memo[ n ][ num_res ] )
    {
        if( cont != 1 )
            printf(" ");
        printf("%d",num_res);
        cont++;
        print_path( n - num_res, num_res - 1 );
        return;
    }
    if( dp( n , num_res - 1 ) == memo[ n ][ num_res ])
    {
        print_path( n, num_res - 1 );
    }
}

int main()
{
    int n;
    cont = 1;
    memset( memo, -1, sizeof memo );
    scanf("%d",&n);
    cout << dp( n, n ) << endl;
    print_path( n, n );
    cout << endl;

    return 0;
}
