#include <bits/stdc++.h>

using namespace std;

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
#define ii pair < int , int >
#define NMAX 1e6
typedef long long ll;

vector < int > primes;

void sieve()
{
  bitset < 10000000 > bs;
  bs.set();
  for(ll i = 2 ; i <= NMAX ; i++)
  {
    if( bs[i] )
    {
      primes.push_back( i );
      for(ll j = i*i ; j <= NMAX ; j+=i)
      {
        bs[j] = false;
      }
    }
  }
}

ll numPF(ll N)
{
  ll PF_idx = 0, PF = primes[ PF_idx ], ans = 0;
  ll acum = 1;
  while(PF * PF <= N)
  {

    while( N%PF == 0)
    {
      N /= PF;
      ans++;
    }
    if( primes[ PF_idx ] != 2 )
      acum = acum * (ans+1);
    PF = primes[ ++PF_idx ];
    ans = 0;
  }
  if( N != 1 )
  {
    ans++;
    if( N%2 != 0 )
      acum = acum * (ans+1);
  }
  return acum;
}

int main()
{
  int n;
  sieve();
  while( scanf("%d",&n)!=EOF)
  {
      printf("%lld\n",(numPF( n ) - 1));
  }

  return 0;
}
