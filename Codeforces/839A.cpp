#include <iostream>

using namespace std;

int main()
{
    int n,k,cant, ans = -1;
    bool flag = false;
    int acum = 0, total = 0;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> cant;
        acum += cant;
        if(acum >= 8)
        {
            total += 8;
            acum -= 8;
        }
        else
        {
            total += acum;
            acum = 0;
        }
        if(total >= k && !flag)
        {
            ans = i+1;
            flag = true;
        }
    }
    cout << ans << '\n';
    return 0;
}
