#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,t;
    cin >> n >> k >> t;
    ll ans = 0;
    if(t < k) ans += t;
    if(t >= k) ans += k;
    if(t >= n + 1) ans -= ( t-n );
    cout << ans << '\n';
    return 0;
}
