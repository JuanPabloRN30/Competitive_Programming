#include <bits/stdc++.h>

using namespace std;

int f(int n)
{
    int c = 1;
    while(n != 1)
    {
        if(n & 1) n = 3 * n + 1;
        else n >>= 1;
        c++;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int lo, hi, maximo, lo_s, hi_s;
    while(cin >> lo >> hi)
    {
        lo_s = lo;
        hi_s = hi;
        if(lo > hi) swap(lo,hi);
        maximo = 0;
        for(int i = lo ; i <= hi ; i++)
            maximo = max(maximo, f(i));
        cout << lo_s << " " << hi_s << " "<<maximo << '\n';
    }
    return 0;
}
