#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    while( scanf("%d",&k) && k )
    {
        vector < int > arr(k);
        for( int i = 0 ; i < k ; ++i )
            scanf("%d",&arr[ i ]);
        do
        {
        }while( next_permutation(arr.begin(),arr.end()) );
    }

    return 0;
}
