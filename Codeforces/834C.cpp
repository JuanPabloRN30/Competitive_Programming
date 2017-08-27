#include <iostream>

using namespace std;

typedef long long ll;

ll binary(ll a, ll b)
{
    ll lo = 0,mid;
    ll hi = 1e6;
    while( lo <= hi)
    {
        mid = (lo + hi) >> 1LL;
        if(mid * mid * mid == a * b) return mid;
        if( mid * mid * mid > a*b)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll a,b;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        ll cubic = binary(a,b);
        if( cubic != -1 && a%cubic == 0 && b % cubic == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
