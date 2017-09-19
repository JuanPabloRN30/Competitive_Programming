#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int s,b,l,r;
    while(cin >> s >> b && (s+b))
    {
        int left[ s + 1 ], right[ s + 1 ];
        for(int i = 0 ; i <= s ; i++)
        {
            left[i] = i-1;
            right[i] = i+1;
        }
        for(int i = 0 ; i < b ; i++)
        {
            cin >> l >> r;
            left[ right[ l ] ]
        }
    }
    return 0;
}
