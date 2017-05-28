#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

vector < ll > primes;
vector < pair < int , ll > > primorial;
bitset<10000000> bs;

const ll mod = 1e10;

void sieve(ll N)
{
  bs.set();
  for( ll i = 2 ; i <= N ; i++ )
  {
    if( bs[ i ] )
    {
      primes.push_back( i );
      if( primes.size() > 1 )
        primorial.push_back( make_pair(i, (i%mod * primorial[ primorial.size()-1 ].second%mod)%mod ) );
      else
        primorial.push_back( make_pair( i, i ) );
      for( ll j = i*i ; j <= N ; j+= i )
        bs[ j ] = false;
    }
  }
}

bool cmp(const pair < int , int > &p1, const pair < int , int > &p2)
{
  return p1.first < p2.first;
}

int main()
{
  int cases,query;
  sieve(1e6);
  scanf("%d",&cases);
  while( cases-- )
  {
    scanf("%d",&query);

    int position = lower_bound(primorial.begin(),primorial.end(),make_pair(query,-1),cmp) - primorial.begin();
    if( bs[ query ] )
    {
      if( query >= 29)
        printf("%010lld\n",primorial[ position ].second);
      else
        printf("%lld\n",primorial[ position ].second);
    }
    else
    {
      if( query >= 29)
        printf("%010lld\n",primorial[ position - 1 ].second);
      else
        printf("%lld\n",primorial[ position - 1 ].second);
    }
  }
  return 0;
}
