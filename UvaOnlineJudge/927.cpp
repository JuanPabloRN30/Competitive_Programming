#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull potencia( ull base, ull expo )
{
    ull pot = 1;
    for( int i = 0 ; i< expo ; ++i )
        pot *= base;
    return pot;
}

int main()
{
    int c,d,k,coeficient,n;
    string linea;
    cin >> c;
    while( c-- )
    {
        int cont = 0;
        cin >> n;
        ull coeficient[ n + 1 ];
        for( int i = 0 ; i <= n ; ++i )
        {
            cin >> coeficient[ i ];
        }
        cin >> d >> k;
        ull acum = 0;
        ull ans;
        while( acum < k )
        {
            ans = 0;
            for( int i = 0 ; i <= n ; ++i )
            {
                ans += coeficient[ i ] * potencia( cont, i );
            }
            acum += (cont * d );
            cont++;
        }
        cout << ans << endl;

    }

    return 0;
}
