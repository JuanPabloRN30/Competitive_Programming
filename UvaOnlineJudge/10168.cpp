#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < int > primes;
bitset<10000010> bs;
void sieve(ll N)
{

  bs.set();
  bs[ 0 ] = bs[ 1 ] = false;
  for( ll i = 2 ; i <= N ; i++ )
  {
    if( bs[ i ] )
    {
      primes.push_back( i );
      for( ll j = i*i ; j <= N ; j+= i )
        bs[j] = false;
    }
  }
}



int main()
{
  int n;
  sieve( 1e7 );
  while( scanf("%d",&n) != EOF )
  {
    bool band = false;
    for(int a = 0 ; a < (int)primes.size() && !band && primes[ a ] < n  ; a++)
    {
      for( int b = a ; b < (int)primes.size() && !band && primes[ b ] < n  ; b++ )
      {
        for( int c = b ; c < (int)primes.size() && !band && primes[ c ] < n  ; c++ )
        {
            int total = n-primes[ a ] - primes[ b ] - primes[ c ];
            if( total >= 0  && bs[ total ])
            {
              printf("%d %d %d %d\n",primes[ a ],primes[ b ],primes[ c ],total);
              band = true;
            }
        }
      }
    }
    if( !band )
      printf("Impossible.\n");
  }


  return 0;
}
