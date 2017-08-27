#include <iostream>

using namespace std;

int main()
{
    int n;
    int may,tot;
    may = tot = 0;
    scanf("%d",&n);
    int arr[ n ];
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[ i ]);
        may = max( may, arr[ i ] );
    }
    for( int i = 0 ; i < n ; i++ )
        tot += (may - arr[ i ]);
    printf("%d\n",tot);
    return 0;
}
