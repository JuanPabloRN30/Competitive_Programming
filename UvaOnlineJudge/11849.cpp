#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,val;
    while(cin >> n >> m && (n+m))
    {
        set < int > all;
        for(int i = 0 ; i < n ; i++)
            cin >> val, all.insert(val);
        for(int i = 0 ; i < m ; i++)
            cin >> val, all.insert(val);
        cout << (n+m) - all.size() << '\n';
    }
    return 0;
}
