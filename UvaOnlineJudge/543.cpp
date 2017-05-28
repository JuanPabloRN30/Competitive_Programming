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
    inf = 1;
    sup = lower_bound( primes.begin(), primes.end(), n ) - primes.begin();
    suma = primes[ inf ] + primes[ sup ];
    while( sup > inf && suma != n )
    {
      if( suma > n )
        sup--;
      else
        inf++;
      suma = primes[ inf ] + primes[ sup ];
    }
    if( suma == n )
      printf("%d = %d + %d\n",n,primes[ inf ],primes[ sup ]);
    else
      printf("Goldbach's conjecture is wrong.\n");
  }


  return 0;
}
