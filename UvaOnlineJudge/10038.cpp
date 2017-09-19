#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int arr[ 3010 ];
    while(cin >> n)
    {
        bitset < 3010 > bs;
        for(int i = 0 ; i < n ; i++)
            cin >> arr[i];
        for(int i = 1 ; i < n ; i++)
            bs[ abs(arr[i]-arr[i-1]) ] = 1;
        bool flag = true;
        for(int i = 1 ; i < n ; i++)
            if(!bs[i]) flag = false;
        if(flag) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
