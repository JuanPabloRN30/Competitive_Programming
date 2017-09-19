#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, cases = 1;
    int arr[3];
    cin >> n;
    while(n--)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        cout << "Case " << cases++ << ": " << arr[1] << '\n';
    }
    return 0;
}
