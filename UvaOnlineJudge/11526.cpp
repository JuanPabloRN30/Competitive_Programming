#include <bits/stdc++.h>

using namespace std;

long long H(int n)
{
    long long res = 0;
    for( int i = 1; i <= n ; ++i )
    {
        res = (res + n/i);
    }
    return res;
}

long long HRes(int n)
{
    long long res = 0;
    int lim = n/2;
    for( int i = 1; i <= lim ; ++i )
    {
        res = (res + n/i);
    }
    return res + ( n - lim );
}

int main()
{
    int cases,n;
    scanf("%d",&cases);
    while( cases-- )
    {
        scanf("%d",&n);
        int dif = 0;
        for( int i = 1 ; i<= n ; i++ )
        {
            //cout << i << " " << H(i) << " "<< HRes(i)<<endl;
            dif = dif - H(i);
            cout << i << " " << H(i) << " "<<abs(dif) << endl;
            dif = H(i);
        }

    }
    return 0;
}
