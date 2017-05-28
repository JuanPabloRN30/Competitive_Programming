#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    int p,altura;
    while( scanf("%d",&p) && p )
    {
        int arr[ p ];
        for( int i = 0 ; i < p ; ++i )
        {
            scanf("%d",&arr[ i ]);
        }
        int otro_arr[ 20 ];
        int letra = 0;
        memset( otro_arr, -1, sizeof otro_arr );
        for( int i = 0 ; i < 20 ; i++ )
        {

            if( otro_arr[ i ] == -1 )
            {
                otro_arr[ i ] = letra;
                letra++;
            }
            else
            {
                if( otro_arr[ i ] == otro_arr[ i-arr[ i%p ] ] )
                    otro_arr[ arr[ i%p ] ] = letra;
            }
            if( otro_arr[ arr[ i%p ] ] != -1 )
                cout << "crash" << endl;
            else
                otro_arr[ arr[ i%p ] ] = letra;
            cout << otro_arr[ i ] << '\t';
        }
    }

    return 0;
}

