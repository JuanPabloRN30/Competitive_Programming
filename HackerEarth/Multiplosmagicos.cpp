#include <iostream>
#include <stdio.h>

using namespace std;

bool arr[ 10 ];

void digitos( long long n, int &cont )
{
    while( n != 0 )
    {
        if( !arr[ n%10 ] )
            cont++;
        arr[ n%10 ] = true;
        n/=10;
    }
}

int main()
{
    long long n;
    while( scanf("%lld",&n) != EOF )
    {
        for( int i = 0 ; i < 10 ; i++)
            arr[ i ] = false;
        int cont = 0;
        int k = 2;
        while( cont < 10 )
        {
            for( int i = 0 ; i <= k ; i++ )
            {
                digitos( i*n, cont );
            }
            k++;
        }
        printf("%d\n",k-1);

    }

    return 0;
}

