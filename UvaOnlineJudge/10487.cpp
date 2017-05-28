#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,q,diferencia,cases = 1,menor;
    int arr[ 1010 ];
    while( scanf("%d",&n) && n )
    {
        for( int i = 0 ; i < n ; ++i )
            scanf("%d",&arr[i]);
        scanf("%d",&m);
        printf("Case %d:\n",cases);
        cases++;
        for( int i = 0 ; i < m ; ++i )
        {
            scanf("%d",&q);
            diferencia = 1e9;
            for( int i = 0 ; i < n ; ++i )
            {
                for( int j = i+1 ; j < n ; ++j )
                {
                    if( abs(q-(arr[ i ] + arr[ j ])) < diferencia )
                    {
                        diferencia = abs(q - (arr[ i ] + arr[ j ]));
                        menor = arr[ i ]+ arr[ j ];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n",q,menor);

        }
    }
    return 0;
}
