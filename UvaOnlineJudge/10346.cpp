#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    while( scanf("%d%d",&n,&k) != EOF )
    {
        double nD = n;
        double kD = k;
        double acum = 0.0;
        acum += n;
        while( nD > 1e-3 )
        {
            acum += nD / kD;
            nD /= kD;
        }
        cout << (int)acum << endl;
    }

}
