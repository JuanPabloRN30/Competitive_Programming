#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < int > primes;
long long result[ 32 ];
bitset<1000> bs;
void sieve(ll N)
{

  bs.set();
  bs[ 0 ] = bs[ 1 ] = false;
  for( ll i = 2 ; i <= N ; i++ )
  {
    if( bs[ i ] )
    {
      primes.push_back( i );
      result[ i ] = (1LL<<(i-1LL))*((1LL<<i)-1LL);
      for( ll j = i*i ; j <= N ; j+= i )
        bs[j] = false;
    }
  }
}



int main()
{
  int n;
  sieve( 100 );
  while( scanf("%d",&n) != EOF )
  {
    if( n < 1 )
      break;
    if( bs[ n ] )
      printf("Perfect: %lld!\n",result[ n ]);
    else
      printf("Given number is NOT prime! NO perfect number is available.\n");
  }


  return 0;
}
