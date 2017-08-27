#include <iostream>

using namespace std;

typedef long long ll;

int dp[20][200][200];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q,c,x,y,s;
    int t,x1,y1,x2,y2;
    cin >> n >> q >> c;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> y >> s;
        dp[s][x][y]++;
    }
    for(int i = 0 ; i <= c ; i++)
        for(int j = 1 ; j <= 100 ; j++)
            dp[i][0][j] += dp[i][0][j-1];
    for(int i = 0 ; i <= c ; i++)
        for(int j = 1 ; j <= 100 ; j++)
            dp[i][j][0] += dp[i][j-1][0];
    for(int i = 0 ; i <= c ; i++)
        for(int j = 1 ; j <= 100 ; j++)
            for(int k = 1 ; k<= 100 ; k++)
                dp[i][j][k] += dp[i][j][k-1] - dp[i][j-1][k-1] + dp[i][j-1][k];
    while(q--)
    {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int acum = 0;
        int ans;
        for(int i = 0 ; i <= 10 ; i++)
        {
            ans = dp[i][x2][y2];
            if(x1-1 >= 0)
                ans -= dp[i][x1-1][y2];
            if(y1-1 >= 0)
                ans -= dp[i][x2][y1-1];
            if(x1-1 >= 0 && y1-1 >= 0)
                ans += dp[i][x1-1][y1-1];
            acum += ((i + t)%(c+1))* ans;

        }
        cout << acum << '\n';
    }
    return 0;
}
