#include <bits/stdc++.h>

using namespace std;

int busqueda_binaria_techo( int valor_buscado, vector < int > ans , vector < int > cars)
{
  int hi,lo,mid;
  hi = ans.size()-1;
  lo = 0;
  mid = ( hi + lo )/2;
  while( cars[ ans[ mid ] ] != valor_buscado && abs(lo - hi) != 1)
  {
    if( cars[ ans[ mid ] ] > valor_buscado )
      hi = mid;
    else
      lo = mid;
    mid = ( hi + lo )/2;
  }
  return abs(lo-hi) == 1 ? lo+1 : mid;
}

int main()
{
  int n;
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d",&n);
    vector < int > izq,der;
    vector < int > cars(n);
    vector < int > cars_negativo(n);
    int valor;
    for(int i = 0 ; i < n ; i++)
    {
      scanf("%d",&valor);
      cars[ i ] = valor;
      cars_negativo[ i ] = valor*-1;
    }
    if( !cars.empty() )
    {
      izq.push_back( 0 );
      der.push_back( 0 );
    }
    for(int i = 1 ; i < (int)cars.size() ; i++)
    {
      if( cars[i] > cars[ izq[ izq.size()-1 ] ]  )
        izq.push_back( i );
      else if( cars[ i ] < cars[ izq[ izq.size()-1 ] ] && cars[ i ] > cars[ izq[ 0 ] ] )
      {
        int position = busqueda_binaria_techo( cars[ i ], izq, cars );
        izq[ position ] = i;
      }
      else if( cars[ i ] < cars[ izq[ 0 ] ] )
      {
        izq[ 0 ] = i;
      }

      if( cars_negativo[i] > cars_negativo[ der[ der.size()-1 ] ]  )
        der.push_back( i );
      else if( cars_negativo[ i ] < cars_negativo[ der[ der.size()-1 ] ] && cars_negativo[ i ] > cars_negativo[ der[ 0 ] ] )
      {
        int position = busqueda_binaria_techo( cars_negativo[ i ], der, cars_negativo );
        der[ position ] = i;
      }
      else if( cars_negativo[ i ] < cars_negativo[ der[ 0 ] ] )
      {
        der[ 0 ] = i;
      }
    }
    printf("%d %d\n",(int)izq.size(),(int)der.size());
  }
  return 0;
}
