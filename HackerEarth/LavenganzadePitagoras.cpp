#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

int divisores( ll n )
{
    ll lim = sqrt( n );
    set < int > divis;
    for( int i = 1 ; i <= lim ; i++ )
    {
        if( n%i == 0 )
        {
            divis.insert(i);
            divis.insert(n/i);
        }
    }
    return divis.size();
}

bitset<10000000> bs;
vector < int > primes;

void sieve()
{
    bs.set();
    for( ll i = 2 ; i<= 1e7 ; i++ )
    {
        if( bs[ i ] )
        {
            primes.push_back( i );
            for( ll j = i * i ; j <= 1e7 ; j+= i )
                bs[ i ] = false;
        }
    }
}

ll numDiv(ll N)
{
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
    while (PF * PF <= N)
    {
        ll power = 0; // count the power
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1); // according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
    return ans;
}
bool formula( ll a, ll b )
{
    ll hipo = a*a + b*b;
  //  cout << hipo << " " << divisores( hipo ) << endl;
  //cout << numDiv( hipo ) << endl;
    if( numDiv( hipo ) & 1 )
        return true;
    else
        return false;
}

int main()
{
    ll a;
    sieve();
    while( scanf("%lld",&a) && a )
    {
        int cont = 0;
        for( ll i = a + 1 ; i <= a*2 ; i++ )
        {
            if( formula( a,i ) )
            {
                cout << a << " " << i << endl;
                cont++;
            }
        }
        printf("%d\n",cont);

    }

    return 0;
}

