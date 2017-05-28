#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

vector < ll > primes;
vector < vector < int > > matriz;


const ll mod = 1000000007;

void sieve(ll N)
{
  bitset<1000000000> bs;
  bs.set();
  for( ll i = 2 ; i <= N ; i++ )
  {
    if( bs[ i ] )
    {
      primes.push_back( i );
      for( ll j = i+i ; j <= N ; j+= i )
      {
        primes[ primes.size()-1 ].push_back(  )
        bs[ j ] = false;
      }
    }
  }
}

int main()
{
  int query;
  sieve(1e6);
  while( scanf("%d",&query) != EOF )
  {
    cout << "No me totee " << endl;
  }

  return 0;
}
