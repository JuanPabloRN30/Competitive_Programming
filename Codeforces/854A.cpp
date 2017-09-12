#include <iostream>
#include <algorithm>

using namespace std;

typedef pair < int , int > ii;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    ii ans;
    cin >> n;
    for(int i = 0 ; i < (n >> 1)+1 ; i++)
    {
        if(__gcd(i, n - i) == 1 && i < (n-1))
            ans = ii(i, n-i);
    }
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}
