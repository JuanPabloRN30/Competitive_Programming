#include <iostream>

using namespace std;

int main()
{
    int n,m,x,y,val,ans;
    int acum = 0;
    bool flag = false;
    cin >> n;
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> val;
        acum += val;
    }
    cin >> m;
    for( int i = 0 ; i < m ; i++ )
    {
        cin >> x >> y;
        if( acum >= x && acum <= y && !flag ){
                flag =  true;
                ans = acum;
        }
        if( acum < x && !flag )
        {
            ans = x;
            flag = true;
        }
    }
    if( flag ) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}
