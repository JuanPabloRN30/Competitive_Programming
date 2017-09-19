#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, cases = 1, mayor, k, num;
    cin >> n;
    while(n--)
    {
        mayor = 0;
        cin >> k;
        while(k--)
        {
            cin >> num;
            mayor = max(num, mayor);
        }
        cout << "Case " << cases++ << ": " << mayor << '\n';
    }
    return 0;
}
