#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main()
{
    int n,k,bill;
    long long tot;
    while( scanf("%d",&n) && n )
    {
        multiset < int > bills;
        tot = 0;
        while( n-- )
        {
            scanf("%d",&k);
            for( int i = 0 ; i < k ; ++i )
            {
                scanf("%d",&bill);
                bills.insert( bill );
            }
            tot += *(--bills.end()) - *bills.begin();
            bills.erase( --bills.end() );
            bills.erase( bills.begin() );
        }
        printf("%lld\n",tot);

    }

    return 0;
}
