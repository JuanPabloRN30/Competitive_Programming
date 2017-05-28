#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < int > primes;

void sieve(ll N)
{
  bitset<10000010> bs;
  bs.set();
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
  sieve( 1e6 );
  while( scanf("%d",&n) && n )
  {

    int sup,inf,suma;
    inf = 0;
    sup = lower_bound( primes.begin(), primes.end(), n ) - primes.begin();
    suma = primes[ inf ] + primes[ sup ];
    int cont = 0;
    while( sup >= inf)
    {
      // cout << suma << " " << primes[ inf ] << " " << primes[ sup ] << endl;
      if( suma == n )
      {
        sup--;
        cont++;
      }
      else if( suma > n )
        sup--;
      else
        inf++;
      suma = primes[ inf ] + primes[ sup ];
    }
    printf("%d\n",cont);
  }


  return 0;
}
