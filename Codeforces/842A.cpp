#include <iostream>

using namespace std;

typedef long long ll;

bool solution(int lo, int hi, int k, int b)
{
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if(mid % b == 0 && mid / b == k) return true;
        if( (mid/b) < k ) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main()
{
    ll l,r,x,y,k;
    cin >> l >> r >> x >> y >> k;
    bool solve = false;
    for(int i = x ; i<= y ; i++)
    {
        solve = solution(l, r, k, i);
        if(solve) break;
    }
    if(solve)
        puts("YES");
    else
        puts("NO");
    return 0;
}
