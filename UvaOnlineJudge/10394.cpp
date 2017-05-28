#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long NMAX = 18409201;
vector < pair < int , int > > twin_primes;

void sieve()
{
  //vector < bool > bs(18409211,true);
  bitset < 18409211 > bs;
  bs.set();
  ll anterior = -1;
  for(ll i = 2 ; i <= NMAX && twin_primes.size() <= 100000 ; i++)
  {
    if( bs[ i ] )
    {
      for(ll j = i*i ; j <= NMAX ; j+= i)
      {
        bs[ j ] = false;
      }
      if( anterior == -1 )
        anterior = i;
      else
      {
        if( abs(anterior-i) == 2 )
          twin_primes.push_back( make_pair(anterior,i) );
        anterior = i;
      }
    }
  }
}




int main()
{
  int numero;
  sieve();
  while( scanf("%d",&numero) != EOF )
  {
    printf("(%d, %d)\n",twin_primes[ numero-1 ].first,twin_primes[ numero-1 ].second);
  }


  return 0;
}
