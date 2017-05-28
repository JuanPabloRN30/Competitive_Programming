#include<bits/stdc++.h>

using namespace std;

vector < int > ans,a;

int busqueda_binaria_techo( int valor_buscado )
{
  int hi,lo,mid;
  hi = ans.size()-1;
  lo = 0;
  mid = ( hi + lo )/2;
  while( a[ ans[ mid ] ] != valor_buscado && abs(lo - hi) != 1)
  {
    if( a[ ans[ mid ] ] > valor_buscado )
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
  while( scanf("%d",&n) != EOF )
  {
    a.push_back(n);
  }
  int parents[ a.size() ];
  memset( parents, -1, sizeof(parents) );
  if( !a.empty() )
    ans.push_back( 0 );
  for(int i = 1 ; i < (int)a.size() ; i++)
  {
    if( a[i] > a[ ans[ ans.size()-1 ] ]  )
    {
      parents[ i ] = ans[ ans.size()-1 ];
      ans.push_back( i );
    }
    else if( a[ i ] < a[ ans[ ans.size()-1 ] ] && a[ i ] > a[ ans[ 0 ] ] )
    {
      int position = busqueda_binaria_techo( a[ i ] );
      ans[ position ] = i;
      parents[ i ] = ans[ position-1 ];
    }
    else if( a[ i ] < a[ ans[ 0 ] ] )
    {
      ans[ 0 ] = i;
    }
  }
  printf("%d\n-\n",(int)ans.size());
  stack < int > impresion;
  int current_value = ans[ ans.size()-1 ];
  while( parents[ current_value ]  != -1)
  {
    impresion.push( current_value );
    current_value = parents[ current_value ];
  }
  impresion.push( current_value );

  while(!impresion.empty() )
  {
    printf("%d\n",a[ impresion.top() ] );
    impresion.pop();
  }
  return 0;
}
