#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int arr[1000];
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    bool flag = false;
    if(n&1)
    {
        if(!(arr[0] & 1) || !(arr[n-1]&1)) flag = 1;
    }
    else
        flag = 1;
    if(!flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
