#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    bool doors[ 10000 ];
    while( scanf("%d",&n) && n )
    {
        memset( doors, 0, sizeof doors );
        for( long long i = 1 ; i*i <= n ; i++ )
        {
            if( i != 1 )
                cout << " ";
            cout << i*i;
        }
        cout << endl;
    }


    return 0;
}
