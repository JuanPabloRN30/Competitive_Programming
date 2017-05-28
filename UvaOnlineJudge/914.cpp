#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < int > primes;

void sieve( ll N )
{
  bitset<10000010 > bs;
  bs.set();
  for( ll i = 2 ; i<= N ; i++ )
  {
    if( bs[ i ] )
    {
      primes.push_back( i );
      for( ll j = i*i ; j <= N ; j+=i )
        bs[ j ] = false;
    }
  }
}

int main()
{
  int casos;
  sieve( 1e6 );
  scanf("%d",&casos);
  while( casos-- )
  {
    int inf,sup;
    scanf("%d%d",&inf,&sup);
    int lim_inf;
    lim_inf = lower_bound( primes.begin(), primes.end(), inf ) - primes.begin();
    int mayor = 0;
    int verdadero_mayor;
    map < int , int > mapa;
    for(int i = lim_inf ; primes[ i+1 ] <= sup && i+1 < primes.size() ; i++)
    {
      int valor = mapa[ primes[ i+1 ] - primes[ i ] ]++;
      if( valor+1 > mayor)
      {
        mayor = valor+1;
        verdadero_mayor = primes[ i+1 ] - primes[ i ];
      }
    }
    int cont = 0;
    map < int , int>::iterator it;
    for(it = mapa.begin() ; it != mapa.end() ; it++)
    {

      if( it->second == mayor)
      {
        cont++;
      }
    }
    if( cont != 1 )
      printf("No jumping champion\n");
    else
      printf("The jumping champion is %d\n",verdadero_mayor);
  }

    return 0;
}
