#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases,n,cont,value;
    cont = 1;
    scanf("%d",&cases);
    while( cases-- )
    {
        scanf("%d",&n);
        map < int , int > mapa;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                scanf("%d",&value);
                mapa[ value ]++;
            }
        }
        map < int , int >::iterator it;
        bool stable = true;
        for( it = mapa.begin() ; it != mapa.end() ; ++it )
        {
            if( it->second > n )
                stable = false;
        }
        if( stable )
            printf("Case %d: yes\n",cont);
        else
            printf("Case %d: no\n",cont);
        ++cont;
    }
    return 0;
}
