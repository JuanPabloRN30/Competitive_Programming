#include <iostream>

using namespace std;

int main()
{
    string x,y;
    cin >> x >> y;
    string ans = "";
    bool can = true;
    for( int i = 0 ; i < (int)x.size() ; i++ )
    {
        if( x[ i ] < y[ i ] ) can = false;
        else ans = ans + y[ i ];
    }
    if( can )
        cout << ans << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
