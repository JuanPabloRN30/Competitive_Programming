#include <iostream>
#include <bitset>

using namespace std;

bitset < 10000010 > bs;

void sieve()
{
    bs.set();
    bs[ 0 ] = bs[ 1 ] = false;
    for( long long i = 2 ; i<= 1e6 ; i++ )
    {
        if( bs[ i ] )
        {
            for( long long j = i * i ; j <= 1e6 ; j*= i )
            {
                bs[ j ] = false;
            }
        }
    }
}

int main()
{
    sieve();
    int n;
    scanf("%d",&n);
    for( int i = 1 ; i <= 1e3 ; i++ )
    {
        int result = (n * i) + 1;
        if( !bs[ result ] )
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
