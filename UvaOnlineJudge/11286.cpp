#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while( scanf("%d",&n) && n)
    {
        map < int , int > frequency;
        int value;
        for( int i = 0 ; i < n ; ++i )
        {
            for( int j = 0 ; j < 5 ; ++j )
            {
                scanf("%d",&value);
                frequency[ value ]++;
            }
        }
        int may = 0;
        map < int , int >::iterator it;
        for( it = frequency.begin() ; it != frequency.end() ; ++it )
        {
            cout << it->first << " " << it->second << endl;
        }
        //printf("%d\n",may == 1 ? n : may);
    }
    return 0;
}
