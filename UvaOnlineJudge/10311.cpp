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
    int second;
    second = lower_bound( primes.begin(), primes.end(), n ) - primes.begin();
    int diferencia = 1e9;
    pair < int , int > res;
    for( int i = 0 ; i <= second ; i++ )
    {
      long long resultado = n-primes[ i ];
      if( resultado != primes[ i ] && resultado > 0 && resultado < 10000010 && bs[ resultado ] )
      {
        if( resultado - primes[ i ] >= 0 && resultado - primes[ i ] < diferencia )
        {
          diferencia = resultado - primes[ i ];
          res.first = primes[ i ];
          res.second = resultado;
        }
      }
    }
    if( diferencia == 1e9 )
      printf("%d is not the sum of two primes!\n",n);
    else
      printf("%d is the sum of %d and %d.\n",n,res.first,res.second);
  }


  return 0;
}
