#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int formula( int n )
{
    return ( ( n ) * ( n - 1) * ( n - 2 ) ) / 6;
}

int bitsOn( int n )
{
    int acum = 0;
    if( n < 0 )
        return 0;
    while( n )
    {
        if( n&1 )
            acum++;
        n >>= 1;
    }
    return acum;
}

int main()
{
    long long n;
    while( scanf("%lld",&n) != EOF )
    {
        int res = ceil(log2(n));
        if( res < 3 )
            cout << 0 << endl;
        int res1 = ceil(log2(n-(1<<(res-1))));
        int resultado = formula( res-1 ) + formula(res1 + 1);

        cout << resultado << endl;
//        printf("Day %lld: Level = %d\n",n,level);
    }

    return 0;
}

