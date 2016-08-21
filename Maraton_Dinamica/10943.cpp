#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector < ll > fact;
const ll M = 1e9+7;


void precalc_fact( int NUM_MAX )
{
  fact.assign(NUM_MAX+10, 0);
  fact [ 0 ] = fact[ 1 ] = 1;
  for(ll i = 2 ; i <= NUM_MAX ; i++)
  {
    fact[ i ] = (fact[ i-1 ]%M * i%M)%M;
  }
}

ull fastPow( ull base , ull exponente )
{
  ull res = base;
  ull i = 0;
  ull llevo = 1;
  while( ( 1LL << i ) <= exponente )
  {
    if( ( exponente & ( 1LL << i ) ) != 0 )
      llevo = ( llevo * res ) % M;
    res = res * res % M;
    ++i;
  }
  return llevo;
}

ull formula( int n, int r)
{
  r--;
  n++;
  ull num = fact[n+r-1];
  ull den = ( fact[r] * fact[n-1] ) % M;
  return ( ( num * fastPow( den , M - 2 )) % M ) ;
}

int main()
{
  int n,k;
  precalc_fact( 200 );
  while( scanf("%d%d",&n,&k) && (n+k) )
  {
    printf("%lld\n",formula(n,k) );
  }
  return 0;
}
