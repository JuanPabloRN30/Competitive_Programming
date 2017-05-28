#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < int > primes;

void sieve(ll N)
{
  bitset<10000010> bs;
  bs.set();
  primes.push_back(1);
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
  int n,c;
  while( scanf("%d%d",&n,&c) != EOF )
  {
    primes.clear();
    sieve( n );
    int sz = primes.size();
    int valor = 2*c;
    if( sz&1 )
      valor--;
    int formulita = sz/2 - valor/2;
    printf("%d %d:",n,c);
    if( valor >= primes.size() )
    {
      formulita = 0;
      valor = primes.size();
    }
    for(int inicio = formulita ; inicio < formulita+valor && inicio < primes.size() ; inicio++ )
    {
      printf(" %d",primes[ inicio ]);
    }
    printf("\n");
    printf("\n");
  }


  return 0;
}
