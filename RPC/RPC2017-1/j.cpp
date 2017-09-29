#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

struct Wave
{
    ll time;
    ll fun;
    ll wait_t;

    bool operator< (const ll other_time) const
    {
        return time < other_time;
    }
};

bool cmp(Wave o, Wave d)
{
    return o.time < d.time;
}

Wave waves[1000000];
ll memo[ 1000000 ];
int n;
int cont;

ll dp(int pos)
{
    if(pos == n) return 0LL;
    if(pos == n-1) return memo[pos] = waves[pos].fun;
    if(memo[pos] != -1) return memo[pos];
    int new_pos = lower_bound(waves, waves+n, waves[pos].time+waves[pos].wait_t) - waves;
    return memo[pos] = max(dp(new_pos)+waves[pos].fun, dp(pos+1));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    memset(memo, -1, sizeof memo);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> waves[i].time >> waves[i].fun >> waves[i].wait_t;
    sort(waves, waves+n, cmp);
    cout << dp(0) << '\n';
    return 0;
}
