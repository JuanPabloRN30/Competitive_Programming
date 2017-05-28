#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,c,d;
    scanf("%d",&n);
    while( n-- )
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        long long ratioo = (long double)((fabs( b - d ) / abs( a - c )) * 100.0);
        cout << (long long)ratioo/100;
        cout << ",";
        printf("%0.2lld\n",ratioo%100);
    }
    return 0;
}

